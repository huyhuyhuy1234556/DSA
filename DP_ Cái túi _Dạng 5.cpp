#include <bits/stdc++.h>
#define N 1002
using namespace std;
int dp[N][N];
int u[N], v[N];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> u[i] >> v[i];
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if(u[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - u[i]] + v[i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
