#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define MAX 100001
#define MOD 1000000007
 
int main()
{
  int n,maxi=-1,start,st,end;
  cin>>n;

  string s;
  cin>>s;

  int dp[n][n];

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)dp[i][j]=false;
  }

  for(int i=0;i<n;i++)dp[i][i]=true;

    start = 0; 
    for (int i = 0; i < n-1; ++i) 
    { 
        if (s[i] == s[i+1]) 
        { 
            dp[i][i+1] = true; 
            start = i; 
            maxi = 2; 
        } 
    }

  for(int l=2;l<=n;l++)
  {
    for(int st=0;st<n-l+1;st++)
    {
      int end = st+l-1;

      if(dp[st+1][end-1]==true && s[st]==s[end])
      {
        dp[st][end]=true;

        if(l > maxi)
        {
          start=st;
          maxi=l;
        }
      }
    }
  }

  /*for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)cout<<dp[i][j]<<" ";
    cout<<endl;
  }*/

  
  for(int i=start;i<=start+maxi-1;i++)cout<<s[i];
    



return 0;
 
}