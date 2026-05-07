#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Global variables to simulate the system state
queue<string> bookingQueue;
queue<string> cancellationQueue;
int availableTickets = 2;

// Function to display the current status of the system
void display_status()
{
    cout << "\n-- System Status --" << endl;
    cout << "Available Tickets: " << availableTickets << endl;
    cout << "Booking Queue Size: " << bookingQueue.size() << endl;
    cout << "Cancellation Queue Size: " << cancellationQueue.size() << endl;
    cout << "-------------------\n"
         << endl;
}

// Function to process pending booking and cancellation requests
void process_requests()
{
    // Process a cancellation request first if one exists
    if (!cancellationQueue.empty())
    {
        string passengerToCancel = cancellationQueue.front();
        cancellationQueue.pop();
        availableTickets++;
        cout << "Cancellation processed for " << passengerToCancel << ". Ticket freed." << endl;
    }

    // Process a booking request if there are tickets available
    if (!bookingQueue.empty() && availableTickets > 0)
    {
        string passengerToBook = bookingQueue.front();
        bookingQueue.pop();
        availableTickets--;
        cout << "Booking processed for " << passengerToBook << ". Ticket allocated." << endl;
    }
}

// Function to add a passenger to the booking queue
void book_ticket(const string &passenger)
{
    bookingQueue.push(passenger);
    cout << "Booking request for " << passenger << " added to queue." << endl;
    process_requests();
}

// Function to add a passenger to the cancellation queue
void cancel_ticket(const string &passenger)
{
    cancellationQueue.push(passenger);
    cout << "Cancellation request for " << passenger << " added to queue." << endl;
    process_requests();
}

int main()
{
    // Simulate a series of actions
    book_ticket("Customer A");
    book_ticket("Customer B");
    book_ticket("Customer C");   // This request will be queued
    cancel_ticket("Customer B"); // A cancellation is requested
    book_ticket("Customer D");   // A new booking is requested

    // Display the final state of the system
    display_status();

    return 0;
}
