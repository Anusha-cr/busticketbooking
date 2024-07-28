#include <stdio.h>

<<<<<<< HEAD
// Constants
#define TOTAL_SEATS 50
#define NUM_CITIES 5


=======
#define TOTAL_SEATS 50
#define NUM_CITIES 5

>>>>>>> 0255ac236c84ea466b258d27fb1d448205820821
// Function prototypes
void initializeSeats(int seats[][NUM_CITIES-1]);
int bookTickets(int seats[][NUM_CITIES-1], float priceMatrix[NUM_CITIES][NUM_CITIES], int busType);
void cancelTickets(int seats[][NUM_CITIES-1], int busType);
void viewAvailableSeats(int seats[][NUM_CITIES-1]);
void displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination);
float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]);
void writeBookingDetailsToFile(int busType, int departure, int destination, int seatNumber, float price);
void writeCancellationDetailsToFile(int busType, int departure, int destination, int seatNumber);
const char* getCityName(int cityIndex);

int main() {
    // Arrays to store the availability of seats for Regular and Deluxe bus types
    int regularSeats[TOTAL_SEATS][NUM_CITIES-1];
    int deluxeSeats[TOTAL_SEATS][NUM_CITIES-1];

    // Initialize seats to available (1)
    initializeSeats(regularSeats);
    initializeSeats(deluxeSeats);

    // Price matrices for Regular and Deluxe bus types (in INR)
    float regularPriceMatrix[NUM_CITIES][NUM_CITIES] = {
        {0.0, 30.0, 60.0, 90.0, 120.0},
        {30.0, 0.0, 30.0, 60.0, 90.0},
        {60.0, 30.0, 0.0, 30.0, 60.0},
        {90.0, 60.0, 30.0, 0.0, 30.0},
        {120.0, 90.0, 60.0, 30.0, 0.0}
    };

    float deluxePriceMatrix[NUM_CITIES][NUM_CITIES] = {
        {0.0, 60.0, 120.0, 180.0, 240.0},
        {60.0, 0.0, 60.0, 120.0, 180.0},
        {120.0, 60.0, 0.0, 60.0, 120.0},
        {180.0, 120.0, 60.0, 0.0, 60.0},
        {240.0, 180.0, 120.0, 60.0, 0.0}
    };


    // Display menu
    printf("Welcome to Bus Ticket Booking System\n");
    printf("Bus Route: Mysore -> Mandya -> Maddur -> Ramanagar -> Bangalore\n");

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
                printf("Choose a bus type to book tickets:\n");
                printf("1. Regular\n");
                printf("2. Deluxe\n");
                printf("Enter your choice: ");
                if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
                    printf("Invalid input. Please enter a valid bus type.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    continue;
                }
                if (choice == 1) {
                    bookTickets(regularSeats, regularPriceMatrix, 1);
                } else {
                    bookTickets(deluxeSeats, deluxePriceMatrix, 2);
                }
                break;

            case 2: // Cancel ticket(s)
                printf("Choose a bus type to cancel tickets:\n");
                printf("1. Regular\n");
                printf("2. Deluxe\n");
                printf("Enter your choice: ");
                if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
                    printf("Invalid input. Please enter a valid bus type.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    continue;
                }
                if (choice == 1) {
                    cancelTickets(regularSeats, 1);
                } else {
                    cancelTickets(deluxeSeats, 2);
                }
                break;

            case 3: // View available seats
                printf("Choose a bus type to view available seats:\n");
                printf("1. Regular\n");
                printf("2. Deluxe\n");
                printf("Enter your choice: ");
                if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
                    printf("Invalid input. Please enter a valid bus type.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    continue;
                }
                if (choice == 1) {
                    viewAvailableSeats(regularSeats);
                } else {
                    viewAvailableSeats(deluxeSeats);
                }
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

void initializeSeats(int seats[][NUM_CITIES-1]) {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        for (int j = 0; j < NUM_CITIES-1; j++) {
            seats[i][j] = 1; // 1 indicates the seat is available
        }
    }
}

