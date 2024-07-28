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
