// Program reads 30 ints from a file ranging from 0-255 representing 8-bit color codes, stores those codes in an array,
//  and exercises various array methods and outputs colors to console

#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>
#include <string>

using namespace std;

bool isInt(const string &str); // Checks if string is an integer

int main()
{
    // Initialize variables
    const string DIVIDER = string(25, '*');
    const unsigned int SIZE = 30;
    string fileLine = "";
    array<int, SIZE> colorCodes = {}; // Initialize array, will be destroyed and redefined during file read
    // File to read from
    const string INPUT_FILE_NAME = "colorCodes.txt";
    ifstream inputFile(INPUT_FILE_NAME);

    // Output error to console if file is no good
    if (!inputFile)
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        // File is good, begin checking data and add to array if int 0-255
        while (getline(inputFile, fileLine))
        {
            
        }

        // if (stoi(fileLine))
    }

    cout << "\033[48;5;238m     " << endl;
    cout << "\033[0m" << endl;

    // Deallocate heap elements and nullify pointers
    // delete[] clientRosterPtr;
    // clientRosterPtr = nullptr;

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