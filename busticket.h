#ifndef BUSTICKET_H_INCLUDED
#define BUSTICKET_H_INCLUDED

#include<stdio.h>
// Constants
#define TOTAL_SEATS 50
#define NUM_CITIES 5

void initializeSeats(int seats[][NUM_CITIES-1]);
int bookTickets(int seats[][NUM_CITIES-1], float priceMatrix[NUM_CITIES][NUM_CITIES]);
void cancelTickets(int seats[][NUM_CITIES-1]);
void viewAvailableSeats(int seats[][NUM_CITIES-1]);
void displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination);
float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]);

#endif
