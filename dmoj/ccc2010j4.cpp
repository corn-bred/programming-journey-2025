#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

vector<int> findchanges(vector<int> values) {
    vector<int> changes;
    if (values.size() == 1) { return changes;}
    for (int i = 0; i < values.size(); i++) {
        if (i != 0) {
            changes.push_back(values.at(i) - values.at(i-1));
        }
    }
    return changes;
}

int findpattern(vector<int> changes) {
    if (changes.size() == 0) return 0;
    vector<int> mainchunk, sidechunk; // 0 = main chunk, >=1 = side chunks
    int iteration = 0;
    
    mainchunk.push_back(changes.at(0));

    for (int i = 1; i < changes.size(); i++) {

        //cout << "passed\n";
        //cout << "mainchunk.size(): " << mainchunk.size() << endl;

        if (changes.at(i) == mainchunk.at(iteration % mainchunk.size())) {
            //cout << "true\n";

            //chunknum++;
            sidechunk.push_back(changes.at(i));

            iteration++;

        } else {
            //cout << "false\n";

                for (int j = 0; j < sidechunk.size(); j++) {
                    //cout << "j: " << j << endl;

                    mainchunk.push_back( sidechunk.at(j) );// to collapse all child info to parent
                    
                }
                //cout << "finished\n";
                sidechunk.clear();
            mainchunk.push_back(changes.at(i));
            //(chunks.at(chunknum)).push_back()
            iteration = 0;
            //
        }
    }
    //if (mainchunk.size() == 1) return 0;
    return ( mainchunk.size() );
}



int main () {
    
    string input;
    while(true) {
        vector<int> values;
    getline(cin, input);
    if (input == "0") {
        break;
    }
    stringstream ss(input);

    int num;

    while (ss >> num) {
        values.push_back(num);
    }
    values.erase(values.begin());
    vector<int> changes = findchanges(values);

    cout << findpattern(changes) << endl;
}
    return 0;
}