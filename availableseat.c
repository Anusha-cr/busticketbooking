#include "busticket.h"

#define TOTAL_SEATS 50
#define NUM_CITIES 5

void viewAvailableSeats(int seats[][NUM_CITIES-1]) {
    printf("Available seats:\n");
    displayAvailableSeats(seats, 1, NUM_CITIES); // Display all available seats from start to end
}

}

