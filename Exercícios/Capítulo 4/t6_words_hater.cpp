/*Write a program that “bleeps” out words that you don’t like; that is, you
read in words using cin and print them again on cout. If a word is among a
few you have defined, you write out BLEEP instead of that word. Start with
one “disliked word” such as: string disliked = “Broccoli”;*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//Comparation between a string and a vector<string>, making replacements, if necessary
bool compare_string(string compared_string, vector<string> compared_array, string error_message, bool equality){
    for (int count = 0; count < compared_array.size(); count++){
        if (compared_string == compared_array[count]){
            cout << error_message;
            equality = true;
            break;
        }
    }

    return equality;
}

//Gets an uppercase word, adding it to a vector
vector<string> get_up_array_string(vector<string> word, int counter, string phrase, string error_message){
    string temporary_word;
    bool equality = false;
    
    while (true){
        cout << phrase;
        cin >> temporary_word;

        transform(temporary_word.begin(), temporary_word.end(), temporary_word.begin(), ::toupper);
        compare_string(temporary_word, word, error_message, equality);

        if (equality == false){
            word.push_back(temporary_word);
            break;
        }
    }

    return word;
}

//Gets the key of continuity in a loop
char get_key(string phrase){
    char key_pressed;

    while (true){
        cout << phrase;
        cin >> key_pressed;
        key_pressed = toupper(key_pressed);

        if (key_pressed == 'Y' or key_pressed == 'N'){
            break;
        }

        cout << "\nINVALID CHARACTER! ";
    }

    return key_pressed;
}

//Iteration of a string array inside a determined text layout
void iterate_with_header(string title, vector<string> word){
    cout << "\n------------------------------------------------------";
    cout << "\n|" << title;
    cout << "\n------------------------------------------------------";

    for (int count = 0; count < word.size(); count++){
        cout << "\n|" << word[count];
    }

    cout << "\n------------------------------------------------------\n";
}

//Display the final procedures of the program
void end_program(vector<string> allowed_word, int counter){
    iterate_with_header("WORDS ENTERED", allowed_word);

    cout << "\nGoodbye!\n";
}

int main(){
    vector<string> bleeped_word(0);
    vector<string> allowed_word(0);
    int counter = 0;
    char key_pressed;

    //Gets the bleeped words, doing all the needed process
    while (true){
        bleeped_word = get_up_array_string(bleeped_word, counter, "\nEnter a word to be bleeped: ", 
        "THIS NUMBER HAS ALREADY BEEN ENTERED! ");
        key_pressed = get_key("Do you wish to enter another bleeped word? Y/N: ");

        if (key_pressed == 'N'){
            break;
        }

        counter++;
    }

    counter = 0;

    iterate_with_header("BLEEPED WORDS", bleeped_word);

    //Allows the user to write any word, except the disliked ones
    while (true){
        allowed_word = get_up_array_string(allowed_word, counter, "\nEnter any word, except the bleeped ones: ", 
        "BLEEP! ");
        key_pressed = get_key("Do you wish to enter another word? Y/N: ");

        if (key_pressed == 'N'){
            counter = 0;
            end_program(allowed_word, counter);
            break;
        }

        counter++;
    }

    return 0;
}
