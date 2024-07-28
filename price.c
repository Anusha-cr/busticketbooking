#include "busticket.h"

float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]) {
    // Convert 1-based index to 0-based index
    int depIndex = departure - 1;
    int destIndex = destination - 1;
    return priceMatrix[depIndex][destIndex];
}
