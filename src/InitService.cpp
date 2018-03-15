//
// Created by Yang Liu on 2/8/18.
//

#include "InitService.h"
#include "RenderingService.hpp"
#include <thread>

NaviRice::Networking::Services::RenderingService *renderingService;

extern "C" void init_rendering_service(char *ip_address, int port, void (*on_service_started)()) {
    std::thread serviceThread([ip_address, port, on_service_started] {
        renderingService = new NaviRice::Networking::Services::RenderingService(ip_address, port, "1");
        renderingService->onServiceStarted([on_service_started](){
            std::cout<< "onServiceStarted" << std::endl;
            on_service_started();
        });
        renderingService->start();
    });
    serviceThread.detach();
}

extern "C" void set_new_step_callback(void (*new_step_callback)(Step)) {
    if (renderingService != nullptr) {
        std::cout<< "set_new_step_callback" << std::endl;
        renderingService->onReceiveNewStep([new_step_callback](Step step) {
            new_step_callback(step);
        });
    }
}