int bookTickets(int seats[][NUM_CITIES-1], float priceMatrix[NUM_CITIES][NUM_CITIES], int busType) {
    int numTickets;
    printf("Enter the number of tickets to book: ");
    if (scanf("%d", &numTickets) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return -1;
    }

    // Choose the departure city
    int departure;
    printf("Choose the departure city:\n");
    printf("1. Mysore\n");
    printf("2. Mandya\n");
    printf("3. Maddur\n");
    printf("4. Ramanagar\n");
    printf("5. Bangalore\n");
    printf("Enter your choice: ");
    if (scanf("%d", &departure) != 1 || departure < 1 || departure > 5) {
        printf("Invalid input. Please enter a valid departure city.\n");
        while (getchar() != '\n');  // Clear input buffer
        return -1;
    }

    // Choose the destination city
    int destination;
    printf("Choose the destination city:\n");
    printf("1. Mysore\n");
    printf("2. Mandya\n");
    printf("3. Maddur\n");
    printf("4. Ramanagar\n");
    printf("5. Bangalore\n");
    printf("Enter your choice: ");
    if (scanf("%d", &destination) != 1 || destination < 1 || destination > 5) {
        printf("Invalid input. Please enter a valid destination city.\n");
        while (getchar() != '\n');  // Clear input buffer
        return -1;
    }

    if (departure == destination) {
        printf("Departure and destination cannot be the same.\n");
        return -1;
    }

    // Display available seats
    displayAvailableSeats(seats, departure, destination);

    int seatsBooked = 0;
    for (int i = 0; i < numTickets; i++) {
        int seatNumber;
        printf("Enter the seat number to book (1-%d): ", TOTAL_SEATS);
        if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > TOTAL_SEATS) {
            printf("Invalid input. Please enter a valid seat number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
        }

        // Check if the seat is available for the entire journey
        int seatAvailable = 1;
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            if (seats[seatNumber - 1][segment] == 0) {
                seatAvailable = 0;
                break;
            }
        }

        if (seatAvailable) {
            // Mark the seat as booked for the entire journey
            for (int segment = departure - 1; segment < destination - 1; segment++) {
                seats[seatNumber - 1][segment] = 0;
            }

            // Calculate and display ticket price
            float price = calculatePrice(departure, destination, priceMatrix);
            printf("Seat %d booked successfully from %s to %s. Ticket price: ₹%.2f\n", seatNumber,
                   getCityName(departure), getCityName(destination), price);

            // Write booking details to file
            writeBookingDetailsToFile(busType, departure, destination, seatNumber, price);

            seatsBooked++;
        } else {
            printf("Seat %d is not available for the entire journey from %s to %s.\n", seatNumber,
                   getCityName(departure), getCityName(destination));
        }
    }

    return seatsBooked;
}

