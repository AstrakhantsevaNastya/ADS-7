// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : operationCount(0), firstCar(nullptr) {}

int Train::getOpCount() const {
    return operationCount;
}

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
        operationCount++;
    }

    while (true) {
        int stepsForward = 0;
        do {
            current = current->next;
            stepsForward++;
            operationCount++;
        } while (!current->light && current != firstCar);

        if (current->light) {
            current->light = false;
            operationCount++;

            for (int i = 0; i < stepsForward; i++) {
                current = current->prev;
                operationCount++;
            }

            if (current == firstCar && !current->light) {
                return stepsForward;
            }
        } else {
            return stepsForward;
        }
    }
}
