#include "busticket.h"

#define TOTAL_SEATS 50
#define NUM_CITIES 5

void writeBookingDetailsToFile(int busType, int departure, int destination, int seatNumber, float price) {
    FILE *fp;
    if (busType == 1) {
        fp = fopen("regular_booking_details.txt", "a");
    } else {
        fp = fopen("deluxe_booking_details.txt", "a");
    }

    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "Bus Type: %s\n", (busType == 1) ? "Regular" : "Deluxe");
    fprintf(fp, "Departure City: %s\n", getCityName(departure));
    fprintf(fp, "Destination City: %s\n", getCityName(destination));
    fprintf(fp, "Seat Number: %d\n", seatNumber);
    fprintf(fp, "Ticket Price: ₹%.2f\n", price);
    fprintf(fp, "------------------------------------\n");

    fclose(fp);
}
