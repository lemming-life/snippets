// Author: http://lemming.life
// Language: C++
// Description: A collection of C++ language examples.
// Covers: data types, initialization, input/output, if, while, switch, constant, arrays, vectors
// iterators, 

// To compile at terminal: g++ language.cpp
// To run at terminal: ./a.out

// START

// This is a comment

/*
    This is a multi
    line
    comment
*/

// The way to include libraries is to use #include
#include <iostream> // For console input and output.
#include <string>   // For strings
#include <vector>   // Essentially a dynamic array.
#include <fstream>  // For reading and writing files
#include <exception>
using namespace std; // So that we avoid having to type std::cout, std::cin, etc.


// Define a dataType
typedef int myNumberType; // note that you replace int with other types.

// The program entry point.
// - argc is the argument count
// - args is a pointer to a pointer that has a c-string.
// - Example: ./a.out Hello World
//      - argc will be 3
//      *(argv + 0) will be ./a.out
//      argv[1] will be Hello    (Note that this is another way of accessing the value)
//      argv[2] will be World
int main(int argc, char** argv) {

    // Variable declaration example
    uint anUint;    // 0, 1, 2, 3, etc.
    int anInt;      // ... -2, -1, 0, 1, 2, ...
    float aFloat;   // 
    char aChar;     // Look ascii table, but 2^8
    bool aBool;     // true, false
    string aString; // Note that for string type we need to #include <string>
    myNumberType someNumber; // is an int really

    // Initialize the variable using literals.
    anUint = 123; 
    anInt = 123; 
    aFloat = 123.456;
    aChar = 'a';    
    aBool = true; 
    aString = "Hello, World";

    int anotherInt;
    cout << anotherInt; // What is in anotherInt?  We don't know, so initialize variables.

    // Assigning and changing values
    anInt = anInt; // ok
    anInt = anInt + 1; // ok
    anInt++; // Return anInt, then add one
    ++anInt; // Add one to anInt, return anInt

    const int INT_CONSTANT = 5; // A constant cannot change once defined.

    // Console output
    std::cout << "Hello, World" << std::endl;

    // Since we are using namespace std; we can write it as:
    cout << "Hello, World" << endl;

    // For performance it may be worth not doing endl, and doing '\n' instead.
    cout << "Hello, World\n";
    cout << aString << '\n';

    // FORMAT Specifying
    ios::fmtflags f(cout.flags() );
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); // 2 digits
    cout << "A format specifying: $" << aFloat << '\n'; // $123.46
    //cout.flags( f );    

    // If
    if (true) {
        // this runs
    }

    if (false) {
        // this doesn't run
    }
    // This runs

    // If else
    if (false) {
        // This doesn't run
    } else {
        // This runs
    }

    // If else if
    if (false) {
        // Doesn't run
    } else if (true) {
        // This runs
    }

    // If else if else
    if (false) {
        // Doesn't run
    } else if(false) {
        // Doesn't run
    } else {
        // This runs
    }

    anInt = 2;
    switch (anInt) {
        case 1:
            break;
        case 2:
            // This runs
            break;
        default:
            //"Doesn't run."
            break;
    }

    // Note no break
    anInt = 1;
    switch (anInt) {
        case 1:
            // This runs
        case 2:
            // This runs
            break;
        default:
            //"Doesn't run."
            break;
    }


    // For loop
    for(int i=0; i<argc; ++i) {
        cout << "i: " << i << " | " << argv[i] << '\n';
    }

    // While loop
    // - Depending on the condition this may never run.
    int count = 0;
    while( count<argc) {
        ++count;
    }

    // Do While loop
    // - Runs at least once
    count = 0;
    do {
        ++count;
    } while( count<argc );

    
    // Scope, and closure.
    {
        // ScopeA
        int scopeAInt = 1;

        {
            // ScopeB
            int scopeBInt = scopeAInt; // ok. ScopeB can use anything from ScopeA
        }

        //scopeAInt = scopeBInt; // not ok, ScopeA cannot access ScopeB stuff.
    }

    // ARRAYS
    // - A collection of items side by side in memory.
    const int length = 3;
    char charArray0[length]; // ok, an array of 3 elements.

    // An array, of size n, with values assigned
    char charArray1[] = {'a', 'b', 'c'}; // ok

    // Printing out an array, output will be abc
    for(int i=0; i<length; ++i) {
        cout << charArray1[i];
    }
    cout << '\n';

    char charArray2[] = "abc"; // Note that this has null termination character \0
    cout << charArray2 << '\n'; // Prints out abc


    // POINTER
    // - A variable that points to an address

    // A pointer to an integer
    int* intPtr = &anInt; // The & gives us the address of the variable.

    // Dereferencing: Used for getting or setting the value at the address.
    if (anInt == *intPtr) {
        // This runs.
    }

    
    // Pointers and arrays, char
    char* charPtr = charArray1;
    *charPtr = charArray1[0]; // Same location
    *(charPtr + 0) = charArray1[0];  // Same as above
    *(charPtr + 1) = charArray1[1]; // Same location, we moved the address by one byte.
    
    
    // Pointers and arrays, ints
    
    int intArray[] = {1, 2, 3, 4};
    intPtr = intArray;
    *(intPtr + 0) = intArray[0]; // same
    *(intPtr + 1) = intArray[1]; // Same location, note the intPtr had to be advanced by 4 bytes because integer is 4 bytes
    *(intPtr + 2) = 99;
    *(intPtr + 3) = -123;
    for (int i=0; i<4; ++i) { cout << intArray[i]; }
    cout << '\n';  // will print 1299-123

    // VECTORS
    // - Like a resizable array.
    
    std::vector<int> vectorOfInts; // A vector that can hold int elements

    // Adding elements
    for (int i=0; i<5; ++i) {
        vectorOfInts.push_back(i); // Adds an element to the back
    }
    
    // Accessing elements
    vectorOfInts[0] = vectorOfInts.at(1);
    vectorOfInts.front() = vectorOfInts.size(); 

    // Removing elements
    vectorOfInts.pop_back(); // Removes last element
    
    // Erase the nth element
    vectorOfInts.erase(vectorOfInts.begin() + 1);
    
    // Using iterators to access
    for ( 
        vector<int>::iterator iterator = vectorOfInts.begin();
        iterator != vectorOfInts.end();
        ++iterator
        ) {
            cout << *iterator;
    }
    cout << '\n'; // 523



    // INPUT
    // Uncommented to avoid tedious console input.
    /*
    cout << "Give us an int: ";
    cin >> anInt;
    cin.ignore(); // Ignores the \n that is still in buffer
    cout << "You gave us: " << anInt << '\n';

    cout << "Give us a char: ";
    cin >> aChar;
    cin.ignore(); // Ignores the \n that is still in buffer
    cout << "You gave us: " << aChar << '\n';

    cout << "Give us a word: ";
    cin >> aString;
    cin.ignore(); // Ignores the \n that is still in buffer
    cout << "You gave us: " << aString << '\n';

    cout << "Give us a sentence (aka two or more words): ";
    getline(cin, aString);
    cout << "You gave us: " << aString << '\n';
    */

    // FILE I/O
    const char fileName[] = "test.txt";
    remove(fileName); // Ensures that test.txt gets removed.

    // Write a file with integers on each line.
    {
        ofstream fileOut;
        fileOut.open(fileName);
        if (!fileOut.fail()) {
            for (int i=0; i<5; ++i) {
                fileOut << i << '\n';
            }
            fileOut.close();
        }
    }

    // Read a file with integers on each line
    {
        ifstream fileIn;
        fileIn.open(fileName);
        int n;
        while (fileIn.good() && fileIn>>n) {
            if (fileIn.good()) {
                fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cout << "Read from file: " << n << '\n';
        }
        fileIn.close();
    }
    // Output:
    /*
        Read from file: 0
        ...
        Read from file: 4
    */
    
    remove(fileName); // Ensures that test.txt gets removed.


    // EXCEPTIONS

    try {
        throw exception();
    } catch (...) {
        cout << "Caught exception\n";
    }


    {
        ifstream shouldFailStream;
        // Tell the stream to generate an exception for badbit, failbit, eofbit
        shouldFailStream.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
        try {
            shouldFailStream.open(fileName);
            cout << "This line shouldn't run, since " << fileName << " doesn't exist.\n";
        } catch(ios_base::failure) {
            cout << "Failed to open " << fileName << " as expected\n";
        }
    }

    

    // Write a temporary file
    cout  << "Writing a temp file\n";
    int n_lines = 0;
    {
        ofstream fileOut;
        fileOut.open(fileName);
        fileOut << 1 << '\n'; ++n_lines;
        fileOut << 2 << '\n'; ++n_lines;
        fileOut << "e\n"; ++n_lines;
        fileOut << 4 << '\n'; ++n_lines;
        fileOut.close();
    }


    cout << "Reading a temp file, expecting errors\n";
    // We expect to read n_lines integers, but there is an "error" in file.
    try {
        ifstream fileIn;
        fileIn.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
        fileIn.open(fileName);
        int n = 0;
        bool doneWithLoop = false;
        while (n < n_lines && !doneWithLoop) {
            int nFromFile;
            try {
                fileIn >> nFromFile;
                if (fileIn.good()) {
                    fileIn.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Got " << nFromFile << "\n";
                }
            } catch (std::ios_base::failure e) {
                if (fileIn.eof()) {
                    cout << "Reached end of file\n";
                }

                if (fileIn.fail()) {
                    cout << "Something wrong with file, as expected.\n";
                }
                doneWithLoop = true;
            }
            ++n;
        }
        
        fileIn.close();
        
    } catch (ios_base::failure e) {
        cout << "This line should never run\n";
    }
    remove(fileName);



    

    return 0;
}

