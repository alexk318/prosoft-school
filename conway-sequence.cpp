// https://www.codingame.com/ide/puzzle/conway-sequence

#include <iostream>
#include <string>

using namespace std;

int main() {
    int r;
    cin >> r; cin.ignore();
    int l;
    cin >> l; cin.ignore();

	  int n = 1;
    string line = to_string(r) + " 0";
	  string nextline;

	  string current;
	  string seeked;
	  int count;

	  while (n != l) {
		  nextline = "";
		  current = "";
		  seeked = "";
		  count = 0;

		  for (char c : line) {

			  if (c == '0') {
				  nextline += ' ';
				  nextline += to_string(count);
				  nextline += ' ';
				  nextline += seeked;
			  }

			  else if (c != ' ') {
				  current += c;
			  }

			  else {
				  if (seeked == "") {
					  seeked = current;
					  count = 1;
				  }

				  else if (seeked == current) {
					  count += 1;
				  }

				  else if (seeked != current) {
					  nextline += ' ';
					  nextline += to_string(count);
					  nextline += ' ';
					  nextline += seeked;
					  seeked = current;
					  count = 1;

				  }

				  current = "";
			  }

		  }

		  line = nextline + " 0";
		  n++;
	  }

	  if (l == 1) { cout << to_string(r) << endl; }
	  else {
		  nextline.erase(0, 1); 
		  cout << nextline << endl; 
	  }
}

