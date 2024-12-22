#include <bits/stdc++.h>
#define N 1001
using namespace std;
int  a[N] , b[N] , n , k , v[N][N] , dp[N][N] , vet[N];
int sum(int i) {
    int res = 0;
    for(int j = 1; j <= i; j++) {
        res += v[j][j];
    }
    return res;
}
int main ()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] = abs(a[j] - b[i]);
        }
    }

memset(dp,1000000000, sizeof(dp));
for(int i = 1; i <= k; i++)
{
    for(int j = 1; j <= n; j++)
    {
        if(i == j)
        {
            dp[i][j] = sum(i);
        }
        else if(i < j)
        {
            dp[i][j] = min(dp[i - 1][j - 1] + v[i][j] , dp[i][j - 1]);
        }
    }
}
cout << dp[k][n] << endl;
int i = k, j = n;
while(i > 0 && j > 0)
{
    if(dp[i][j] == dp[i][j - 1] && v[i][j] > 0)
    {
       vet[i] = j - 1;
       j--;
    }
    else
    {
       vet[i] = j;
       i--;
       j--;
    }
}
for(int i = 1; i <= k ; i++)
{
    cout << i << " " << vet[i] << endl;
}
}
