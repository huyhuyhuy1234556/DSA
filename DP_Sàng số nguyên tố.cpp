#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6;

int prime[maxn + 1];

void sang()
{
    for(int i = 0 ; i <= maxn;i++)
    {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i  <= sqrt(maxn);i++)
    {
        if(prime[i])
        {
            for(int j = i * i ; j <= maxn ; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
int f[1000001];
int main ()
{
    sang();
    f[0] = 0;
    f[1] = 0;
    int cnt = 0;
    for(int i = 2 ; i <= 1000000 ;i++)
    {
        if(prime[i])
            cnt++;
            f[i] = cnt;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int l , r;
        cin >> l >> r;
        if(l == 0)
        cout << f[r] << endl;
        else
            cout << f[r] - f[l - 1] << endl;
    }
}
