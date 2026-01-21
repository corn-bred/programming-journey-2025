#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<string> words = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};
int main() {
    int w;
    cin >> w;
    vector<int> filled, filled2;
    vector<vector<int>> arraywords;
    arraywords.resize(50);
    filled.resize(50);
    filled2.resize(50);
    int j = 0;
    for (int i = 0; i < 6; i++) {
        if (filled2.at(j) + words[i].length() <= w) {

            (arraywords.at(j)).push_back(i);

            filled2.at(j) += words[i].length();
            filled.at(j) += words[i].length();

            if (filled2.at(j) + 1 <= w) {
                filled2.at(j)++;
            }

        } else {
            //cout << filled.at(j) << endl;
            j++;
            (arraywords.at(j)).push_back(i);

            filled2.at(j) += words[i].length();
            filled.at(j) += words[i].length();

            if (filled2.at(j) + 1 <= w) {
                filled2.at(j)++;
            }

        }

    }

    //cout << filled.at(1) << endl;
    //cout << j << endl;
    int spacing, extras, extrasTOUSE;
    for (int i = 0; i <= j; i++) {
        if (((arraywords.at(i)).size() - 1) > 0) {
            spacing = floor((w - filled.at(i)) / ((arraywords.at(i)).size() - 1));
            extras = (w - filled.at(i)) % ((arraywords.at(i)).size() - 1);
        
        } else {
            spacing = w - filled.at(i);
            extras = 0;
        }
        extrasTOUSE = extras;
        //cout << spacing << "\t" << extras << "\n";
        
        for (int k = 0; k < (arraywords.at(i)).size(); k++) {

            

            cout << words.at((arraywords.at(i)).at(k));

            if ((k < (arraywords.at(i)).size() - 1 )||((arraywords.at(i)).size() - 1 <= 0)) {
                for (int ind = 0; ind < spacing; ind++) cout << ".";
            }
            if (extrasTOUSE > 0) {cout << "."; extrasTOUSE--;}
            
            
        }
        cout << "\n";
    }

    //cout << "FINISHED\n";
    return 0;
}