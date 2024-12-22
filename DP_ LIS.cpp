#include <bits/stdc++.h>
#define N 1000
#define inf int(1e9)
using namespace std;
int a[N + 2] , vet[N + 2] , dp[N + 2];
int main ()
{
    int n;
    vector<int> x;
    cin >> n;
    for(int i = 1 ;i <= n ;i++)
    {
        cin >> a[i];
    }
    a[0] = -inf ;a[n + 1] = inf;
    dp[0] = 1;dp[1] = 2;
    for(int i = 2; i<=n + 1; i++)
    {
        for(int j =0 ; j<= n ;j++)
        {
            if(a[i] > a[j] && dp[i] <dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                vet[i] = j;
            }
        }
    }
    cout << dp[n+ 1] - 2 << endl;
    for(int i = n +1 ; i > 0 ; i = vet[i])
    {
        x.push_back(a[i]);
    }
    for(int i =x.size() - 1; i > 0 ; i--)
    {
        cout << x[i]  << " ";
    }

}
