#include <iostream>
#include <math.h> 
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Defib {
	public:
	Defib(string defib) {
        stringstream s(defib);
        vector<string> data; data.reserve(6);

        while (s.good()) {
            string sub;
            getline(s, sub, ';');
            data.push_back(sub);
        }

        replace(data[4].begin(), data[4].end(), ',', '.');
        replace(data[5].begin(), data[5].end(), ',', '.');

		this->id = stoi(data[0]); this->addr = data[2]; this->phone = data[3];
		this->name = data[1]; this->lon = stof(data[4]); this->lat = stof(data[5]);
		this->lon_r = (stof(data[4]) * 3.1415926536) / 180;
		this->lat_r = (stof(data[5]) * 3.1415926536) / 180;
	}

	int id;
	string name;
	string addr;
	string phone;

	float lon;
	float lat;
	float lon_r;
	float lat_r;

	float dist(float dlon_r, float dlat_r) {
		float x = (dlon_r - this->lon_r) * cos((this->lat_r + dlat_r)/2);
		float y = dlat_r - this->lat_r;
		return sqrt(x * x + y * y) * 6371;
	}

};

int main() {
    string lon;
    cin >> lon; cin.ignore();
    replace(lon.begin(), lon.end(), ',', '.');
    float lon_r = (stof(lon) * 3.1415926536) / 180;
    string lat;
    cin >> lat; cin.ignore();
    replace(lat.begin(), lat.end(), ',', '.');
    float lat_r = (stof(lat) * 3.1415926536) / 180;
    int n;
    cin >> n; cin.ignore();

    vector<Defib> defibs; defibs.reserve(n);

    for (int i = 0; i < n; i++) {
        string defib;
        getline(cin, defib);

        defibs.push_back(Defib(defib));
    }

    auto iter = defibs.begin();
    Defib result = *iter;

    while (iter != defibs.end()) {
	    if (result.dist(lon_r, lat_r) > iter->dist(lon_r, lat_r)) {
		    result = *iter;
	    }
	    iter++;
    }

    cout << result.name << endl;
}
