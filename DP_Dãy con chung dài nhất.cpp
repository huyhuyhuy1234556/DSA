#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
void LCS(int a[], int b[], int m, int n) {
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] +    1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int res[1001];
    int cnt = 0;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            res[cnt++] = a[i-1];
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    for (int k = cnt-1; k >= 0; k--) {
        cout << res[k] << " ";
    }
}

int main() {

    int m , n;
    int a[m] , b[n];
    cin >> m >> n;
    for(int i = 1; i <= m ; i++)
    {
        cin >> a[i];
    }
    for(int i =1; i <= n ; i++)
    {
        cin >> b[i];
    }
    LCS(a, b, m, n);
    return 0;
}
