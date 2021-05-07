
#include <Wire.h> // Include the I2C library (required)
#include <SparkFunSX1509.h> // Include SX1509 library

const byte SX1509_A[3] = {0x3E, 0x3F, 0x70};

SX1509 s[3];

const int rows = 3;
const int columns = 7;
int pannel[ rows ][ columns ] = {
  { 0, 1, 2, 3, 4, 5, 6 },
  { 7, 8, 9, 10, 11, 12, 13 },
  {14, 15, 16, 17, 18, 19, 20}
};

void tpanel(uint8_t x, uint8_t y, uint8_t level) {
  uint8_t xy = pannel[x][y];
  s[xy / 16].digitalWrite(xy % 16, level);
}

void setup()
{
  uint8_t i;
  for ( i = 0; i < 3; i++) {
    s[i].begin(SX1509_A[i]);
    s[i].clock(INTERNAL_CLOCK_2MHZ, 4);
  }

  for ( i = 0; i < 3; i++) {
    for (uint8_t x = 0; x < 16; x++) {
      s[i].pinMode(x, OUTPUT); // Set LED pin to OUTPUT
      s[i].digitalWrite(x, HIGH);
    }
  }
  tpanel(2, 3, LOW);

}

void loop()
{
  // Relax! The SX1509's got this...
}
