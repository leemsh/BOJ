#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;
        int n = a;
        unordered_map<int, int> factor_count;

        for (int j = 2; j * j <= n; j++) {
            while (n % j == 0) {
                factor_count[j]++;
                n /= j;
            }
        }
        if (n > 1) factor_count[n]++;
        int result = 1;

        for (const auto& factor : factor_count) {
            if (factor.second % 2 == 1) {
                result *= factor.first;
            }
        }
        cout << "#" << i + 1 << " " << result << '\n';
    }
    return 0;
}
