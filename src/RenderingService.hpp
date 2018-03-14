//
// Created by Yang Liu on 11/16/17.
//

#ifndef RENDERING_SERVICE_H
#define RENDERING_SERVICE_H

#include <src/Service.hpp>
#include "public_headers/Step.h"
#include "string"

namespace NaviRice {
    namespace Networking {
        namespace Services {
            class RenderingService : public Service {
                std::function<void(Step)> onReceiveNewStepCallback;
            public:
                std::mutex receiveNewStepMutex;
                RenderingService(std::string ipAddress,
                                 int port,
                                 std::string name);
                void setupRoutes() override;
                void onReceiveNewStep(std::function<void(Step)>);
            };
        }
    }
}

#ifdef __cplusplus
extern "C" {
void start_service(const char *ipAddress, int port, void (*on_head_location_update)(struct Location),
                   void (*on_road_info_update)(struct Location), void (*on_connection)(struct RoadInfo),
                   void (*on_error)(), void (*on_disconnect)());
};
#endif

#endif //RENDERING_SERVICE_H
