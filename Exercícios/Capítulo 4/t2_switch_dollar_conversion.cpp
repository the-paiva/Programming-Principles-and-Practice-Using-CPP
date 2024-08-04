/*Rewrite your currency converter program from the previous Try this to use a
switch-statement.*/

#include <iostream>
using namespace std;

string get_currency_code(char currency){
    string currency_code;

    switch (currency){
        case 'y': case 'Y':
            currency_code = "JPY";
            break;
        case 'k': case 'K':
            currency_code = "kr$";
            break;
        default:
            currency_code = "GBP";
            break;
    }
    
    return currency_code;
}

double convert_dollar(double value, char currency){
    double dollar;

    switch (currency){
        case 'y': case 'Y':
            dollar = value / 149.67;
            break;
        case 'k': case 'K':
            dollar = value / 11.16;
            break;
        default:
            dollar = value * 1.21;
            break;
    }

    return dollar;
}

int main(){
    double value, dollar;
    char currency;
    string currency_code;

    cout << "Currency conversions availables\n" << endl;
    cout << "Yen(y)\nKroner(k)\nPounds(p)\n" << endl;
    cout << "Enter a value, followed by the respective currency (y, k or p): ";
    cin >> value >> currency;

    switch (currency){
        case 'y': case 'Y': case 'k': case 'K': case 'p': case 'P':
            if (value > 0){
                dollar = convert_dollar(value, currency);
                currency_code = get_currency_code(currency);

                cout << "\nValue entered: " << currency_code << " " << value << endl;
                cout << "Value in Dollars: USD " << dollar << endl;
            } else{
                cout << "\nINVALID VALUE!" << endl;
            }
            break;
        default:
            cout << "\nSorry, i do not recognize this currency!" << endl;
            break;
    }

    return 0;
}
