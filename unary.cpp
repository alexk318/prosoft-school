// https://www.codingame.com/ide/puzzle/unary

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    string message;
    getline(cin, message);

    string mc;

    for (char c : message) {
	    mc += bitset<7>(c).to_string();
    }
    mc += 'x';

    int series = 1;
    char prev = mc[0];

    for (int i = 1; i < mc.size(); i++) {
	    if (mc[i] == prev) {
		    series++;
		    continue;
	    }

	    if (i != 1) { cout << " "; }

	    if (prev == '0') {
	    	cout << "00 " << string(series, '0');
	    }

	    else {
	    	cout << "0 " << string(series, '0');
	    }
	
	    series = 1;
	    prev = mc[i];
    }
}
