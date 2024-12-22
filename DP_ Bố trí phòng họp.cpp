#include <bits/stdc++.h>
#define N 1000
#define inf int(1e9)
using namespace std;
struct ph{
int x , y;
};
bool cmp(ph a , ph b)
{
    return a.y < b.y;
}
ph a[N + 2];
int vet[N + 2] , dp[N + 2];
int main ()
{
    int n;
    cin >> n;
    vector<ph> x;
    for(int i = 1; i <= n ;i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a+ n , cmp);
    a[0].x = -inf ; a[n + 1].x = inf;
    dp[0] = 1; dp[1] = 2;
    for(int i = 2; i <= n + 1; i++)
    {
        for(int j = 0; j < i ; j++)
        {
            if(a[j].y < a[i].x && dp[i] < dp[j] + 1)
            {
               dp[i] = dp[j] + 1;
               vet[i] = j;
            }
        }
    }
    cout << dp[n + 1] - 2 << endl;
    for(int i = n + 1; i > 0 ; i = vet[i])
    {
        x.push_back(a[i]);
    }
    for(int i = x.size() - 1; i > 0 ; i--)
    {
        cout << x[i].x << " " << x[i].y << " " << endl;
    }
}
