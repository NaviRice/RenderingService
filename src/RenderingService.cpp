//
// Created by Yang Liu on 11/16/17.
//

#include <iostream>
#include <build/src/proto/response.pb.h>
#include "RenderingService.hpp"

NaviRice::Networking::Services::RenderingService::RenderingService(std::string ipAddress, int port, std::string name)
        : Service(ipAddress, port, name, navirice::proto::Service::RENDERING) {
};

void NaviRice::Networking::Services::RenderingService::setupRoutes() {
    addRoute(navirice::proto::Request_Command_UPDATE, "/steps/current",
             [](std::map<std::string, std::string> params,
                std::map<std::string, std::string> options,
                const char *body,
                std::function<void(navirice::proto::Response)> respond) {

                 std::cout << body << std::endl;

                 navirice::proto::Response response;
                 response.set_status(navirice::proto::Response_Status_SUCCESS);
                 respond(response);

             });
}