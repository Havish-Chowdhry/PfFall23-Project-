# PfFall23-Project-Bus-Ticket-Reservation-System
## Creators: Havish Chowdhry, Emaan Arshad, Dania Khan.
Desc: A ticket reservation system for buses.




**1. User Authentication:**
   - Implement a basic login system where users (both customers and admins) can log in using their credentials.
   - Store usernames and passwords securely, perhaps using basic encryption techniques.

**2. Bus Route Management:**
   - Create a data structure to store bus routes, including details like source, destination, departure time, and ticket price.
   - Implement functions to add new routes, update existing ones, and delete routes if necessary.

**3. Seat Reservation:**
   - Use arrays to represent the seating arrangement of buses. For example, a 2D array where rows represent buses and columns represent seats.
   - Implement functions to check seat availability, reserve seats, and cancel reservations.
   - Ensure you handle boundary cases and invalid inputs gracefully.

**4. Ticket Booking:**
   - Allow users to search for buses based on source, destination, and departure time.
   - Once the user selects a bus, allow them to choose the number of seats to book.
   - Generate a booking ID and display it to the user for future reference.

**5. Admin Features:**
   - Only authenticated admins should have access to admin features.
   - Admins can view all bookings, including customer details and booking IDs.
   - Implement a feature for admins to cancel bookings, if required.
   - Implement a feature for admins to view the occupancy rate of buses.

**6. Error Handling:**
   - Implement robust error handling for various scenarios, such as invalid inputs, seat availability checks, etc.
   - Provide clear and helpful error messages to guide the users.

**7. Data Persistence:**
   - Implement a basic form of data persistence using file handling. Store bus routes, bookings, and user data in text files.
   - Create functions to read data from files when the program starts and save data back to files when the program exits.

**8. User-Friendly Interface:**
   - Although you cannot use UI, ensure that the text-based interface is user-friendly and intuitive. Provide clear instructions and options to guide the users.

**9. Extra Features:**
   - Implement a feature to calculate the total revenue earned by the bus service.
   - Implement a feature to display the upcoming buses based on the current system time.
   - Add a feature to sort buses based on departure time or price to help users find suitable options quickly.

**10. Code Modularity and Comments:**
   - Organize your code into functions and modules for better readability and maintainability.
   - Add comments to explain complex sections of your code, making it easier for others (and your future self) to understand.
