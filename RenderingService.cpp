//
// Created by Yang Liu on 11/16/17.
//

#include <netinet/in.h>
#include <iostream>
#include "RenderingService.hpp"

NaviRice::Networking::RenderingService::RenderingService(std::string ipAddress, int port) :
        Service("RenderingService", ipAddress, port) {

}

void NaviRice::Networking::RenderingService::onWaitingForConnection() {
    std::cout << this->name << " onWaitingForConnection" << std::endl;
};

void NaviRice::Networking::RenderingService::onAcceptConnection(sockaddr_in clientAddress) {
    std::cout << this->name << " onAcceptConnection" << std::endl;
};

void NaviRice::Networking::RenderingService::onReceiveData(Buffer) {
    std::cout << this->name << " onReceiveData" << std::endl;
};

//void start_service(const char *ipAddress, int port, void (*on_head_location_update)(struct Location),
//                   void (*on_road_info_update)(struct Location), void (*on_connection)(struct RoadInfo),
//                   void (*on_error)(), void (*on_disconnect)()) {
//    NaviRice::Networking::Service *service = new NaviRice::Networking::RenderingService("127.0.0.1", 8080);
//    service->start();
//}

int main(int argc, char *argv[]) {
    NaviRice::Networking::Service *service = new NaviRice::Networking::RenderingService("127.0.0.1", 8080);
    service->start();
}
