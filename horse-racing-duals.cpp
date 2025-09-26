// https://www.codingame.com/ide/puzzle/horse-racing-duals

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; cin.ignore();

    vector<int> strengths;

    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi; cin.ignore();

        strengths.push_back(pi);
    }

    sort(strengths.begin(), strengths.end());

  int closest = strengths[1] - strengths[0];

  for (int i = 2; i < strengths.size(); i++) {
	  if (strengths[i] - strengths[i-1] < closest) {
		  closest = strengths[i] - strengths[i-1];
	  }
		
}

  cout << closest << endl;
}
