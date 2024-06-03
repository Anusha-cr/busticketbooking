#include "busticket.h"

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