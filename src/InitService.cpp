//
// Created by Yang Liu on 2/8/18.
//

#include "InitService.h"
#include "RenderingService.hpp"
#include <thread>

extern "C" int init_rendering_service(char *ip_address, int port, void (*new_step_callback)(Step)) {
    std::thread serviceThread([ip_address, port, new_step_callback]{
        NaviRice::Networking::Services::RenderingService renderingService(ip_address, port, "1");
        renderingService.onReceiveNewStep([new_step_callback](Step step){
            new_step_callback(step);
        });
        renderingService.start();
    });
    serviceThread.detach();
    return true;
}