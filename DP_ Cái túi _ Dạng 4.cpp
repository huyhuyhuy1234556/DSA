#include <bits/stdc++.h>
using namespace std;
int a[101] , b[101] ,dp[10001] , vet[10001], s1[10001];
int main ()
{
    int n , W;
    cin >> n >> W;
    for(int i = 1; i <= n; i++)
    {
     cin >> a[i] >> b[i];
    }
    memset(dp,0,sizeof(dp));
    memset(vet,0,sizeof(vet));
    dp[0] = 0;
    for(int i = 1; i<= n; i++)
    {
        for(int j = a[i] ; j<= W; j++)
        {
            if(dp[j] < dp[j - a[i]] + b[i] ||  dp[j] == 0)
            {
                dp[j] = dp[j - a[i]] + b[i];
                vet[j] = i;
            }
    }
    }
  int i = n , j = W;
  while(i > 0 && j > 0)
  {
      if(dp[j] != dp[j - a[i]]+b[i])
      {
          i--;
      }
      else
      {
          s1[i]++;
          j -= a[i];
      }
  }
    for(int i = 1; i <= n ; i++)
    {
        cout << s1[i] << " ";
    }
}
