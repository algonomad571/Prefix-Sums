#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    s = " " + s;

    vector<vector<int>> pref(n + 1, vector<int>(26));

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        pref[i][s[i] - 'a']++;
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        if (l == r) {
            cout << "Yes\n";
            continue;
        }

        int distinct = 0;
        for (int c = 0; c < 26; c++)
            if (pref[r][c] - pref[l - 1][c] > 0)
                distinct++;

        if (s[l] != s[r] || distinct >= 3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
