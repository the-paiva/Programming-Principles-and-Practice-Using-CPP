/*Write a program that converts from Celsius to Fahrenheit and from Fahrenheit 
to Celsius (formula in §4.3.3). Use estimation (§5.8) to see if your results 
are plausible.*/

#include <iostream>
#include <typeinfo>
using namespace std;

class Bad_value{};
class Bad_char{};

//Gets the type of temperature to be converted (Celsius or Fahrenheit)
char get_temp_type(){
    char temp_type;
    cout << "\nType C to enter a Celsius value";
    cout << "\nType F to enter a Fahrenheit value\n";
    cin >> temp_type;
    return temp_type;
}

//Checks if the type of temperature was entered correct
void check_temp_type(char temp_type){
    if (temp_type != 'C' and temp_type != 'F'){
        throw Bad_char{};
    }
}

//Gets value of the temperature
double get_temp(){
    double temp;
    cout << "\nEnter a value: ";
    cin >> temp;
    return temp;
}

/*Checks if the value of temperature is higher than absolute zero (No value 
can be lower than that) or if is really a double*/
void check_temp(double temp, char temp_type){
    if (temp_type == 'C' and temp < -273.15 or temp_type == 'F' and temp < -459.67){
        throw Bad_value{};
    } else if (cin.fail()){
        cin.clear();
        cin.ignore();
        throw bad_cast{};
    }
}

//Converts a Celsius scale to Fahrenheit
double convert_to_fahrenheit(double temp){
    double new_temp = (temp * 9 / 5) + 32;
    return new_temp;
}

//Converts a Fahrenheit scale to Celsius
double convert_to_celsius(double temp){
    double new_temp = (temp - 32) * 5 / 9;
    return new_temp;
}

int main(){
    try{
        char temp_type = get_temp_type(); //Temp = Temperature
        temp_type = toupper(temp_type); //Converts to uppercase
        check_temp_type(temp_type);

        double temp = get_temp();
        check_temp(temp, temp_type);

        double new_temp; //Converted temperature
        char new_temp_type;

        if (temp_type == 'C'){
            new_temp = convert_to_fahrenheit(temp);
            new_temp_type = 'F';
        } else{
            new_temp = convert_to_celsius(temp);
            new_temp_type = 'C';
        }

        //Output of conversion. E.g: 1 C = 33.8 F
        cout << "\n" << temp << " " << temp_type << " = " << new_temp << " " << new_temp_type << "\n";
        return 0;
    } catch (Bad_char){
        cerr << "\nINVALID CHARACTER! KILLING PROGRAM NOW...\n";
        return 1;
    } catch (Bad_value){
        cerr << "\nINVALID VALUE! KILLING PROGRAM NOW...\n";
        return 2;
    } catch (bad_cast){
        cerr << "\nWRONG TYPE OF VALUE! KILLING PROGRAM NOW...\n";
        return 3;
    }
}
