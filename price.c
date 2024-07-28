#include "busticket.h"

// Constants
#define TOTAL_SEATS 50
#define NUM_CITIES 5

float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]) {
    // Convert 1-based index to 0-based index
    int depIndex = departure - 1;
    int destIndex = destination - 1;
    return priceMatrix[depIndex][destIndex];
}