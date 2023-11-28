/*
Programmer: Havish Chowdhry, Emaan Arshad, Dania Khan
Date: 27/11/2023 (Date when progress 1 was uploaded) 
*/




//bookinggg
void initializeBookings(Booking bookings[], int numBookings)
{
	int index;
	for (index = 0; index<numBookings; index++)
	{
		bookings[index].busID = 0;
		bookings[index].seatNumber = 0;	
		strcpy(bookings[index].customerName, "");
	}
}

void displayBookings(Booking bookings[], int numBookings)
{
	int index;
	printf("\n*** \t Seat Reservations \t ***\n");
    printf("Bus ID\t Seat Number\t Customer Name\n");
    for (index = 0; index<numBookings; index++)
    {
    	printf("%d\t%d\t%s\n", bookings[index].busID, bookings[index].seatNumber, bookings[index].customerName);
	}
}

int reserveSeat(int seats[][totalSeats], int numBuses, Booking bookings[], int* numBookings)
{
	int busID, seatNum, index, index2;
	printf("Enter the bus ID: ");
	scanf("%d", &busID);
	
	if (busID<1 || busID > numBuses)
	{
		printf("Invalid bus ID.\n");
		return -1;
	}
	
	// Displaying available seats for the selected bus
    printf("Available seats for Bus %d:\n", busID);
    for (index = 0; index < totalSeats; index++)
    {
        if (seats[busID - 1][index] == 0)
        {
            printf("Seat %d\n", index + 1);
        }
    }

    printf("Enter the number of seats to book: ");
    scanf("%d", &seatNum);

    if (seatNum < 1 || seatNum > totalSeats)
    {
        printf("Invalid number of seats.\n");
        return -1;
    }
    
    if (seatNum > totalSeats - *numBookings)
	{
    	printf("Not enough available seats.\n");
    	return -1;
	}

    printf("Enter customer name(s):\n");
    for (index = 0; index < seatNum; index++)
    {
        // Find the first available seat and reserve it
        for (index2 = 0; index2 < totalSeats; index2++)
        {
            if (seats[busID - 1][index2] == 0)
            {
                seats[busID - 1][index2] = 1;
                bookings[*numBookings].busID = busID;
                bookings[*numBookings].seatNumber = index2 + 1;
                printf("Enter name for seat %d: ", index2 + 1);
                scanf("%49s", bookings[*numBookings].customerName);
                (*numBookings)++;
                printf("Seat reserved successfully.\n");
                break;
            }
        }
    }

    return 0;
}

void cancelReservation(int seats[][totalSeats], int numBuses, Booking bookings[], int* numBookings)
{
	int seatNumber, index;
    printf("Enter the seat number to cancel the reservation: ");
    scanf("%d", &seatNumber);

    // Validate seat number
    if (seatNumber < 1 || seatNumber > totalSeats) 
	{
        printf("Invalid seat number.\n");
        return;
    }

    // Find the booking
    int bookingIndex = -1;
    for (index = 0; index < *numBookings; index++) 
	{
        if (bookings[index].seatNumber == seatNumber) 
		{
            bookingIndex = index;
            break;
        }
    }
    
    if (bookingIndex != -1) 
	{
        seats[bookings[bookingIndex].busID - 1][seatNumber - 1] = 0;

        // Remove the booking
        for (index = bookingIndex; index < *numBookings - 1; index++) 
		{
            bookings[index] = bookings[index + 1];
        }

        (*numBookings)--;
        printf("Reservation canceled successfully!\n");
    } 
	else 
	{
        printf("No reservation found for seat %d.\n", seatNumber);
    }
}
//bookinggg
