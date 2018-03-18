//
// Created by Yang Liu on 3/12/18.
//

#ifndef NAVIRICE_STEP_H
#define NAVIRICE_STEP_H

typedef struct Step {
    double longitude;
    double latitude;
    const char *description;
    const char *icon;
} Step;

#endif //NAVIRICE_STEP_H
