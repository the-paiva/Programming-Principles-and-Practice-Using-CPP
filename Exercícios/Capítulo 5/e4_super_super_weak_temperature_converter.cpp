//Do exercise 3 again, but this time handle the error inside ctok().

#include <iostream>
using namespace std;

class Bad_value{};

//Gets the current type of temperature
char get_temp_type(){
    char temp_type;
    cout << "\nType C to enter a temperature in Celsius degree";
    cout << "\nType K to enter a temperature in Kelvin degree\n";
    cin >> temp_type;
    temp_type = toupper(temp_type);

    if (temp_type != 'C' and temp_type != 'K'){
        throw Bad_value{};
    }

    return temp_type;
}

//Gets the current temperature
double get_temp(char temp_type){
    double temp;
    string temp_name;

    if (temp_type == 'C'){
        temp_name = "Celsius";
    } else{
        temp_name = "Kelvin";
    }

    cout << "\nEnter a temperature (in " << temp_name << "): ";
    cin >> temp;

    if (temp < -273.15){
        throw Bad_value{};
    }
    return temp;
}

//Converts one type of temperature to another
double convert_temp(double temp, char temp_type){
    if (temp_type == 'C'){
        double new_temp = temp + 273.15;
        return new_temp;
    } else{
        double new_temp = temp - 273.15;
        return new_temp;
    }
}

//Changes the temperature type after the conversion
char change_temp_type(char temp_type){
    if (temp_type == 'C'){
        temp_type = 'K';
    } else{
        temp_type = 'C';
    }
    return temp_type;
}

int main(){
    try{
        char temp_type = get_temp_type();
        double temp = get_temp(temp_type);
        double new_temp = convert_temp(temp, temp_type);
        char new_temp_type = change_temp_type(temp_type);

        // Print out temperature
        cout << "\n" << temp << " " << temp_type << " = " << new_temp << " " << new_temp_type
        << "\n";
        return 0;
    } catch (Bad_value){
        cerr << "INVALID VALUE! SHUTTING PROGRAM DOWN...\n";
        return 1;
    }
}
