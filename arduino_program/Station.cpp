#include "Station.h"

char* Station::getJSON() {
  char* result = new char[128]();
  sprintf(result, "{\"stationName\": \"%.16s\", \"data\": ", _name);

  char* data = myData.getJSON();
  strcat(result, data);
  strcat(result, "}");
  delete[] data;
  return result;
}
