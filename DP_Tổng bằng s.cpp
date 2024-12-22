#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], dp[MAXN], vet[1001][1001];
int main() {
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(vet, 0, sizeof(vet));
    dp[0] = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = s  ; j >= a[i] ; j--)
        {
            if(dp[j - a[i]] == 1)
            {
                dp[j] = 1;
                vet[i][j] = 1;
            }
        }
    }
    if(dp[s])
    {
        vector<int> res;
        int i = n, j = s;
        while(j > 0 && i > 0)
        {
            if(vet[i][j] == 1)
            {
                res.push_back(a[i]);
                j -= a[i];
            }
            i--;
        }
        reverse(res.begin(), res.end());
        for(int i = 0 ; i < res.size() ; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
