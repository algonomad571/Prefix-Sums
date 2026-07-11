#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        ll pref = 0;
        ll ans = 0;

        map<ll, ll> mp;
        mp[0] = 1;

        for (int i = 1; i <= n; i++) {
            pref += s[i-1] - '0';

            ll key = pref - i;

            ans += mp[key];
            mp[key]++;
        }

        cout << ans << "\n";
    }
}

