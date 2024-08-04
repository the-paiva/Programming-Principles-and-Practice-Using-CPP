#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void show_accepted_units(){
    cout << "\n"
    << "-------------------ACCEPTED UNITS-------------------\n"
    << "|M (Meters)                                        |\n"
    << "|CM (Centimeters)                                  |\n"
    << "|IN (Inches)                                       |\n"
    << "|FT (Feets)                                        |\n"
    << "----------------------------------------------------\n";
}

vector<double> get_num(vector<double> num, int counter){
    double temporary_num;

    cout << "\nEnter the " << counter + 1 << "th number: ";

    while (true){
        cin >> temporary_num;

        if (temporary_num >= 0){
            break;
        }
        else{
            cout << "INVALID VALUE! Enter a number above zero: ";
        }
    }

    num.push_back(temporary_num);

    return num;
}

string get_unit(){
    string unit;

    cout << "Now, enter the unit of the value: ";

    while (true){
        cin >> unit;

        transform(unit.begin(), unit.end(), unit.begin(), ::tolower); //Convert to lowercase

        if (unit == "m" or unit == "cm" or unit == "in" or unit == "ft"){
            break;
        }

        cout << "\nINVALID UNIT!\nEnter one of the accepted units: ";
    }

    return unit;
}

double get_smaller_num(double converted_num, double counter, double smaller_num){
    if ((counter > 0 and converted_num < smaller_num) or counter == 0){
        smaller_num = converted_num;
    }

    return smaller_num;
}

double get_larger_num(double converted_num, double counter, double larger_num){
    if ((counter > 0 and converted_num > larger_num) or counter == 0){
        larger_num = converted_num;
    }

    return larger_num;
}

vector<double> convert_to_meters(vector<double> converted_num, double num, string unit){
    if (unit == "cm"){
        num /= 100;
    }
    else if (unit == "ft"){
        num /= 3.28084;
    }
    else if (unit == "in"){
        num /= 39.3701;
    }

    converted_num.push_back(num);

    return converted_num;
}

double get_sum(double sum, double converted_num, string unit){
    return sum + converted_num;
}

void show_results(double num, double converted_num, string unit, double smaller_num, double larger_num, 
int counter, double sum){
    cout << "\nValue entered: " << num << " " << unit;

    if (unit != "m"){
        cout << "\nValue converted to meters: " << converted_num << " m";
    }
    else{
        cout << "\n" << converted_num << " is already in meters.";
    }

    cout << "\nAmmount of values entered so far: " << counter + 1;

    if (smaller_num != larger_num){
        cout << "\nSmaller value so far: " << smaller_num << " m";
        cout << "\nLarger value so far: " << larger_num << " m";
    }
    else{
        cout << "\n" << converted_num << " m is both the smaller and larger value so far";
    }

    cout << "\nThe sum of all the values so far (in meters): " << sum << " m\n";
}

char get_key_pressed(){
    char key_pressed;

    cout << "\nPress '|' if you want to leave the program, or press any other key to repeat: ";
    cin >> key_pressed;

    return key_pressed;
}

vector<double> sort_values(vector<double> converted_num){
    int counter = 0;
    int size = converted_num.size();
    int auxiliar_num; //Intermediary number used for the change of position of the values

    while (counter < size){
        for (int count = 0; count < size - 1 - counter; count++){
            if (converted_num[count] > converted_num[count + 1]){
                auxiliar_num = converted_num[count];
                converted_num[count] = converted_num[count + 1];
                converted_num[count + 1] = auxiliar_num;
            }
        }

        counter++;
    }

    return converted_num;
}

void end_program(vector<double> converted_num, int counter){
    cout << "\nShowing total numbers entered (converted to meters)\n\n";

    for (int count = 0; count <= counter; count++){
        cout << converted_num[count] << " m\n";
    }

    cout << "\nGoodbye!\n";
}

int main(){
    vector<double> num(0);
    vector<double> converted_num(0);
    char key_pressed;
    int counter = 0;
    double sum = 0;

    while (key_pressed != '|'){
        show_accepted_units();
        num = get_num(num, counter);
        string unit = get_unit();
        converted_num = convert_to_meters(converted_num, num[counter], unit);
        double smaller_num = get_smaller_num(converted_num[counter], counter, smaller_num);
        double larger_num = get_larger_num(converted_num[counter], counter, larger_num);
        sum = get_sum(sum, converted_num[counter], unit);
        show_results(num[counter], converted_num[counter], unit, smaller_num, larger_num, counter, sum);
        key_pressed = get_key_pressed(); //Gets the condition of continuity

        if (key_pressed == '|'){
            converted_num = sort_values(converted_num);
            end_program(converted_num, counter);
            break;
        }

        counter++;
    }

    return 0;
}
