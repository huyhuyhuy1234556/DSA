#include <bits/stdc++.h>
#define N 1000005
using namespace std;
int a[11], dp[N] , vet[N];
int main ()
{
    int n;
    for(int i = 1;i <= 10 ; i++)
    {
        cin >> a[i];
    }
    cin >> n;
    memset(dp,1000000, sizeof(dp));
    memset(vet,0 , sizeof(vet));
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 10 ; j++)
        {
            if(j <= i)
            {
                if(dp[i - j] + a[j] < dp[i])
                {
                    dp[i] = dp[i - j] + a[j];
                    vet[i] = j;
                }
            }
        }
    }
    cout << dp[n] << endl;
    int i = n;
    while(i > 0)
    {
        cout << vet[i] << " " << a[vet[i]] << endl;
        i -= vet[i];
    }
}
