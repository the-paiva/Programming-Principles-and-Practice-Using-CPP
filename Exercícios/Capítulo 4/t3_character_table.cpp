/*The character 'b' is char('a'+1), 'c' is char('a'+2), etc. Use a loop to write out
a table of characters with their corresponding integer values*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char> alphabet(27);
    vector<int> value(27);
    int count = 0;

    while (count < 26){
        alphabet[count] = 'a' + count;
        value[count] = alphabet[count];

        cout << alphabet[count] << '\t' << value[count] << endl;

        count++;
    }
}
