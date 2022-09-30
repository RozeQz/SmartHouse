#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <Arduino.h>

class Data {
  public:
    int _brightness;
    float _temperature;
    int _humidity;
  public:
    char* getJSON();
};

#endif
