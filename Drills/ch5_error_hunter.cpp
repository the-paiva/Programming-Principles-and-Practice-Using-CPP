#include <iostream>
#include <vector>
using namespace std;

int main(){
    try{
        string anything;

        cout << "Type anything: ";
        cin >> anything;

        cout << "Success!\n";

        return 0;
    }
    catch (exception &e){
        cerr << "erro: " << e.what() << '\n';
        return 1;
    }
    catch (...){
        cerr << "Oops: unknown exception!\n";
        return 2;
    }
}

//Next step: 25.
