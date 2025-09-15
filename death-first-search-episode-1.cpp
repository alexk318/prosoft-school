#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();

    map<int, vector<int>> links;
    for (int i = 0; i < n; i++) { links.insert(pair<int, vector<int>>(i, {})); }

    vector<int> gateways;
    gateways.reserve(e);

    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        links[n1].push_back(n2);
        links[n2].push_back(n1);
    }

    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gateways.push_back(ei);
    }

    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();

        vector<int> checked;

        queue<array<int, 2>> q; // Первый элемент сам добавленный узел, а второй элемент - от какого узла добавлен
        auto iter = links[si].begin();
        while (iter != links[si].end()) { q.push({ *iter, si }); iter++; }

        while (find(gateways.begin(), gateways.end(), q.front()[0]) == gateways.end()) {
	        auto iter = links[q.front()[0]].begin();
	        while (iter != links[q.front()[0]].end()) {
		        if (*iter != si && (find(checked.begin(), checked.end(), *iter)) == checked.end()) {
			        q.push({ *iter, q.front()[0]});
		        }
		        iter++;
	        }
		 
	        checked.push_back(q.front()[0]);
	        q.pop();
        }
        
        cout << q.front()[0] << " " << q.front()[1] << endl;
        iter = remove(links[q.front()[0]].begin(), links[q.front()[0]].end(), q.front()[1]);
        links[q.front()[0]].erase(iter, links[q.front()[0]].end());

        iter = remove(links[q.front()[1]].begin(), links[q.front()[1]].end(), q.front()[0]);
        links[q.front()[1]].erase(iter, links[q.front()[1]].end());
    }
}
