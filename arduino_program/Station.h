#ifndef STATION_H
#define STATION_H

#include <string.h>
#include <stdio.h>
#include <Arduino.h>
#include <TroykaDHT.h>


#define DHT_CONNECTION_WAITTIME 300

class Station {
  private:
    unsigned int _id;
    char _name[16];
    int _photoPin;
    DHT* _dht;
    int getBrightness();
    void getDHTDataJSON(char* buf, int bufSize);
    int getDHTData(float* temp, int* hum);
  public:
    Station(unsigned int id, const char* str, const DHT* dht, int photoPin);
    char* getJSON();
    char* getParams();
};

#endif
