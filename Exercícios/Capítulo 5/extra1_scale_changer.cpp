/*Write a program that converts from Celsius to Fahrenheit and from Fahrenheit 
to Celsius (formula in §4.3.3). Use estimation (§5.8) to see if your results 
are plausible.*/

#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Bad_value{};
class Bad_char{};

//Clear the screen of any output
void clear_screen(){
    system("cls");
}

//Check if the input was made correctly
void check_cin(){
    if (cin.fail()){
        cin.clear();
        cin.ignore();
        throw bad_cast{};
    }
}

//Adds a value in a char array
vector<char> add_to_char_array(vector<char> array, char value){
    array.push_back(value);
    return array;
}

//Gets the type of temperature to be converted (Celsius or Fahrenheit)
char get_scale(){
    char scale;
    cout << "\nType C to enter a Celsius value";
    cout << "\nType F to enter a Fahrenheit value";
    cout << "\nType K to enter a Kelvin value\n";
    cin >> scale;
    return scale;
}

//Checks if the type of temperature was entered correct
void check_scale(char scale){
    if (scale != 'C' and scale != 'F' and scale != 'K'){
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
void check_temp(double temp, char scale){
    check_cin();
    
    if (scale == 'C' and temp < -273.15 or scale == 'F' and temp < -459.67 or scale == 'K' and temp <= 0){
        throw Bad_value{};
    }
}

//Gets the scale for which value will be converted
char get_new_scale(char scale){
    char new_scale;

    if (scale == 'C'){
        cout << "\nType F to convert to Fahrenheit";
        cout << "\nType K to convert to Kelvin\n";
    } else if (scale == 'F'){
        cout << "\nType C to convert to Celsius";
        cout << "\nType K to convert to Kelvin\n";
    } else{
        cout << "\nType C to convert to Celsius";
        cout << "\nType F to convert to Fahrenheit\n";
    }

    cin >> new_scale;
    return new_scale;
}

//Converts a Celsius scale to Fahrenheit
double celsius_to_fahrenheit(double temp){
    double new_temp = (temp * 9 / 5) + 32;
    return new_temp;
}

//Converts a Celsius scale to Kelvin
double celsius_to_kelvin(double temp){
    double new_temp = temp + 273.15;
    return new_temp;
}

//Converts a Fahrenheit scale to Celsius
double fahrenheit_to_celsius(double temp){
    double new_temp = (temp - 32) * 5 / 9;
    return new_temp;
}

//Converts a Fahrenheit scale to Kelvin
double fahrenheit_to_kelvin(double temp){
    double new_temp = (temp - 32) * 5 / 9 + 273.15;
    return new_temp;
}

//Converts a Kelvin scale to Celsius
double kelvin_to_celsius(double temp){
    double new_temp = temp - 273.15;
    return new_temp;
}

//Converts a Kelvin scale to Fahrenheit
double kelvin_to_fahrenheit(double temp){
    double new_temp = (temp - 273.15) * 9 / 5 + 32;
    return new_temp;
}

//Get the continuity key to break the main loop(or not)
char get_key(){
    char key;
    cout << "\nDo you wish to enter another value? Y/N: ";
    cin >> key;
    return key;
}

//Check the continuity key in order to know if the input was valid
void check_key(char key){
    check_cin();
    
    if (key != 'Y' and key != 'N'){
        throw Bad_char{};
    }
}

int main(){
    try{
        vector<double> temp_list;
        vector<char> scale_list;

        while (true){
            char scale = get_scale();
            scale = toupper(scale); //Converts to uppercase
            check_scale(scale);
            scale_list = add_to_char_array(scale_list, scale);

            double temp = get_temp(); //Temp = Temperature
            check_temp(temp, scale);

            char new_scale = get_new_scale(scale);
            new_scale = toupper(new_scale);
            check_scale(new_scale);

            double new_temp; //Converted temperature

            //Conversions
            if (scale == 'C' and new_scale == 'F'){
                new_temp = celsius_to_fahrenheit(temp);
            } else if (scale == 'C' and new_scale == 'K'){
                new_temp = celsius_to_kelvin(temp);
            } else if (scale == 'F' and new_scale == 'C'){
                new_temp = fahrenheit_to_celsius(temp);
            } else if (scale == 'F' and new_scale == 'K'){
                new_temp = fahrenheit_to_kelvin(temp);
            } else if (scale == 'K' and new_scale == 'C'){
                new_temp = kelvin_to_celsius(temp);
            } else if (scale == 'K' and new_scale == 'F'){
                new_temp = kelvin_to_fahrenheit(temp);
            } else{
                throw Bad_char{};
            }

            //Output of conversion. E.g: 1 C = 33.8 F
            cout << "\n" << temp << " " << scale << " = " << new_temp << " " << new_scale << "\n";
            
            char key = get_key();
            key = toupper(key);
            check_key(key);

            if (key == 'N'){
                cout << "\nGoodbye!\n";
                break;
            }

            clear_screen();
        }
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

//Next step: Make a list of all temperatures and scales entered in the loop
