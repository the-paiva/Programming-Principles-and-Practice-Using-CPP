/*Implement square() without using the multiplication operator; that is, do the
x*x by repeated addition (start a variable result at 0 and add x to it x times).
Then run some version of “the first program” using that square().*/

#include <iostream>
#include <vector>
using namespace std;

int get_square(int num){
    int square = 0;

    for (int count = 0; count <= num; count++){
        square += num;
    }

    return square;
}

int main(){
    int num;

    cout << "\nEnter a integer number: ";
    cin >> num;

    int square = get_square(num);

    cout << "The square of " << num << " is " << square << "." << endl;

    return 0;
}
