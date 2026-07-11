#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pref(n), suff(n);

    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = gcd(pref[i - 1], a[i]);

    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suff[i] = gcd(suff[i + 1], a[i]);

    int ans = 1;

    for (int i = 0; i < n; i++) {
        int cur;

        if (i == 0)
            cur = suff[1];
        else if (i == n - 1)
            cur = pref[n - 2];
        else
            cur = gcd(pref[i - 1], suff[i + 1]);

        ans = max(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}