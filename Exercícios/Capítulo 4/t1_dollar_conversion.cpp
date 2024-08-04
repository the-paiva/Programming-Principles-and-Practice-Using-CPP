//Create a program that converts yen ('y'), kroner ('k'), and pounds ('p') into dollars.

#include <iostream>
using namespace std;

string get_currency_code(char currency){
    string currency_code;

    if (currency == 'y' or currency == 'Y'){
        currency_code = "JPY";
    } else if (currency == 'k' or currency == 'K'){
        currency_code = "kr$";
    } else{
        currency_code = "GBP";
    }

    return currency_code;
}

double convert_dollar(double value, char currency){
    double dollar;
    
    if (currency == 'y' or currency == 'Y'){
        dollar = value / 149.67;
    } else if (currency == 'k' or currency == 'K'){
        dollar = value / 11.16;
    } else{
        dollar = value * 1.21;
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

    if (value > 0 and (currency == 'y' or currency == 'Y' or currency == 'k' or currency == 'K' or currency == 'p' or currency == 'P')){
        dollar = convert_dollar(value, currency);
        currency_code = get_currency_code(currency);

        cout << "\nValue entered: " << currency_code << " " << value << endl;
        cout << "Value in Dollars: USD " << dollar << endl;
    } else if (value <= 0){
        cout << "\nINVALID VALUE!" << endl;
    } else{
        cout << "\nSorry, i do not recognize this currency." << endl;
    }
    
    return 0;
}
