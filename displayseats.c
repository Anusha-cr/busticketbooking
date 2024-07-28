#include "busticket.h"

// Constants
#define TOTAL_SEATS 50
#define NUM_CITIES 5

vvoid displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination) {
    printf("Available seats from %s to %s:\n", getCityName(departure), getCityName(destination));
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %d:", i + 1);
        int seatAvailable = 1;
        for (int j = departure - 1; j < destination - 1; j++) {
            if (seats[i][j] == 0) {
                seatAvailable = 0;
                break;
            }
        }
        if (seatAvailable) {
            printf(" Available,");
        } else {
            printf(" Not Available,");
        }
        printf("\n");
    }
}
