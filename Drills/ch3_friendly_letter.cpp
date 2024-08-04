#include <iostream>
#include <cstdlib>
using namespace std;


void write_gender_word(char friend_gender)
{
    if (friend_gender == 'm' or friend_gender == 'M')
    {
        cout << "him ";
    }
    else if (friend_gender == 'f' or friend_gender == 'F')
    {
        cout << "her ";
    }
}


void write_age_phrase(int friend_age)
{
    if (friend_age < 17 or (friend_age > 17 and friend_age < 70))
    {
        cout << "Next year, you will be " << friend_age + 1 << " years old. \nThe age is coming, right?";
    }
    else if (friend_age == 17)
    {
        cout << "Next year, you will be able to vote. \nAlways remember to choose wisely, ok?";
    }
    else
    {
        cout << "I hope you are enjoying your retirement.";
    }
}


void write_letter(string first_name, string friend_name, char friend_gender, int friend_age, string user_name)
{
    cout << "\nDear, " << first_name << ". \nIs everything all right with you? \nI hope yes, miss you!\n"
    << "Have you seen " << friend_name << "? \nI miss ";

    write_gender_word(friend_gender);
    
    cout << "too. \n";

    write_age_phrase(friend_age);

    cout << "\nSee you soon, my friend. \nBye! \n\nYours sincerely, " << user_name << "...\n";
}


void make_angry_exit()
{
    cout << "\nStop playing around, you moron! No more letters for you!\n";

    exit(0);
}


void check_gender(char friend_gender)
{
    if (friend_gender != 'm' and friend_gender != 'M' and friend_gender != 'f' and friend_gender != 'F')
    {
        make_angry_exit();
    }
}


void check_age(int friend_age)
{
    if (friend_age < 0 or friend_age > 110)
    {
        make_angry_exit();
    }
}


int main()
{
    string user_name, first_name, friend_name;
    char friend_gender;
    int friend_age;

    cout << "Enter your name: ";
    cin >> user_name;
    cout << "Enter the name of the person you want to write: ";
    cin >> first_name;
    cout << "Enter the age of the person you want to write: ";
    cin >> friend_age;

    check_age(friend_age);

    cout << "Enter the name of the another friend: ";
    cin >> friend_name;
    cout << "Enter the gender of the another friend: ";
    cin >> friend_gender;

    check_gender(friend_gender);
    write_letter(first_name, friend_name, friend_gender, friend_age, user_name);
    
    return 0;
}
