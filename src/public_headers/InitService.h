//
// Created by Yang Liu on 3/12/18.
//

#ifndef NAVIRICE_INITSERVICE_H
#define NAVIRICE_INITSERVICE_H

#include "Step.h"

void init_rendering_service(char *ip_address, int port, void (*on_service_started)());
void set_new_step_callback(void (*new_step_callback)(Step));

#endif //NAVIRICE_INITSERVICE_H
