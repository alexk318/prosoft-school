// https://www.codingame.com/ide/puzzle/mime-type

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    int n; // Number of elements which make up the association table.
    cin >> n; cin.ignore();
    int q; // Number Q of file names to be analyzed.
    cin >> q; cin.ignore();

    map<string, string> assoc, assoc_lower;
    vector<string> files; files.reserve(q);

    for (int i = 0; i < n; i++) {
        string ext; // file extension
        string mt; // MIME type.
        cin >> ext >> mt; cin.ignore();

        string ext_lower;
        for (char c : ext) { ext_lower += tolower(c); }

        assoc[ext_lower] = mt;
    }

    for (int i = 0; i < q; i++) {
        string fname;
        getline(cin, fname); // One file name per line.
        files.push_back(fname);
    }

    auto iter = files.begin();

    while (iter != files.end()) {
	    int point_index = iter->find_last_of('.');
	    if (point_index == -1) { cout << "UNKNOWN" << endl; iter++; continue; }

	    string name = iter->substr(0, point_index);
	    string ext = iter->substr(point_index + 1);
        string ext_lower; 
        for (char c : ext) { ext_lower += tolower(c); }

	    if (assoc.count(ext_lower) == 1) { cout << assoc[ext_lower] << endl; }
        else { cout << "UNKNOWN" << endl; }    

	    iter++;
    }
}
