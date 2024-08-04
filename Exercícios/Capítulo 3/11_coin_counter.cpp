/*Write a program that prompts the user to enter some number of pennies (1-cent coins), 
nickels (5-cent coins), dimes (10-cent coins), quarters (25-cent coins), 
half dollars (50-cent coins), and one-dollar coins (100-cent coins). 
Query the user separately for the number of each size coin, 
e.g., “How many pennies do you have?” Then your program should print out 
something like this:
You have 23 pennies.
You have 17 nickels.
You have 14 dimes.
You have 7 quarters.
You have 3 half dollars.
The value of all of your coins is 573 cents.
Make some improvements: if only one of a coin is reported, make the
output grammatically correct, e.g., 14 dimes and 1 dime (not 1 dimes).
Also, report the sum in dollars and cents, i.e., $5.73 instead of 573 cents.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> input_values(vector<string> coin_name){
    vector<int> coin_ammount(6);

    for (int count = 0; count <= 5; count++){
        cout << "How many " << coin_name[count] << "s do you have? ";
        cin >> coin_ammount[count];

        if (coin_ammount[count] < 0){
            coin_ammount[count] = 0;
        }
    }

    return coin_ammount;
}

double calculate_cents(vector<int> coin_ammount){
    vector<int> coin_value = {1, 5, 10, 25, 50, 100};
    double total_cents;

    for (int count = 0; count <= 5; count++){
        coin_ammount[count] *= coin_value[count];
        total_cents += coin_ammount[count]; 
    }

    return total_cents;
}

double convert_to_dollar(double total_cents){
    double total_dollars = total_cents / 100;

    return total_dollars;
}

void print_results(vector<int> coin_ammount, vector<string> coin_name, double total_cents, double total_dollars){
    for (int count = 0; count <= 5; count++){
        if (coin_ammount[count] == 1){
            cout << "\nYou have 1 " << coin_name[count] << ".";
        }
        else if (coin_ammount[count] > 1){
            cout << "\nYou have " << coin_ammount[count] << " " << coin_name[count] << "s.";
        }
        else{
            cout << "\nYou do not have " << coin_name[count] << "s.";
        }
    }
    
    cout << "\n\nYou have a total of " << total_cents << " cents.";
    cout << " That means you have $" << total_dollars << "." << endl;
}

int main(){
    vector<int> coin_ammount(6);
    vector<string> coin_name = {"pennie", "nickel", "dime", "quarter", "half dollar coin", "one dollar coin"};
    
    coin_ammount = input_values(coin_name);

    double total_cents = calculate_cents(coin_ammount);
    double total_dollars = convert_to_dollar(total_cents);

    print_results(coin_ammount, coin_name, total_cents, total_dollars);

    return 0;
}
