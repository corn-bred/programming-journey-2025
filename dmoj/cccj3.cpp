#include <string>
#include <vector>
#include <iostream>

using namespace std;

int houses;
vector<int> spacing;
string onoroff;

int find(int i, string &bin) {
  for (int j = 1;j < houses; j++) {
    if (bin[i + j] == '1' || bin[i - j] == '1') {
      return j;
    }
  }
  return -1;
}

int addall(vector<int> x) {
  int sum = 0;
  for (int x: spacing) {
    sum += x;
  }
  return sum;
}

int main() {
  cin >> houses;
  cin >> onoroff;
  for (int i = 0; i < houses; i++) {
    if (onoroff[i] == '0') {
      spacing.push_back(find(i, onoroff));
      cout << find(i, onoroff) << endl;
    } else if (onoroff[i] == '1') {
      spacing.push_back(0);
      cout << 0 << endl;
    }
  }
  cout << addall(spacing) << endl;
  return 0;
}