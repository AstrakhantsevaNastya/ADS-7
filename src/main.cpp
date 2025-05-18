// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
  Train train;
  const int wagonCount = 60; // кол-во вагонов

  for (int i = 0; i < wagonCount; ++i) {
        train.addCar(false);
  }

  std::cout << "Train length: " << train.getLength() << std::endl;
  std::cout << "Operations count: " << train.getOpCount() << std::endl;
  return 0;
}
