#include <bits/stdc++.h>
using namespace std;
int n,i , j ;
int L[40][40]; int a[40][40];
void xl()
{
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j <= n ;j++)
   {
       if(i==1&& j==1) L[i][j]  = a[i][j];
        else
            L[i][j] = min(L[i - 1][j], L[i][j - 1])+ a[i][j];
        }
    }
}
void in_res()
{
    for(int i= 1 ; i <= n ;i++)
    {
        for(int j= 1; j <= n ; j++){
           cout << L[i][j] << " ";
        cout << endl;
    }

    }
//    cout << L[n][n] << endl;
//    int i = n , j = n;
//    cout << L[i][j] << " ";
}
int main ()
{
    cin >> n;
    for(int i = 1; i <= n ;i++)
    {
        for(int j = 1; j <= n;j++)
        {
            cin >> a[i][j];
        }
    }
    int maxrb = 10000000;
for(int i = 1; i <= n; i++)
{
   L[0][i]=  maxrb;
   L[i][0]= maxrb;
}
    xl();
    in_res();
}
