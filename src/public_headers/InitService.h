//
// Created by Yang Liu on 3/12/18.
//

#ifndef NAVIRICE_INITSERVICE_H
#define NAVIRICE_INITSERVICE_H

#include "Step.h"

int init_rendering_service(char *ip_address, int port, void (*new_step_callback)(Step));

#endif //NAVIRICE_INITSERVICE_H
