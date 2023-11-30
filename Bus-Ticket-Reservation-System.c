/*
Programmer: Havish Chowdhry, Emaan Arshad, Dania Khan
Date: 27/11/2023 (Date when progress 1 was uploaded) 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define totalRoutes 50

// Structure to represent a bus route
typedef struct 
{
    char pickup[50];
    char destination[50];
    char departureTime[10];
    float ticketPrice;
} Routes;


// Function prototypes for Routes
void initializeRoutes(Routes routes[]);
int addRoute(Routes routes[], int numRoutes);
void displayRoutes(Routes routes[], int numRoutes);
Routes findRoute(Routes routes[], int numRoutes, const char pickup[], const char destination[]);
void updateRoute(Routes routes[], int numRoutes);

// Function to initialize routes array
void initializeRoutes(Routes routes[])
{
    int index;
    for (index = 0; index < totalRoutes; index++)
    {
        // Initialize each route's attributes
        strcpy(routes[index].pickup, "");
        strcpy(routes[index].destination, "");
        strcpy(routes[index].departureTime, "");
        routes[index].ticketPrice = 0.0;
    }
}

// Function to add a new route to the array
int addRoute(Routes routes[], int numRoutes)
{
    if (numRoutes < totalRoutes)
    {
        printf("Enter the pickup location:\n");
        scanf("%s", &routes[numRoutes].pickup);
        
        printf("Enter the destination location:\n");
        scanf("%s", &routes[numRoutes].destination);
        
        printf("Enter the departure time:\n");
        scanf("%s", &routes[numRoutes].departureTime);
        
        printf("Enter the ticket price:\n");
        scanf("%f", &routes[numRoutes].ticketPrice);
        
        printf("Route added successfully!\n");
        
        return numRoutes + 1; // Increment the number of routes
    } 
    else 
    {
        printf("Maximum routes reached. Cannot add more routes.\n");
        return numRoutes;
    }
}

// Function to display all routes in the array
void displayRoutes(Routes routes[], int numRoutes) 
{
    int index;
    printf("\n*** \t Bus Routes \t ***\n");
    printf("Pickup\tDestination\tDeparture Time\tTicket Price\n");
    for (index = 0; index < numRoutes; index++) 
    {
        printf("%s\t%s\t%s\t%.2f\n", routes[index].pickup, routes[index].destination, routes[index].departureTime, routes[index].ticketPrice);
    }
}

// Function to find a route based on source and destination
Routes findRoute(Routes routes[], int numRoutes, const char pickup[], const char destination[]) 
{
    Routes notFoundRoute = { "", "", "", 0.0 }; // Default route if the searched route is not found

    int index;
    for (index = 0; index < numRoutes; index++) 
    {
        if (strcmp(routes[index].pickup, pickup) == 0 && strcmp(routes[index].destination, destination) == 0) 
        {
            return routes[index]; 
        }
    }
    return notFoundRoute; // Return a default route if not found
}

// Function to update an existing route
void updateRoute(Routes routes[], int numRoutes) 
{
    char pickup[50], destination[50];
    
    printf("Enter source of the route to update: ");
    scanf("%s", &pickup);

    printf("Enter destination of the route to update: ");
    scanf("%s", &destination);

    Routes foundRoute = findRoute(routes, numRoutes, pickup, destination);

    if (strcmp(foundRoute.pickup, "") != 0) 
    {
        printf("Enter new departure time: ");
        scanf("%s", foundRoute.departureTime);

        printf("Enter new ticket price: ");
        scanf("%f", &foundRoute.ticketPrice);

        printf("Route updated successfully!\n");
    } 
    else 
    {
        printf("Route not found. Cannot update.\n");
    }


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
