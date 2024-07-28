#include<stdio.h>
#include "busticket.h"
#include "booking.c"
#include "cancel.c"
#include "availableseat.c"
<<<<<<< HEAD
=======

>>>>>>> c92d89148c49f5a844dcb7645325d3118df3a0d0

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
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

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
                while (getchar() != '\n');  // Clear input buffer
                break;
        }
    }

    return 0;
}
