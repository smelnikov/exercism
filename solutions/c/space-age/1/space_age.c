#include "space_age.h"

const int EARTH_SECONDS = 31557600; // 365.25 Earth days

const float period[] = {
   0.2408467, // MERCURY
   0.6151972, // VENUS
   1.0      , // EARTH
   1.8808158, // MARS
   11.862615, // JUPITER
   29.447498, // SATURN
   84.016846, // URANUS
   164.79132, // NEPTUNE
};

float age(planet_t planet, int64_t seconds) {
   return (float)seconds / (period[planet] * EARTH_SECONDS); 
}
