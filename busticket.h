#ifndef BUSTICKET_H_INCLUDED
#define BUSTICKET_H_INCLUDED

#include<stdio.h>
void initializeSeats(int seats[][NUM_CITIES-1]);
int bookTickets(int bookedSeats, int totalSeats);
int cancelTickets(int bookedSeats);
void viewAvailableSeats(int bookedSeats, int totalSeats);
void displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination);
float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]);

#endif
