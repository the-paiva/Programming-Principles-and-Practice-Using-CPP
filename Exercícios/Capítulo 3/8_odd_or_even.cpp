/*Write a program to test an integer value to determine if it is odd or
even. As always, make sure your output is clear and complete. In other
words, don’t just output yes or no. Your output should stand alone,
like The value 4 is an even number.*/

#include <iostream>
using namespace std;

string check_num(int num)
{
    string num_type;

    if (num % 2 == 0)
    {
        num_type = "even";
    }
    else
    {
        num_type = "odd";
    }

    return num_type;
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    string num_type = check_num(num);

    cout << num << " is a " << num_type << " number!";
}
