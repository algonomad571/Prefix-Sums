#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long x;
  cin >> n >> x;

  vector<long long> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  map<long long, long long> freq;

  long long ans = 0;
  long long pref = 0;

  freq[0] = 1;

  for (int i = 0; i < n; i++) {
    pref += a[i];

    ans += freq[pref - x];

    freq[pref]++;
  }

  cout << ans << '\n';

  return 0;
}