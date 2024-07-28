#include "busticket.h"

void writeCancellationDetailsToFile(int busType, int departure, int destination, int seatNumber) {
    FILE *fp;
    if (busType == 1) {
        fp = fopen("regular_cancellation_details.txt", "a");
    } else {
        fp = fopen("deluxe_cancellation_details.txt", "a");
    }

    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "Bus Type: %s\n", (busType == 1) ? "Regular" : "Deluxe");
    fprintf(fp, "Departure City: %s\n", getCityName(departure));
    fprintf(fp, "Destination City: %s\n", getCityName(destination));
    fprintf(fp, "Cancelled Seat Number: %d\n", seatNumber);
    fprintf(fp, "------------------------------------\n");

    fclose(fp);
}