void cancelTickets(int seats[][NUM_CITIES-1], int busType) {
    int seatNumber;
    printf("Enter the seat number to cancel: ");
    if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid input. Please enter a valid seat number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    // Check if the seat is booked
    int seatBooked = 0;
    for (int segment = 0; segment < NUM_CITIES-1; segment++) {
        if (seats[seatNumber - 1][segment] == 0) {
            seatBooked = 1; // Seat is booked for at least one segment
            break;
        }
    }

    if (!seatBooked) {
        printf("Seat %d is not booked or does not exist.\n", seatNumber);
        return;
    }

    // Get the journey details for cancellation
    int departure, destination;
    printf("Enter the departure city of the journey to cancel:\n");
    printf("1. Mysore\n");
    printf("2. Mandya\n");
    printf("3. Maddur\n");
    printf("4. Ramanagar\n");
    printf("5. Bangalore\n");
    printf("Enter your choice: ");
    if (scanf("%d", &departure) != 1 || departure < 1 || departure > 5) {
        printf("Invalid input. Please enter a valid departure city.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    printf("Enter the destination city of the journey to cancel:\n");
    printf("1. Mysore\n");
    printf("2. Mandya\n");
    printf("3. Maddur\n");
    printf("4. Ramanagar\n");
    printf("5. Bangalore\n");
    printf("Enter your choice: ");
    if (scanf("%d", &destination) != 1 || destination < 1 || destination > 5) {
        printf("Invalid input. Please enter a valid destination city.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    // Check if the seat was booked for the specified journey
    int bookedForJourney = 1;
    for (int segment = departure - 1; segment < destination - 1; segment++) {
        if (seats[seatNumber - 1][segment] != 0) {
            bookedForJourney = 0;
            break;
        }
    }

    if (!bookedForJourney) {
        printf("Seat %d was not booked for the journey from %s to %s.\n", seatNumber,
               getCityName(departure), getCityName(destination));
    } else {
        // Mark the seat as available for the specified journey
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            seats[seatNumber - 1][segment] = 1; // Mark seat as available
        }

        // Display cancellation success message
        printf("Ticket cancelled successfully. Seat %d from %s to %s.\n", seatNumber,
               getCityName(departure), getCityName(destination));

        // Write cancellation details to file
        writeCancellationDetailsToFile(busType, departure, destination, seatNumber);
    }
}



void viewAvailableSeats(int seats[][NUM_CITIES-1]) {
    printf("Available seats:\n");
    displayAvailableSeats(seats, 1, NUM_CITIES); // Display all available seats from start to end
}

void displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination) {
    printf("Available seats from %s to %s:\n", getCityName(departure), getCityName(destination));
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %d:", i + 1);
        int seatAvailable = 1;
        for (int j = departure - 1; j < destination - 1; j++) {
            if (seats[i][j] == 0) {
                seatAvailable = 0;
                break;
            }
        }
        if (seatAvailable) {
            printf(" Available,");
        } else {
            printf(" Not Available,");
        }
        printf("\n");
    }
}

float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]) {
    return priceMatrix[departure - 1][destination - 1];
}

void writeBookingDetailsToFile(int busType, int departure, int destination, int seatNumber, float price) {
    FILE *fp;
    if (busType == 1) {
        fp = fopen("regular_booking_details.txt", "a");
    } else {
        fp = fopen("deluxe_booking_details.txt", "a");
    }

    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "Bus Type: %s\n", (busType == 1) ? "Regular" : "Deluxe");
    fprintf(fp, "Departure City: %s\n", getCityName(departure));
    fprintf(fp, "Destination City: %s\n", getCityName(destination));
    fprintf(fp, "Seat Number: %d\n", seatNumber);
    fprintf(fp, "Ticket Price: ₹%.2f\n", price);
    fprintf(fp, "------------------------------------\n");

    fclose(fp);
}

void writeCancellationDetailsToFile(int busType, int departure, int destination, int seatNumber) {
    FILE *fp;
    if (busType == 1) {
        fp = fopen("regular_cancellation_details.txt", "a");
    } else {
        fp = fopen("deluxe_cancellation_details.txt", "a");
    }

    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(fp, "Bus Type: %s\n", (busType == 1) ? "Regular" : "Deluxe");
    fprintf(fp, "Departure City: %s\n", getCityName(departure));
    fprintf(fp, "Destination City: %s\n", getCityName(destination));
    fprintf(fp, "Cancelled Seat Number: %d\n", seatNumber);
    fprintf(fp, "------------------------------------\n");

    fclose(fp);
}

const char* getCityName(int cityIndex) {
    switch (cityIndex) {
        case 1: return "Mysore";
        case 2: return "Mandya";
        case 3: return "Maddur";
        case 4: return "Ramanagar";
        case 5: return "Bangalore";
        default: return "Unknown";
    }
}

