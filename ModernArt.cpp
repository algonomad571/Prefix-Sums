#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> grid(N + 1, vector<int>(N + 1));

    int MAXC = N * N;

    vector<int> minR(MAXC + 1, INF), minC(MAXC + 1, INF);
    vector<int> maxR(MAXC + 1, -INF), maxC(MAXC + 1, -INF);

    vector<bool> present(MAXC + 1, false);

    int colors = 0;

    // Read grid and compute bounding boxes
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 0) continue;

            int c = grid[i][j];

            if (!present[c]) {
                present[c] = true;
                colors++;
            }

            minR[c] = min(minR[c], i);
            maxR[c] = max(maxR[c], i);
            minC[c] = min(minC[c], j);
            maxC[c] = max(maxC[c], j);
        }
    }

    // Special case:
    // If only one color is visible,
    // every other color could have been painted first.
    if (colors == 1) {
        cout << N * N - 1 << '\n';
        return 0;
    }

    vector<vector<int>> diff(N + 2, vector<int>(N + 2, 0));

    // Add every bounding rectangle
    for (int c = 1; c <= MAXC; c++) {
        if (!present[c]) continue;

        diff[minR[c]][minC[c]]++;
        diff[maxR[c] + 1][minC[c]]--;
        diff[minR[c]][maxC[c] + 1]--;
        diff[maxR[c] + 1][maxC[c] + 1]++;
    }

    // Recover coverage counts
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            diff[i][j] += diff[i - 1][j]
                        + diff[i][j - 1]
                        - diff[i - 1][j - 1];
        }
    }

    vector<bool> impossible(MAXC + 1, false);

    // Any color covered by another rectangle cannot be first
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] == 0) continue;

            if (diff[i][j] > 1)
                impossible[grid[i][j]] = true;
        }
    }

    int ans = 0;

    // Visible colors that are still possible
    for (int c = 1; c <= MAXC; c++) {
        if (present[c] && !impossible[c])
            ans++;
    }

    // Invisible colors could always have been first
    ans += MAXC - colors;

    cout << ans << '\n';

    return 0;
}
