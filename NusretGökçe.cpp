#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64 m;
    cin >> n >> m;

    vector<int64> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Left -> Right
    for (int i = 1; i < n; i++) {
        a[i] = max(a[i], a[i - 1] - m);
    }

    // Right -> Left
    for (int i = n - 2; i >= 0; i--) {
        a[i] = max(a[i], a[i + 1] - m);
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n";

    return 0;
}
