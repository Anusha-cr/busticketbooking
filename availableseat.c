#iclude "busticket.h"

void viewAvailableSeats(int bookedSeats, int totalSeats) {
    printf("Available seats: %d\n", totalSeats - bookedSeats);
}
