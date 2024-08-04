/*Write a program that prompts the user to enter some number of pennie (1-cent coins),
nickel (5-cent coins), dime (10-cent coins), quarter (25-cent coins),
half dollars (50-cent coins), and one-dollar coins(100-cent coins).
Query the user separately for the number of each size
coin, e.g., “How many pennie do you have?” Then your program should
print out something like this:
You have 23 pennie.
You have 17 nickel.
You have 14 dime.
You have 7 quarter.
You have 3 half dollars.
The value of all of your coins is 573 cents.
Make some improvements: if only one of a coin is reported, make the
output grammatically correct, e.g., 14 dime and 1 dime (not 1 dime).
Also, report the sum in dollars and cents, i.e., $5.73 instead of 573 cents.*/

#include <iostream>
using namespace std;

int calculate_cents(int pennie, int nickel, int dime, int quarter, int half_dollar, int one_dollar){
    return pennie + (nickel * 5) + (dime * 10) + (quarter * 25) + (half_dollar * 50) + (one_dollar * 100);
}

void print_results(int coin_ammount, string coin_name){
    if (coin_ammount == 1){
        cout << "\nYou have 1 " << coin_name << ".";
    } 
    else if (coin_ammount > 1){
        cout << "\nYou have " << coin_ammount << " " << coin_name << "s.";
    } 
    else{
        cout << "\nYou do not have " << coin_name << "s.";
    }
}

int set_zero(int coin_ammount){
    if (coin_ammount < 0){
        coin_ammount = 0;
    }

    return coin_ammount;
}

double convert_to_dollar(int total_cents){
    double converted_cent = total_cents;
    double total_dollars = converted_cent / 100;

    return total_dollars;
}

int main(){
    int pennie, nickel, dime, quarter, half_dollar, one_dollar;

    cout << "How many pennies do you have? ";
    cin >> pennie;

    pennie = set_zero(pennie);

    cout << "How many nickels do you have? ";
    cin >> nickel;

    nickel = set_zero(nickel);

    cout << "How many dimes do you have? ";
    cin >> dime;

    dime = set_zero(dime);

    cout << "How many quarters do you have? ";
    cin >> quarter;

    quarter = set_zero(quarter);

    cout << "How many coins of a half dollar do you have? ";
    cin >> half_dollar;

    half_dollar = set_zero(half_dollar);

    cout << "How many coins of one dollar do you have? ";
    cin >> one_dollar;

    one_dollar = set_zero(one_dollar);
    
    print_results(pennie, "pennie");
    print_results(nickel, "nickel");
    print_results(dime, "dime");
    print_results(quarter, "quarter");
    print_results(half_dollar, "half dollar coin");
    print_results(one_dollar, "one dollar coin");
    
    int total_cents = calculate_cents(pennie, nickel, dime, quarter, half_dollar, one_dollar);
    double total_dollars = convert_to_dollar(total_cents);
    
    cout << "\n\nYou have a total of " << total_cents << " cents.";
    cout << " That means you have $" << total_dollars << "." << endl;

    return 0;
}
