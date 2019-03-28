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

vector<int> trace_path(int n, int m, vector<int> a, vector<int> b, vector< vector<int> > dp)
{
    int i = n, j = m;
    
    vector<int> path;

    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j-1]+1)
        {
            path.pb(a[i-1]); 
            i--;
            j--;
                 
        }
        else if(dp[i][j-1]>dp[i-1][j])
        {
            j--;            
        }
        else
        {
            i--;            
        }
        
        
    }
    //for(int i:path)cout<<i<<" ";
    return path;
}

pair<int, vector<int> > solve(int n, int m, vector<int> a, vector<int> b)
{
    //int dp[n+1][m+1];
    vector< vector<int> > dp(n+1, vector<int>(m+1));

    for(int i=0;i<=m;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[j-1]==a[i-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    
    vector<int> path = trace_path(n,m,a,b,dp);
    
    return {dp[n][m], path};
}

int main() {

    int n,m;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++)cin>>b[i];

    pair<int, vector<int> > result = solve(n,m,a,b);

    cout<<result.ff;
    


return 0;

}
