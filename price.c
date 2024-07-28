#include "busticket.h"

#define TOTAL_SEATS 50
#define NUM_CITIES 5

float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]) {
    return priceMatrix[departure - 1][destination - 1];
}
