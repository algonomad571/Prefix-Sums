#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<vector<bool>> isPal(n, vector<bool>(n, false));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (len == 1)
                isPal[i][j] = true;
            else if (len == 2)
                isPal[i][j] = (s[i] == s[j]);
            else
                isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            if (i == j)
                dp[i][j] = 1;
            else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1];

                if (i + 1 <= j - 1)
                    dp[i][j] -= dp[i + 1][j - 1];

                dp[i][j] += isPal[i][j];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << dp[l][r] << "\n";
    }

    return 0;
}
