//
// Created by Yang Liu on 11/16/17.
//

#include <iostream>
#include <build/src/proto/response.pb.h>
#include <nlohmann/json.hpp>
#include "RenderingService.hpp"

NaviRice::Networking::Services::RenderingService::RenderingService(std::string ipAddress, int port, std::string name)
        : Service(ipAddress, port, name, navirice::proto::Service::RENDERING) {
};

void NaviRice::Networking::Services::RenderingService::setupRoutes() {
    addRoute(navirice::proto::Request_Command_UPDATE, "/steps/current",
             [this](std::map<std::string, std::string> params,
                std::map<std::string, std::string> options,
                const char *body,
                std::function<void(navirice::proto::Response)> respond) {
                 auto json = nlohmann::json::parse(body);

                 auto x = json["x"].get<double>();
                 auto y = json["y"].get<double>();
                 std::string description = json["description"].get<std::string>();
                 std::string icon = json["icon"].get<std::string>();

                 Step step = {};
                 step.x = x;
                 step.y = y;
                 step.description = description.c_str();
                 step.icon = icon.c_str();

                 this->onReceiveNewStepCallback(step);

                 navirice::proto::Response response;
                 response.set_status(navirice::proto::Response_Status_SUCCESS);
                 respond(response);

             });
}

void NaviRice::Networking::Services::RenderingService::onReceiveNewStep(
        std::function<void(Step)> onReceiveNewStepCallback) {
    this->onReceiveNewStepCallback = onReceiveNewStepCallback;
}