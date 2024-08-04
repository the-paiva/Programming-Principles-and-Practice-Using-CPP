/*Write a program that converts spelled-out numbers such as “zero” and
“two” into digits, such as 0 and 2. When the user inputs a number, the
program should print out the corresponding digit. Do it for the values 0,
1, 2, 3, and 4 and write out not a number I know if the user enters some-
thing that doesn’t correspond, such as stupid computer!*/

#include <iostream>
using namespace std;

int get_digit(string spelled_num){
    int digited_num;

    if (spelled_num == "zero"){
        digited_num = 0;
    }
    else if (spelled_num == "one"){
        digited_num = 1;
    }
    else if (spelled_num == "two"){
        digited_num = 2;
    }
    else if (spelled_num == "three"){
        digited_num = 3;
    }
    else if (spelled_num == "four"){
        digited_num = 4;
    }
    else{
        digited_num = -1;
    }

    return digited_num;
}

int main(){
    string spelled_num;

    cout << "Enter a number, between 0 and 4, in it`s spelled form (lower case): ";
    cin >> spelled_num;

    int digited_num = get_digit(spelled_num);

    if (digited_num == -1){
        cout << "Sorry, i don`t recognize this number!";
    }
    else{
        cout << "Digited form: " << digited_num;
    }

    return 0;
}
