#include <iostream>
#include <string>

using namespace std;

int findS(
    string word //The word that has B and S
    , int index //index for the B
) {
    for (int i = index; i < word.length(); i++) {
        if (word[i] == 'S') {return i;}
    }
    return -1;
}

bool monkeyword(string word) {
    char beforeX, afterX;
    for (int i = 0; i < word.length(); i++) {
        if (i + 1 < word.length()) {
            afterX = word.at(i + 1);
        } else {
            afterX = '\0';
        }
        if (word.at(i) == 'S') break;
        if (!(word.at(i) == 'N' && beforeX == 'A' && afterX) || !(word.at(i) == 'A'))
        beforeX = word.at(i);
    }
    return true;
}

bool isMonkeyWord(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word.at(i) == 'B') findS(word, i);
    }
}

int main() {
    /*string word;
    while (word != "X") {
        cin >> word;

    }*/
    string test = "ANAN";
    cout << test << ", " << monkeyword(test); 
    return 0;
}