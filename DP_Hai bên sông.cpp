#include <bits/stdc++.h>

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+2804;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

using namespace std;
const int MAXN = 1001;
int dp[MAXN][MAXN], a[MAXN][MAXN], q[MAXN][MAXN];
void LCS(int a[][MAXN], int n) {
    memset(dp, 0, sizeof(dp));
    memset(q, 0, sizeof(q));
    for(int i = 1; i <= n*2 ; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        q[u][v] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(q[i][j] == 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int res = dp[n][n];
    cout << res << endl;
    vector<pair<int,int>> x;
    int i = n , j = n;
    while(i > 0 && j > 0)
    {
        if(q[i][j] == 1)
        {
            x.push_back(m_k(i , j));
            i--;
            j--;
        }
        else if(q[i - 1][j] >= q[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i = x.size() - 1; i >= 0 ; i--)
    {
        cout << x[i].first << " " << x[i].second << endl;
    }
}
int main() {
    int n;
    cin >> n;
    LCS(a, n);
    return 0;
}
