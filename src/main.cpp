//
// Created by Yang Liu on 2/8/18.
//

#include "RenderingService.hpp"

int main(int argc, char* argv[]) {

    if(argc != 3) {
        std::cout << "Usage: renderingService [ip address] [port]" << std::endl;
        return 1;
    }

    std::string ipAddress = argv[1];
    int port = std::stoi(argv[2]);

    NaviRice::Networking::Services::RenderingService renderingService(ipAddress, port, "1");
    renderingService.start();
}