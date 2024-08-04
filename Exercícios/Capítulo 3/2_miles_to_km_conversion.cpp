#include <iostream>
using namespace std;


double convert_distance(double miles)
{
    return miles * 1609;
}


int main()
{
    double miles, kilometer;

    cout << "Enter the number of miles runned: ";
    cin >> miles;

    kilometer = convert_distance(miles);

    cout << "The same distance runned in kilometers equals " << kilometer << " km.";
}
