#include "busticket.h"

// Constants
#define TOTAL_SEATS 50
#define NUM_CITIES 5

int bookTickets(int seats[][NUM_CITIES-1], float priceMatrix[NUM_CITIES][NUM_CITIES]) {
    int numTickets;
    printf("Enter the number of tickets to book: ");
    if (scanf("%d", &numTickets) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return -1;
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
        return -1;
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
        return -1;
    }

    if (departure == destination) {
        printf("Departure and destination cannot be the same.\n");
        return -1;
    }

    // Display available seats
    displayAvailableSeats(seats, departure, destination);

    int seatsBooked = 0;
    for (int i = 0; i < numTickets; i++) {
        int seatNumber;
        printf("Enter the seat number to book (1-%d): ", TOTAL_SEATS);
        if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > TOTAL_SEATS) {
            printf("Invalid input. Please enter a valid seat number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        // Check if the seat is available for the entire journey
        int seatAvailable = 1;
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            if (seats[seatNumber - 1][segment] == 0) {
                seatAvailable = 0;
                break;
            }
        }

        if (seatAvailable) {
            // Mark the seat as booked for the entire journey
            for (int segment = departure - 1; segment < destination - 1; segment++) {
                seats[seatNumber - 1][segment] = 0;
            }
            float price = calculatePrice(departure, destination, priceMatrix);
            printf("Seat %d booked successfully from city %d to city %d. Price: %.2f\n", seatNumber, departure, destination, price);
            seatsBooked++;
        } else {
            printf("Seat %d is not available for the entire journey from city %d to city %d.\n", seatNumber, departure, destination);
        }
    }
    return seatsBooked;
}
