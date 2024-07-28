#include "busticket.h"

#define TOTAL_SEATS 50
#define NUM_CITIES 5

void initializeSeats(int seats[][NUM_CITIES-1]) {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        for (int j = 0; j < NUM_CITIES-1; j++) {
            seats[i][j] = 1; // 1 indicates the seat is available
        }
    }
}
