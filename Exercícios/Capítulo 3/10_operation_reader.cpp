/*Write a program that takes an operation followed by two operands and
outputs the result. For example:
+ 100 3.14
* 4 5
Read the operation into a string called operation and use an
if-statement to figure out which operation the user wants, for example,
if (operation=="+"). Read the operands into variables of type double.
Implement this for operations called +, –, *, /, plus, minus, mul, and div
with their obvious meanings.*/

#include <iostream>
#include <vector>
using namespace std;

bool check_operation(string operation){
    if (operation == "+" or operation == "-" or operation == "*" or operation == "/"){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string operation;
    vector<double> operand(2);

    cout << "+: Addition\n-: Subtraction\n*: Multiplication\n/: Division\n\n";
    cout << "Enter one of the operation symbols above: ";
    cin >> operation;

    if (check_operation(operation) == true){
        for (int count = 0; count < 2; count++){
            cout << "Enter the " << count + 1 << "th operand (number): ";
            cin >> operand[count];
        }

        cout << "Reading: " << operation << " | " << operand[0] << " | " << operand[1] << endl;
    }
    else{
        cout << "Invalid operator!\n";
    }
    
    return 0;
}
