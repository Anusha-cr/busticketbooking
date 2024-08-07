#include "busticket.h"

#define TOTAL_SEATS 50
#define NUM_CITIES 5

void cancelTickets(int seats[][NUM_CITIES-1], int busType) {
    int seatNumber;
    printf("Enter the seat number to cancel: ");
    if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid input. Please enter a valid seat number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    // Check if the seat is booked
    int seatBooked = 0;
    for (int segment = 0; segment < NUM_CITIES-1; segment++) {
        if (seats[seatNumber - 1][segment] == 0) {
            seatBooked = 1; // Seat is booked for at least one segment
            break;
        }
    }

    if (!seatBooked) {
        printf("Seat %d is not booked or does not exist.\n", seatNumber);
        return;
    }

    // Get the journey details for cancellation
    int departure, destination;
    printf("Enter the departure city of the journey to cancel:\n");
    printf("1. Mysore\n");
    printf("2. Mandya\n");
    printf("3. Maddur\n");
    printf("4. Ramanagar\n");
    printf("5. Bangalore\n");
    printf("Enter your choice: ");
    if (scanf("%d", &departure) != 1 || departure < 1 || departure > 5) {
        printf("Invalid input. Please enter a valid departure city.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    printf("Enter the destination city of the journey to cancel:\n");
    printf("1. Mysore\n");
    printf("2. Mandya\n");
    printf("3. Maddur\n");
    printf("4. Ramanagar\n");
    printf("5. Bangalore\n");
    printf("Enter your choice: ");
    if (scanf("%d", &destination) != 1 || destination < 1 || destination > 5) {
        printf("Invalid input. Please enter a valid destination city.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    // Check if the seat was booked for the specified journey
    int bookedForJourney = 1;
    for (int segment = departure - 1; segment < destination - 1; segment++) {
        if (seats[seatNumber - 1][segment] != 0) {
            bookedForJourney = 0;
            break;
        }
    }

    if (!bookedForJourney) {
        printf("Seat %d was not booked for the journey from %s to %s.\n", seatNumber,
               getCityName(departure), getCityName(destination));
    } else {
        // Mark the seat as available for the specified journey
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            seats[seatNumber - 1][segment] = 1; // Mark seat as available
        }

        // Display cancellation success message
        printf("Ticket cancelled successfully. Seat %d from %s to %s.\n", seatNumber,
               getCityName(departure), getCityName(destination));

        // Write cancellation details to file
        writeCancellationDetailsToFile(busType, departure, destination, seatNumber);
    }
}
