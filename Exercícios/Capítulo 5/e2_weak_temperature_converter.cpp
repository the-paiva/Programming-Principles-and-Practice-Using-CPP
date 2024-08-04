/*The following program takes in a temperature value in Celsius and
converts it to Kelvin. This code has many errors in it. Find the
errors, list them, and correct the code.*/

#include <iostream>
using namespace std;

// converts Celsius to Kelvin
double ctok(double c){
    double k = c + 273.15;
    return k;
}

int main(){
    double c = 0; // declare input variable
    cout << "\nEnter a temperature (in Celsius): ";
    cin >> c; // retrieve temperature to input variable

    double k = ctok(c); // convert temperature
    cout << "\n" << c << " C = " << k << " K\n"; // print out temperature
}

/*Errors Fixed

    1.  Error: Function ctok was returning a type, instead of a parameter
        Fix: ctok returns k

    2.  Error: ctok was returning an int, instead of a double
        Fix: k (originally, an int value) was changed to double

    3.  Error: cin input was using an inexistent variable (d)
        Fix: Variable changed (d to c)

    4.  Error: ctok in main() was using a string argument (should be a double)
        Fix: Changed the string to double

    5.  Error: cout was written with the first letter in uppercase (Cout)
        Fix: Changed to cout (this time, written correctly)

    6.  Error: Text in the last cout was in char format (should be string)
        Fix: Changed the text to string format ('' to "")*/
