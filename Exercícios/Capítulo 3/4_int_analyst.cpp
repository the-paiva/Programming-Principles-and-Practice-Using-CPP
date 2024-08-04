#include <iostream>
#include <vector>
using namespace std;

int get_smaller(vector<int> num)
{
    int smaller;

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

int get_larger(vector<int> num)
{
    int larger;

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

int get_sum(vector<int> num)
{
    int sum = num[0] + num[1];

    return sum;
}

int get_diff(int larger, int smaller)
{
    int diff = larger - smaller;

    return diff;
}

int get_product(vector<int> num)
{
    int product = num[0] + num[1];

    return product;
}

int get_ratio(int larger, int smaller)
{
    int ratio = larger / smaller;

    return ratio;
}

int main()
{
    vector<int> num(2);

    for (int count; count <= 1; count++)
    {
        cout << "Enter the " << count + 1 << "th value: ";
        cin >> num[count];
    }

    int larger = get_larger(num);
    int smaller = get_smaller(num);
    int sum = get_sum(num);
    int diff = get_diff(larger, smaller);
    int product = get_product(num);
    int ratio = get_ratio(larger, smaller);

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
