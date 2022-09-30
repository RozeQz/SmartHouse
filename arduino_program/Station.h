#ifndef STATION_H
#define STATION_H

#include <string.h>     //
#include <stdio.h>
#include "Data.h"       //

class Station {
  private:
    char _name[16];
  public:
    Data myData;
    Station(const char* str) { strcpy(_name, str); };
    char* getJSON();
};

#endif
