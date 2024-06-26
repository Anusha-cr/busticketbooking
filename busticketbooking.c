#include <stdio.h>
// Function prototypes
int bookTickets(int bookedSeats, int totalSeats);
int cancelTickets(int bookedSeats);
void viewAvailableSeats(int bookedSeats, int totalSeats);

int main() {
    // Variables to store the number of available seats and ticket price
    int totalSeats = 50;
    int bookedSeats = 0;

    // Display menu
    printf("Welcome to Bus Ticket Booking System\n");

    // Loop to display menu until user exits
    while (1) {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Book ticket(s)\n");
        printf("2. Cancel ticket(s)\n");
        printf("3. View available seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        // Variable to store user's choice
        int choice;
        scanf("%d", &choice);

        // Process user's choice
        switch (choice) {
            case 1: // Book ticket(s)
                bookedSeats = bookTickets(bookedSeats, totalSeats);
                break;

            case 2: // Cancel ticket(s)
                bookedSeats = cancelTickets(bookedSeats);
                break;

            case 3: // View available seats
                viewAvailableSeats(bookedSeats, totalSeats);
                break;

            case 4: // Exit
                printf("Exiting...\n");
                return 0; // Exit the program

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

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

int cancelTickets(int bookedSeats) {
    int numTicketsToCancel;
    printf("Enter the number of tickets to cancel: ");
    scanf("%d", &numTicketsToCancel);
    if (bookedSeats >= numTicketsToCancel) {
        bookedSeats -= numTicketsToCancel;
        printf("Ticket(s) cancelled successfully!\n");
    } else {
        printf("Not enough tickets booked.\n");
    }
    return bookedSeats;
}

void viewAvailableSeats(int bookedSeats, int totalSeats) {
    printf("Available seats: %d\n", totalSeats - bookedSeats);
}
