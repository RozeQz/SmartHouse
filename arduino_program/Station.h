#ifndef STATION_H
#define STATION_H

#include <string.h>     //
#include <stdio.h>
#include <TroykaDHT.h>
#include "Data.h"       //

#define DHT_CONNECTION_WAITTIME 300

class Station {
  private:
    char _name[16];
    int _photoPin;
    DHT* _dht;
  public:
    Data myData;
    Station(const char* str, const DHT* dht, int photoPin);
    void getData();
    char* getJSON();
};

#endif
