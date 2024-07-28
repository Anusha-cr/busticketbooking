#include "busticket.h"

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