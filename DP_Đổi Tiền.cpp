#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dp[10001], vet[10001], a[101], s1[101];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 101, sizeof(dp));
    memset(vet, 0, sizeof(vet));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= m; j++) {
            if (dp[j - a[i]] + 1 < dp[j]) {
                dp[j] = dp[j - a[i]] + 1;
                vet[j] = i;
            }
        }
    }
    cout << dp[m] << endl;
    int j = m;
    while (j > 0) {
        s1[vet[j]]++;
        j -= a[vet[j]];
    }
    for (int i = 1; i <= n; i++) {
        cout << s1[i] << " ";
    }
    return 0;
}
