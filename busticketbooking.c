#include <stdio.h>

#define TOTAL_SEATS 50
#define NUM_CITIES 5

// Function prototypes
void initializeSeats(int seats[][NUM_CITIES-1]);
int bookTickets(int seats[][NUM_CITIES-1], float priceMatrix[NUM_CITIES][NUM_CITIES]);
void cancelTickets(int seats[][NUM_CITIES-1]);
void viewAvailableSeats(int seats[][NUM_CITIES-1]);
void displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination);
float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]);

int main() {
    // Arrays to store the availability of seats for Regular and Deluxe bus types
    int regularSeats[TOTAL_SEATS][NUM_CITIES-1];
    int deluxeSeats[TOTAL_SEATS][NUM_CITIES-1];

    // Initialize seats to available (1)
    initializeSeats(regularSeats);
    initializeSeats(deluxeSeats);

    // Price matrices for Regular and Deluxe bus types
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
                    bookTickets(regularSeats, regularPriceMatrix);
                } else {
                    bookTickets(deluxeSeats, deluxePriceMatrix);
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
                    cancelTickets(regularSeats);
                } else {
                    cancelTickets(deluxeSeats);
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

int bookTickets(int seats[][NUM_CITIES-1], float priceMatrix[NUM_CITIES][NUM_CITIES]) {
    int numTickets;
    printf("Enter the number of tickets to book: ");
    if (scanf("%d", &numTickets) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');  // Clear input buffer
<<<<<<< HEAD
        return bookedSeats;
    }
    if (bookedSeats + numTickets <= totalSeats) {
        // Choose a bus type
        int busType;
        printf("Choose a bus type:\n");
        printf("1. Regular\n");
        printf("2. Deluxe\n");
        printf("Enter your choice: ");
        if (scanf("%d", &busType) != 1 || (busType != 1 && busType != 2)) {
            printf("Invalid input. Please enter a valid bus type.\n");
            while (getchar() != '\n');  // Clear input buffer
            return bookedSeats;
=======
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
            float price = calculatePrice(departure, destination, priceMatrix);
            printf("Seat %d booked successfully from city %d to city %d. Price: %.2f\n", seatNumber, departure, destination, price);
            seatsBooked++;
        } else {
            printf("Seat %d is not available for the entire journey from city %d to city %d.\n", seatNumber, departure, destination);
        }
    }
    return seatsBooked;
}

void cancelTickets(int seats[][NUM_CITIES-1]) {
    int numTicketsToCancel;
    printf("Enter the number of tickets to cancel: ");
    if (scanf("%d", &numTicketsToCancel) != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n');  // Clear input buffer
        return;
    }

    for (int i = 0; i < numTicketsToCancel; i++) {
        int seatNumber;
        printf("Enter the seat number to cancel (1-%d): ", TOTAL_SEATS);
        if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > TOTAL_SEATS) {
            printf("Invalid input. Please enter a valid seat number.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
>>>>>>> c92d89148c49f5a844dcb7645325d3118df3a0d0
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
<<<<<<< HEAD
        if (scanf("%d", &departure) != 1 || departure < 1 || departure > 3) {
            printf("Invalid input. Please enter a valid departure city.\n");
            while (getchar() != '\n');  // Clear input buffer
            return bookedSeats;
=======
        if (scanf("%d", &departure) != 1 || departure < 1 || departure > 5) {
            printf("Invalid input. Please enter a valid departure city.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
>>>>>>> c92d89148c49f5a844dcb7645325d3118df3a0d0
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
<<<<<<< HEAD
        if (scanf("%d", &destination) != 1 || destination < 1 || destination > 3) {
            printf("Invalid input. Please enter a valid destination city.\n");
            while (getchar() != '\n');  // Clear input buffer
            return bookedSeats;
        }

        // Calculate ticket price based on departure, destination, and bus type
        float totalPrice;
        if (departure == destination) {
            totalPrice = numTickets * 0.0;
        } else if (departure == 1 && destination == 2) {
            totalPrice = numTickets * (busType == 1 ? 50.0 : 100.0);
        } else if (departure == 2 && destination == 1) {
            totalPrice = numTickets * (busType == 1 ? 50.0 : 100.0);
        } else if (departure == 1 && destination == 3) {
            totalPrice = numTickets * (busType == 1 ? 150.0 : 200.0);
        } else if (departure == 3 && destination == 1) {
            totalPrice = numTickets * (busType == 1 ? 150.0 : 200.0);
        } else if (departure == 2 && destination == 3) {
            totalPrice = numTickets * (busType == 1 ? 250.0 : 300.0);
        } else if (departure == 3 && destination == 2) {
            totalPrice = numTickets * (busType == 1 ? 250.0 : 300.0);
=======
        if (scanf("%d", &destination) != 1 || destination < 1 || destination > 5) {
            printf("Invalid input. Please enter a valid destination city.\n");
            while (getchar() != '\n');  // Clear input buffer
            continue;
>>>>>>> c92d89148c49f5a844dcb7645325d3118df3a0d0
        }

        if (departure == destination) {
            printf("Departure and destination cannot be the same.\n");
            continue;
        }

        // Check if the seat is booked for the entire journey
        int seatBooked = 1;
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            if (seats[seatNumber - 1][segment] == 1) {
                seatBooked = 0;
                break;
            }
        }

        if (seatBooked) {
            // Mark the seat as available for the entire journey
            for (int segment = departure - 1; segment < destination - 1; segment++) {
                seats[seatNumber - 1][segment] = 1;
            }
            printf("Seat %d cancelled successfully from city %d to city %d.\n", seatNumber, departure, destination);
        } else {
            printf("Seat %d is not booked for the entire journey from city %d to city %d.\n", seatNumber, departure, destination);
        }
    }
}

<<<<<<< HEAD
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
=======
void viewAvailableSeats(int seats[][NUM_CITIES-1]) {
    printf("Available seats:\n");
    displayAvailableSeats(seats, 1, NUM_CITIES); // Display all available seats from start to end
>>>>>>> c92d89148c49f5a844dcb7645325d3118df3a0d0
}

void displayAvailableSeats(int seats[][NUM_CITIES-1], int departure, int destination) {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        int seatAvailable = 1;
        for (int segment = departure - 1; segment < destination - 1; segment++) {
            if (seats[i][segment] == 0) {
                seatAvailable = 0;
                break;
            }
        }
        if (seatAvailable) {
            printf("Seat %d: Available\n", i + 1);
        }
    }
}

float calculatePrice(int departure, int destination, float priceMatrix[NUM_CITIES][NUM_CITIES]) {
    // Convert 1-based index to 0-based index
    int depIndex = departure - 1;
    int destIndex = destination - 1;
    return priceMatrix[depIndex][destIndex];
}
