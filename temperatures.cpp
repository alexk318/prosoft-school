#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    int current;

    vector<int> temperatures;
    temperatures.reserve(n);

    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        temperatures.push_back(t);
    }

    auto iter = temperatures.begin();

    if (iter != temperatures.end()) {
	    current = *iter;
	    iter++;
    } else { current = 0; }

    while (iter != temperatures.end()) {
	    if ((abs(*iter) < abs(current)) || (abs(*iter) == abs(current) && *iter > 0)) {
		    current = *iter;
	    }
	    iter++;
    }

    cout << current << endl;
}
