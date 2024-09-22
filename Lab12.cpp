// Program reads 30 ints from a file ranging from 0-255 representing 8-bit color codes, stores those codes in an array,
//  and exercises various array methods and outputs colors to console

#include <iostream>
#include <iomanip>
#include <array>
#include <string>

using namespace std;

bool isInt(const string &str);                                                                                  // Checks if string is an integer

int main()
{
    // Initialize variables
    const string DIVIDER = string(30, '*');
    int numClientsToInput = 0;
    Client *clientRosterPtr = nullptr; // Will be used to point to array of clients

    // Get number of clients validation loop
    numClientsToInput = getPositiveIntFromUser(0, "How many clients would you like to input (0 to exit): ", "Invalid. Please enter an integer >= 0.");

    // Now that we have a valid int, let's create a client roster of that size
    clientRosterPtr = new Client[numClientsToInput]; // clientRosterPtr now points to new array of clients

    // Loop through array to create client profiles
    cout << endl
         << "++ INPUT NEW CLIENT INFO ++" << endl; // Input message
    for (size_t i = 0; i < numClientsToInput; i++)
    {
        cout << "Client #" << i + 1 << endl;
        inputClient(&clientRosterPtr[i]);
        cout << endl;
    }
    cout << DIVIDER << endl
         << endl; // Input completion message

    // Loop through array to output client profiles
    cout << "== NEW CLIENT ROSTER ==" << endl; // Roster output message
    for (size_t i = 0; i < Client::numOfClients; i++)
    {
        cout << "Client #" << i + 1 << endl;
        displayClient(&clientRosterPtr[i]);
        cout << endl;
    }
    cout << DIVIDER << endl;

    // Deallocate heap elements and nullify pointers
    delete[] clientRosterPtr;
    clientRosterPtr = nullptr;

    return 0;
}

// Check if input is an integer
bool isInt(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}