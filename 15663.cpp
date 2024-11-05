#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
set<vector<int>> unique_combinations;
vector<int> input;

void solve(vector<int>& arr, vector<bool>& visited) {
    if (arr.size() == m) {
        unique_combinations.insert(arr);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] || (i > 0 && input[i] == input[i - 1] && !visited[i - 1])) continue;

        visited[i] = true;
        arr.push_back(input[i]);
        solve(arr, visited);
        arr.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());

    vector<int> arr;
    vector<bool> visited(n, false);
    solve(arr, visited);

    for (const auto& comb : unique_combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << '\n';
    }

    return 0;
}
