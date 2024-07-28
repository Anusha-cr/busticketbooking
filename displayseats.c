#include "busticket.h"

// Constants
#define TOTAL_SEATS 50
#define NUM_CITIES 5

void displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination) {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        int seatAvailable = 1;
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            if (seats[i][segment] == 0) {
                seatAvailable = 0;
                break;
            }
        }
        if (seatAvailable) {
            printf("Seat %d: Available\n", i + 1);
        }
    }
}
