#include "busticket.h"

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
