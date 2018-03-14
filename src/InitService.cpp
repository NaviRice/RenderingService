//
// Created by Yang Liu on 2/8/18.
//

#include "InitService.h"
#include "RenderingService.hpp"
#include <thread>

NaviRice::Networking::Services::RenderingService *renderingService;

extern "C" void init_rendering_service(char *ip_address, int port) {
    std::thread serviceThread([ip_address, port] {
        renderingService = new NaviRice::Networking::Services::RenderingService(ip_address, port, "1");
        renderingService->start();
    });
    serviceThread.detach();
}

extern "C" void set_new_step_callback(void (*new_step_callback)(Step)) {
    if (renderingService != nullptr) {
        renderingService->onReceiveNewStep([new_step_callback](Step step) {
            new_step_callback(step);
        });
    }
}