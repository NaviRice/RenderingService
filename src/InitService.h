//
// Created by Yang Liu on 3/11/18.
//

#ifndef INIT_SERVICE_H
#define INIT_SERVICE_H

#include "public_headers/Step.h"

extern "C" void init_rendering_service(char *ip_address, int port, void (*on_service_started)());
extern "C" void set_new_step_callback(void (*new_step_callback)(Step));

#endif //INIT_SERVICE_H
