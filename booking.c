#include "busticket.h"

int bookTickets(int bookedSeats, int totalSeats) {
    int numTickets;
    printf("Enter the number of tickets to book: ");
    scanf("%d", &numTickets);
    if (bookedSeats + numTickets <= totalSeats) {
        // Choose a bus type
        int busType;
        printf("Choose a bus type:\n");
        printf("1. Regular\n");
        printf("2. Deluxe\n");
        printf("Enter your choice: ");
        scanf("%d", &busType);

        // Choose the departure city
        int departure;
        printf("Choose the departure city:\n");
        printf("1. Bangalore\n");
        printf("2. Mysore\n");
        printf("3. Mangalore\n");
        printf("Enter your choice: ");
        scanf("%d", &departure);

        // Choose the destination city
        int destination;
        printf("Choose the destination city:\n");
        printf("1. Bangalore\n");
        printf("2. Mysore\n");
        printf("3. Mangalore\n");
        printf("Enter your choice: ");
        scanf("%d", &destination);

        // Calculate ticket price based on departure, destination, and bus type
        float totalPrice;
        if (departure == destination) {
            totalPrice = numTickets * 0.0;
        } else if (departure == 1 && destination == 2) {
            totalPrice = numTickets * (busType == 1 ? 50.0 : 100.0);
        } else if (departure == 2 && destination == 1) {
            totalPrice = numTickets * (busType == 1 ? 50.0 : 100.0);
        } else if (departure == 1 && destination == 3) {
            totalPrice = numTickets * (busType == 1 ? 150.0 : 200.0);
        } else if (departure == 3 && destination == 1) {
            totalPrice = numTickets * (busType == 1 ? 150.0 : 200.0);
        } else if (departure == 2 && destination == 3) {
            totalPrice = numTickets * (busType == 1 ? 250.0 : 300.0);
        } else if (departure == 3 && destination == 2) {
            totalPrice = numTickets * (busType == 1 ? 250.0 : 300.0);
        }

        printf("Ticket(s) booked successfully! Total price: %.2f\n", totalPrice);
        bookedSeats += numTickets;
    } else {
        printf("Sorry, not enough seats available.\n");
    }
    return bookedSeats;
}
