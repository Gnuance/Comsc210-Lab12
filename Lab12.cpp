// Program reads 30 ints from a file ranging from 0-255 representing 8-bit color codes, stores those codes in an array,
//  and exercises various array methods and outputs colors to console

#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm> // sort(), find()
#include <numeric> // accumulate()

using namespace std;

bool IsInt(const string &str); // Checks if string is an integer
void SetForegroundColor(int color); // Changes cout letter color
void SetBackgroundColor(int color); // Changes cout background color
void ResetColor(); // Resets console output color

int main()
{
    // Initialize variables
    const string DIVIDER = string(25, '*');
    const unsigned int SIZE = 30;
    string fileLine = "";
    array<int, SIZE> colorCodes = {}; // Initialize array, will be destroyed and redefined during file read
    array<int, SIZE>::iterator it; // Iterator to traverse array
    unsigned int index = 0;
    // File to read from
    const string INPUT_FILE_NAME = "colorCodes.txt";
    ifstream inputFile;

    // Try opening file and output error to console if file is no good
    inputFile.open(INPUT_FILE_NAME);
    if (inputFile)
    {
        // File is good, begin checking data and add to array if int 0-255
        while (getline(inputFile, fileLine))
        {
            if (stoi(fileLine) >= 0 && stoi(fileLine) <= 255)
            {
                colorCodes.at(index) = stoi(fileLine);
                index++;
            }
        }
        // CLOSE THE F-ING FILE
        inputFile.close();     

        // Now we have color codes in the array, let's play with array methods and output some colors to console :-D
        // Output all colors numbers to screen with colored font
        cout << "Color Codes:" << endl;
        index = 0;
        for (it = colorCodes.begin(); it != colorCodes.end(); ++it){
            cout << *it << " ";            
            index++;
            if (index % 10 == 0) cout << endl; // Add line spacing
        }
        
        cout << "\nColored Color Codes:" << endl;
        index = 0;
        for (it = colorCodes.begin(); it != colorCodes.end(); ++it){
            SetForegroundColor(*it);
            cout << *it << " ";            
            index++;
            if (index % 10 == 0) cout << endl; // Add line spacing
        }
        ResetColor();
    }
    else // Output error if file no good
    {
        cerr << "Error opening file! Better luck next time..." << endl;
    }    


    // Deallocate heap elements and nullify pointers
    // delete[] clientRosterPtr;
    // clientRosterPtr = nullptr;

    return 0;
}

// Check if input is an integer
bool IsInt(const string &str)
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

// Changes cout letter color
void SetForegroundColor(int color){
    cout << "\033[38;5;" << color << "m";
}
// Changes cout background color
void SetBackgroundColor(int color){
    cout << "\033[48;5;" << color << "m";
}
// Resets console output color
void ResetColor(){
    cout << "\033[0m";
}