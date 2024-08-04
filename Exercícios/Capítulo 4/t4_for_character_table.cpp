/*Rewrite the character value example from the previous Try this to use a
for-statement. Then modify your program to also write out a table of the
integer values for uppercase letters and digits.*/

#include <iostream>
#include <vector>
using namespace std;

void print_up_alphabet(vector<char> up_alphabet, vector<int> up_value){
    for (int count = 0; count < 26; count++){
        up_alphabet[count] = 'A' + count;
        up_value[count] = up_alphabet[count];

        cout << up_alphabet[count] << "\t" << up_value[count] << endl;
    }
}

void print_low_alphabet(vector<char> low_alphabet, vector<int> low_value){
    for (int count = 0; count < 26; count++){
        low_alphabet[count] = 'a' + count;
        low_value[count] = low_alphabet[count];

        cout << low_alphabet[count] << "\t" << low_value[count] << endl;
    }
}

int main(){
    vector<char> low_alphabet(27);
    vector<char> up_alphabet(27);
    vector<int> low_value(27);
    vector<int> up_value(27);

    print_up_alphabet(up_alphabet, up_value);

    cout << endl;

    print_low_alphabet(low_alphabet, low_value);

    return 0;
}
