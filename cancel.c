#include "busticket.h"

int cancelTickets(int bookedSeats) {
    int numTicketsToCancel;
    printf("Enter the number of tickets to cancel: ");
    if (scanf("%d", &numTicketsToCancel) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return bookedSeats;
    }
    if (bookedSeats >= numTicketsToCancel) {
        bookedSeats -= numTicketsToCancel;
        printf("Ticket(s) cancelled successfully!\n");
    } else {
        printf("Not enough tickets booked.\n");
    }
    return bookedSeats;
}
