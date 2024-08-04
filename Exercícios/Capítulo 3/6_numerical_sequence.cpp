/*Write a program that prompts the user to enter three integer values, and
then outputs the values in numerical sequence separated by commas. So,
if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
values are the same, they should just be ordered together. So, the input
4 5 4 should give 4, 4, 5*/

#include <iostream>
#include <vector>
using namespace std;

void checar_iguais(vector<int> num){
    int num_reserva;

    for (int count; count <= 2; count++){
        for (int count2 = count; count2 <= 2; count2++){
            if (count < 2 and num[count] == num[count + 1]){
                num[count + 1];
            }
        }
    }
}

int main(){
    vector<int> num(3);

    cout << "Enter three integer numbers (separated by spaces): ";

    for (int count = 0; count <= 2; count++){
        cin >> num[count];
    }

    for (int count = 0; count <= 1; count++){
        cout << num[count] << ", ";
    }

    cout << num[2];
}
