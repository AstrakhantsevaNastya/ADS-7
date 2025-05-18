// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : operationCount(0), firstCar(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    
    if (!firstCar) {
        firstCar = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* lastCar = firstCar->prev;
        newCar->next = firstCar;
        newCar->prev = lastCar;
        lastCar->next = newCar;
        firstCar->prev = newCar;
    }
}

int Train::getLength() {
    if (!firstCar) return 0;

    operationCount = 0;
    Car* current = firstCar;

    if (!current->light) {
        current->light = true;
    }

    while (true) {
        int stepsForward = 0;
        Car* forwardCar = current;

        do {
            forwardCar = forwardCar->next;
            stepsForward++;
            operationCount++;
        } while (!forwardCar->light);

        forwardCar->light = false;

        Car* backwardCar = forwardCar;
        for (int i = 0; i < stepsForward; ++i) {
            backwardCar = backwardCar->prev;
            operationCount++;
        }

        if (backwardCar == current && !backwardCar->light) {
            return stepsForward;
        }
    }
}

int Train::getOpCount() const {
    return operationCount;
}
