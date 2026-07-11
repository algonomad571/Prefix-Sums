#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<long long, long long> freq;

  long long pref = 0;
  long long ans = 0;

  freq[0] = 1; // Empty prefix

  for (int i = 0; i < n; i++) {
    pref += a[i];
    pref %= n;

    // Handle negative remainders
    if (pref < 0)
      pref += n;

    ans += freq[pref];
    freq[pref]++;
  }

  cout << ans << '\n';

  return 0;
}