#include "bits/stdc++.h"
using namespace std;
int dp[1001][1001];
void LCS(string s , string s1 , int n)
{
    memset(dp , 0 , sizeof(dp));
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= n;j++)
        {
            if(s[i - 1] == s1[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    cout << n - dp[n][n];
}
int main ()
{
    string s;
    cin >> s;
    int cnt = s.size();
    string s1 = s;
    reverse(s1.begin() , s1.end());
    LCS(s ,s1, cnt);
}
