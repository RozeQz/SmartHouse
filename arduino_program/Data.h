#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <Arduino.h>

class Data {
  private:
    int _brightness;
    float _temperature;
    int _humidity;
    int _error;
  public:
    char* getJSON();
    void setBrightness(int b) { _brightness = b; }
    void setTemperature(float t) { _temperature = t; }
    void setHumidity(int h) { _humidity = h; }
    void setError(int e) { _error = e; }
};

#endif
