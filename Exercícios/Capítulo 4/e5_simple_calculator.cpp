/*Write a program that performs as a very simple calculator. Your calculator
should be able to handle the four basic math operations — add, subtract,
multiply, and divide — on two input values. Your program should prompt
the user to enter three arguments: two double values and a character to
represent an operation. If the entry arguments are 35.6, 24.1, and '+', the
program output should be The sum of 35.6 and 24.1 is 59.7.*/

#include <iostream>
#include <vector>
using namespace std;

vector<double> get_double_array(vector<double> array, int ammount){
    double temporary_num;

    for (int count = 0; count < ammount; count++){
        cout << "Enter the " << count + 1 << "th value: ";
        cin >> temporary_num;
        array.push_back(temporary_num);
    }

    return array;
}

void giant_text(){
    cout << "\n------OPERATIONS--------";
    cout << "\n|+                     |";
    cout << "\n|-                     |";
    cout << "\n|*                     |";
    cout << "\n|/                     |";
    cout << "\n------------------------";
}

double calculate_value(char operation, vector<double> value, int ammount){
    double result = value[0];
    
    if (operation == '+'){
        for (int count = 1; count < ammount; count++){
            result += value[count];
        }
    }
    else if (operation == '-'){
        for (int count = 1; count < ammount; count++){
            result -= value[count];
        }
    }
    else if (operation == '*'){
        for (int count = 1; count < ammount; count++){
            result *= value[count];
        }
    }
    else{
        for (int count = 1; count < ammount; count++){
            if (value[count] != 0){
                result /= value[count];
            }
            else{
                result = -0; //WTF?!
                break;
            }
        }
    }

    return result;
}

int main(){
    vector<double> value(0);
    int ammount;
    char operation;

    cout << "How many numbers will be entered? ";
    cin >> ammount;

    //Gets the values
    value = get_double_array(value, ammount);

    //Shows the allowed operations
    giant_text();

    //Gets the operation
    while (true){
        cout << "\nEnter an operation: ";
        cin >> operation;

        if (operation == '+' or operation == '-' or operation == '*' or operation == '/'){
            break;
        }

        cout << "INVALID OPERATION!";
    }

    //Calculates the values, according to the selected operation
    double result = calculate_value(operation, value, ammount);

    //E.g: 1 + 1 = 2
    if (result != -0){
        cout << "\n" << value[0];

        for (int count = 1; count < ammount; count++){
            if (value[count] >= 0){
                cout << " " << operation << " " << value[count];
            } 
            else{
                cout << " " << operation << " " << "(" << value[count] << ")";
            }
        }

        cout << " = " << result;
    }
    else{
        cout << "\nCANNOT DIVIDE BY ZERO!\n";
    }
}

//Next step: Upgrade the input of ammount
