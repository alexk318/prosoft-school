// https://www.codingame.com/ide/puzzle/there-is-no-spoon-episode-1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{

    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();

    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    vector<string> rows;
    rows.reserve(height);

    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line); // width characters, each either 0 or .
        rows.push_back(line);
    }

    for (int y = 0; y < height; y++) {
	    for (int x = 0; x < width; x++) {
		
		    if (rows[y][x] == '0') {
			    int right_x, right_y, bottom_x, bottom_y;
		    	right_x = right_y = bottom_x = bottom_y = -1;

			    for (int i = 1; x + i <= width - 1; i++) {
				    if (rows[y][x + i] == '0') {
					    right_x = x + i;
					    right_y = y;
					    break;
				    }
          		}

          		for (int i = 1; y + i <= height - 1; i++) {
				    if (rows[y + i][x] == '0') {
					    bottom_x = x;
					    bottom_y = y + i;
					    break;
				    }
          		}

			    cout << x << ' ' << y << ' ' << right_x << ' ' << right_y << ' ' << bottom_x << ' ' << bottom_y << endl;
			}
		}
	}
}
