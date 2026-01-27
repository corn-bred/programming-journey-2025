#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int x, y, xvelo, yvelo, c, r;

int main () {
    string input;
    getline(cin, input);
    stringstream sinput(input);

    sinput >> c;
    sinput >> r;
    do {
        getline(cin, input);
        stringstream sinput(input);

        sinput >> xvelo;
        sinput >> yvelo;
        if (xvelo + x > c) {x = c - xvelo;}
        if (xvelo + x < 0) {x = 0 - xvelo;}
        x += xvelo;
        if (yvelo + y > r) {y = r - yvelo;}
        if (yvelo + y < 0) {y = 0 - yvelo;}
        y += yvelo;
        if (xvelo != 0 || yvelo != 0) cout << x << ' ' << y << endl;
    } while (xvelo != 0 || yvelo != 0);
    
    return 0;
}