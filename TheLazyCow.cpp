#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // Maximum value of (x+y) and (x-y+n) is about 2n
    int SZ = 2 * n + 2;

    vector<vector<int>> rot(SZ + 1, vector<int>(SZ + 1, 0));

    // Read grid and rotate coordinates
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;

            int u = i + j - 1;
            int v = i - j + n;

            rot[u][v] += x;
        }
    }

    // 2D Prefix Sum
    vector<vector<int>> pref(SZ + 1, vector<int>(SZ + 1, 0));

    for (int i = 1; i <= SZ; i++) {
        for (int j = 1; j <= SZ; j++) {
            pref[i][j] = rot[i][j]
                       + pref[i-1][j]
                       + pref[i][j-1]
                       - pref[i-1][j-1];
        }
    }

    int ans = 0;

    // Try every starting position
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            int u = i + j - 1;
            int v = i - j + n;

            int x1 = max(1, u - k);
            int y1 = max(1, v - k);

            int x2 = min(SZ, u + k);
            int y2 = min(SZ, v + k);

            int sum = pref[x2][y2]
                    - pref[x1 - 1][y2]
                    - pref[x2][y1 - 1]
                    + pref[x1 - 1][y1 - 1];

            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';
}
