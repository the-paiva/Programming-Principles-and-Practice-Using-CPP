/*Absolute zero is the lowest temperature that can be reached; it is –273.15°C,
or 0K. The above program, even when corrected, will produce erroneous results when 
given a temperature below this. Place a check in the main program that will produce 
an error if a temperature is given below –273.15°C.*/

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

    if (c < -273.15){
        cerr << "INVALID TEMPERATURE! SHUTTING PROGRAM DOWN...\n";
        return 1;
    }

    double k = ctok(c); // convert temperature
    cout << "\n" << c << " C = " << k << " K\n"; // print out temperature
    return 0;
}
