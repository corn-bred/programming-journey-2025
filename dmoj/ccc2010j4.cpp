#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

vector<int> findchanges(vector<int> values) {
    vector<int> changes;
    for (int i = 0; i < values.size(); i++) {
        if (i != 0) {
            changes.push_back(values.at(i) - values.at(i-1));
        }
    }
    return changes;
}

int findpattern(vector<int> changes) {
    vector<vector<int>> chunks; // 0 = main chunk, >=1 = side chunks
    int iteration = 0, chunknum = 0;
    
    for (int i = 0; i < changes.size(); i++) {

        //cout << "passed\n";
        //cout << iteration << endl;
        chunks.push_back({0});
        cout << changes.at(i) << endl;
        cout << (chunks.at(0)).at(0) << endl;

        if (changes.at(i) == (chunks.at(0)).at(iteration% (chunks.at(0)).size())) {
            cout << "true\n";

            chunknum = floor( iteration / (chunks.at(0)).size() ) + 1;

            //chunknum++;
            (chunks.at(chunknum)).push_back(changes.at(i));

            iteration++;

        } else {
            //cout << "false\n";

            for (int k = chunknum; k > 0; k--) {

                for (int j = 0; j < (chunks.at(i)).size(); j++) {

                    (chunks.at(k - 1)).push_back( (chunks.at(k)).at(j) );// to collapse all child info to parent
                    
                }
                (chunks.at(k)).erase ( (chunks.at(k)).begin() );
            } 
            (chunks.at(0)).push_back(changes.at(i));
            chunknum = 0;
            //(chunks.at(chunknum)).push_back()
            iteration = 0;
            //
        }
    }
    return ( (chunks.at(0)).size() ) - 1;
}

vector<int> values;

int main () {
    
    string input;
    getline(cin, input);
    stringstream ss(input);

    int num;

    while (ss >> num) {
        values.push_back(num);
    }

    vector<int> changes = findchanges(values);
    
    /*for (int i = changes; i > 0; i--) {
                for (int j = 0; j < (chunks.at(i)).size(); j++) {
                    (chunks.at(i - 1)).push_back( (chunks.at(i)).at(j) );
                }
            }*/
    for (auto x : changes) {
        cout << x << " ";
    }
    cout << endl << findpattern(changes);
    return 0;
}