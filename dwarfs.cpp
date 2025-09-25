// https://www.codingame.com/ide/puzzle/dwarfs-standing-on-the-shoulders-of-giants

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void dfs(map<int, vector<int>> links, vector<int> checked, int v, int step, int& max_step);

int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();

    map<int, vector<int>> links;
    set<int> members;
    set<int> values;

    for (int i = 0; i < n; i++) {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y; cin.ignore();

        links[x].push_back(y);
        members.insert(x); members.insert(y);
        values.insert(y);
    }

    set<int> roots;

    set_difference(members.begin(), members.end(), values.begin(), values.end(), 
        inserter(roots, roots.end()));

    vector<int> checked;
    int steps = 0;

    for (int r : roots) {
        dfs(links, checked, r, 2, steps);
    }

    cout << steps << endl;
}

void dfs(map<int, vector<int>> links, vector<int> checked, int v, int step, int& max_step) {
    checked.push_back(v);

    for (int e : links[v]) {
        if (find(checked.begin(), checked.end(), e) == checked.end()) {
            
            if (step > max_step) { max_step = step; }
            
            dfs(links, checked, e, step + 1, max_step);
        }
    }

}
