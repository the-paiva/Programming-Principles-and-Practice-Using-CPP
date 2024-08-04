#include <iostream>
#include <vector>
using namespace std;

double get_smaller(vector<double> num)
{
    double smaller;

    if (num[0] < num[1])
    {
        smaller = num[0];
    }
    else
    {
        smaller = num[1];
    }

    return smaller;
}

double get_larger(vector<double> num)
{
    double larger;

    if (num[0] > num[1])
    {
        larger = num[0];
    }
    else
    {
        larger = num[1];
    }

    return larger;
}

double get_sum(vector<double> num)
{
    double sum = num[0] + num[1];

    return sum;
}

double get_diff(double larger, double smaller)
{
    double diff = larger - smaller;

    return diff;
}

double get_product(vector<double> num)
{
    double product = num[0] + num[1];

    return product;
}

double get_ratio(double larger, double smaller)
{
    double ratio = larger / smaller;

    return ratio;
}

int main()
{
    vector<double> num(2);

    for (double count; count <= 1; count++)
    {
        cout << "Enter the " << count + 1 << "th value: ";
        cin >> num[count];
    }

    double larger = get_larger(num);
    double smaller = get_smaller(num);
    double sum = get_sum(num);
    double diff = get_diff(larger, smaller);
    double product = get_product(num);
    double ratio = get_ratio(larger, smaller);

    if (num[0] == num[1])
    {
        cout << "\nThe two numbers entered are the same";
    }
    else
    {
        cout << "\nThe smallest number is " << smaller;
        cout << "\nThe largest number is " << larger;
    }

    cout << "\nThe sum of the two numbers is " << sum;
    cout << "\nThe difference of the two numbers is " << diff;
    cout << "\nThe product of the two numbers is " << product;
    cout << "\nThe ratio of the two numbers is " << ratio;
    cout << "\n\nThat is all, bye!\n";
}
