#include "busticket.h"

#define TOTAL_SEATS 50
#define NUM_CITIES 5

const char* getCityName(int cityIndex) {
    switch (cityIndex) {
        case 1: return "Mysore";
        case 2: return "Mandya";
        case 3: return "Maddur";
        case 4: return "Ramanagar";
        case 5: return "Bangalore";
        default: return "Unknown";
    }
}
