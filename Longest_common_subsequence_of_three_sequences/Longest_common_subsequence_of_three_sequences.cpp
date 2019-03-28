#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define MAX 100001
#define MOD 1000000007

int maximum(int a, int b, int c)
{
    return max( max(a,b), c);
}

int solve(int n, int m, int l, vector<int> a, vector<int> b, vector<int> c)
{
    
    vector< vector< vector<int> > > dp(n+1, vector< vector<int> >(m+1, vector<int>(l+1)));

    for(int i=0;i<=n;i++)dp[i][0][0]=0;
    for(int i=0;i<=m;i++)dp[0][i][0]=0;
    for(int i=0;i<=l;i++)dp[0][0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=l;k++)
            {
                if(b[j-1]==a[i-1] && a[i-1]==c[k-1])
                {
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                }
                else dp[i][j][k] = maximum(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);                
            }
            
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    
    return dp[n][m][l];
}

int main() {

    int n,m,k;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++)cin>>b[i];

    cin>>k;
    vector<int> c(k);
    for(int i=0;i<k;i++)cin>>c[i];


    cout<<solve(n, m, k, a, b, c);


return 0;

}
