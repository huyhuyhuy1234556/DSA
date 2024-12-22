#include <bits/stdc++.h>
#define N 1000
#define inf int(1e9)
using namespace std;

struct Job {
    int x, y, z;
};

bool cmp(Job a, Job b) {
    return a.y < b.y;
}

Job a[N + 2];
int vet[N + 2], dp[N + 2];

int main () {
    int n;
    cin >> n;
    vector<Job> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a , a + n, cmp);
    a[0].x = -inf; a[n + 1].x = inf;
    dp[0] = 1 ; dp[1] = a[1].z;
    for (int i = 2; i <= n + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j].y <= a[i].x && dp[i] < dp[j] + a[i].z){
                    dp[i] = dp[j] + a[i].z;
                    vet[i] = j;
                }
            }
        }
    for(int i =  1; i<= n ; i++)
    {
        cout << dp[i] << " ";
    }
    cout << dp[n +1] << endl;
    for (int i = n + 1; i > 0; i = vet[i]) {
        x.push_back(a[i]);
    }
    for (int i = x.size() - 1; i > 0; i--) {
        cout << x[i].x << " " << x[i].y << " " << x[i].z << endl;
    }
    return 0;
}
