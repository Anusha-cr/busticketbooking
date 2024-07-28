#include "busticket.h"

// Constants
#define TOTAL_SEATS 50
#define NUM_CITIES 5

void cancelTickets(int seats[][NUM_CITIES-1]) {
    int numTicketsToCancel;
    printf("Enter the number of tickets to cancel: ");
    if (scanf("%d", &numTicketsToCancel) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    for (int i = 0; i < numTicketsToCancel; i++) {
        int seatNumber;
        printf("Enter the seat number to cancel (1-%d): ", TOTAL_SEATS);
        if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > TOTAL_SEATS) {
            printf("Invalid input. Please enter a valid seat number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        // Choose the departure city
        int departure;
        printf("Choose the departure city:\n");
        printf("1. Mysore\n");
        printf("2. Mandya\n");
        printf("3. Maddur\n");
        printf("4. Ramanagar\n");
        printf("5. Bangalore\n");
        printf("Enter your choice: ");
        if (scanf("%d", &departure) != 1 || departure < 1 || departure > 5) {
            printf("Invalid input. Please enter a valid departure city.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        // Choose the destination city
        int destination;
        printf("Choose the destination city:\n");
        printf("1. Mysore\n");
        printf("2. Mandya\n");
        printf("3. Maddur\n");
        printf("4. Ramanagar\n");
        printf("5. Bangalore\n");
        printf("Enter your choice: ");
        if (scanf("%d", &destination) != 1 || destination < 1 || destination > 5) {
            printf("Invalid input. Please enter a valid destination city.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        if (departure == destination) {
            printf("Departure and destination cannot be the same.\n");
            continue;
        }

        // Check if the seat is booked for the entire journey
        int seatBooked = 1;
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            if (seats[seatNumber - 1][segment] == 1) {
                seatBooked = 0;
                break;
            }
        }

        if (seatBooked) {
            // Mark the seat as available for the entire journey
            for (int segment = departure - 1; segment < destination - 1; segment++) {
                seats[seatNumber - 1][segment] = 1;
            }
            printf("Seat %d cancelled successfully from city %d to city %d.\n", seatNumber, departure, destination);
        } else {
            printf("Seat %d is not booked for the entire journey from city %d to city %d.\n", seatNumber, departure, destination);
        }
    }
}
