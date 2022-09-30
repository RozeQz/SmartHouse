#include "Data.h"

char* Data::getJSON() {
  char* result = new char[64]();
  sprintf(result, "{\"brightness\": %d, \"temperature\": ", _brightness);
  dtostrf(_temperature, 4, 2, result + strlen(result));
  sprintf(result + strlen(result), ", \"humidity\": %d}", _humidity);
  return result;
}
