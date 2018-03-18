//
// Created by Yang Liu on 11/16/17.
//

#include <iostream>
#include <src/proto/response.pb.h>
#include <src/proto/step.pb.h>
#include "RenderingService.hpp"

NaviRice::Networking::Services::RenderingService::RenderingService(std::string ipAddress, int port, std::string name)
        : Service(ipAddress, port, name, navirice::proto::Service::RENDERING) {
};

void NaviRice::Networking::Services::RenderingService::setupRoutes() {
    addRoute(navirice::proto::Request_Type_CURRENT_STEP,
             [this](const char *body,
                    unsigned long bodyLength,
                    std::function<void(navirice::proto::Response)> respond) {

                 navirice::proto::Step protoStep;
                 protoStep.ParseFromArray(body, bodyLength);

                 Step step;
                 step.latitude = protoStep.latitude();
                 step.longitude = protoStep.longitude();
                 step.description = protoStep.description().c_str();
                 step.icon = protoStep.icon().c_str();

                 std::lock_guard<std::mutex> guard(receiveNewStepMutex);
                 if(onReceiveNewStepCallback != nullptr)
                    this->onReceiveNewStepCallback(step);

                 navirice::proto::Response response;
                 response.set_status(navirice::proto::Response_Status_SUCCESS);
                 respond(response);

             });
}

void NaviRice::Networking::Services::RenderingService::onReceiveNewStep(
        std::function<void(Step)> onReceiveNewStepCallback) {
    std::lock_guard<std::mutex> guard(this->receiveNewStepMutex);
    this->onReceiveNewStepCallback = onReceiveNewStepCallback;
}