// https://www.codingame.com/ide/puzzle/logic-gates

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string _and(string s1, string s2);
string _or(string s1, string s2);
string _xor(string s1, string s2);
string nand(string s1, string s2);
string nor(string s1, string s2);
string nxor(string s1, string s2);

int main() {
    int n;
    cin >> n; cin.ignore();

    int m;
    cin >> m; cin.ignore();

    map<string, string> input;
    vector<string> output_names;
    vector<string> output_signals;

    for (int i = 0; i < n; i++) {
        string input_name;
        string input_signal;
        cin >> input_name >> input_signal; cin.ignore();
        input[input_name] = input_signal;
    }

    for (int i = 0; i < m; i++) {
        string output_name;
        string type;
        string input_name_1;
        string input_name_2;
        cin >> output_name >> type >> input_name_1 >> input_name_2; cin.ignore();

        output_names.push_back(output_name);

        if (type == "AND") { output_signals.push_back(_and(input[input_name_1], input[input_name_2])); }
        else if (type == "OR") { output_signals.push_back(_or(input[input_name_1], input[input_name_2])); }
        else if (type == "XOR") { output_signals.push_back(_xor(input[input_name_1], input[input_name_2])); }
        else if (type == "NAND") { output_signals.push_back(nand(input[input_name_1], input[input_name_2])); }
        else if (type == "NOR") { output_signals.push_back(nor(input[input_name_1], input[input_name_2])); }
        else if (type == "NXOR") { output_signals.push_back(nxor(input[input_name_1], input[input_name_2])); }
        else { cout << "INVALID TYPE" << endl; }
    }

    for (int i = 0; i < m; i++) {
        cout << output_names[i] << " " << output_signals[i] << endl;
    }
}

string _and(string s1, string s2) {
	string result;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '-' && s2[i] == '-') { result += '-'; }
		else { result += '_'; }
	}
	return result;
}

string _or(string s1, string s2) {
	string result;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '_' && s2[i] == '_') { result += '_'; }
		else { result += '-'; }
	}
	return result;
}

string _xor(string s1, string s2) {
	string result;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '_' && s2[i] == '_') { result += '_'; }
		else if (s1[i] == '-' && s2[i] == '-') { result += '_'; }
		else { result += '-'; }
	}
	return result;
}

string nand(string s1, string s2) {
	string result;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '-' && s2[i] == '-') { result += '_'; }
		else { result += '-'; }
	}
	return result;
}

string nor(string s1, string s2) {
	string result;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '_' && s2[i] == '_') { result += '-'; }
		else { result += '_'; }
	}
	return result;
}

string nxor(string s1, string s2) {
	string result;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == '_' && s2[i] == '_') { result += '-'; }
		else if (s1[i] == '-' && s2[i] == '-') { result += '-'; }
		else { result += '_'; }
	}
	return result;
}
