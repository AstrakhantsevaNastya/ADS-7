// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Car {
    bool light; // состояние лампочки
    Car* next; // следующий вагон
    Car* prev; // предыдущий вагон
  };
  int operationCount; // счетчик операций
  Car* firstCar; // первый вагон поезда

 public:
  Train();
  void addCar(bool light); // добавить вагон
  int getLength(); // вычислить длину поезда
  int getOpCount() const;  // вернуть число операций
};

#endif  // INCLUDE_TRAIN_H_
