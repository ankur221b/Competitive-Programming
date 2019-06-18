#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 10001
#define MOD 1000000007
#define mod 100000

struct suffix
{
  int index;
  int rank[2];
};

bool cmp(suffix a, suffix b)
{
  if(a.rank[0]==b.rank[0])return a.rank[1]<b.rank[1];
  return a.rank[0]<b.rank[0];
}

void build_suffix(string s, int n)
{
  suffix suffixes[n];

  for(int i=0;i<n;i++)
  {
    suffixes[i].index=i;
    suffixes[i].rank[0] = s[i]-'A';
    if(i+1<n)suffixes[i].rank[1] = s[i+1]-'A';
    else suffixes[i].rank[1] = -1; 
  }

  sort(suffixes,suffixes+n,cmp);

  int map[n];

  for(int k=4;k<2*n;k*=2)
  {
    int curr_rank=0;
    int prev_rank=suffixes[0].rank[0];
    suffixes[0].rank[0]=curr_rank;
    map[suffixes[0].index]=0;

    for(int i=1;i<n;i++)
    {
      if(suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1])
      {
        prev_rank = suffixes[i].rank[0];
        suffixes[i].rank[0] = curr_rank;
      }
      else
      {
        prev_rank = suffixes[i].rank[0];
        curr_rank++;
        suffixes[i].rank[0] = curr_rank;
      }
          map[suffixes[i].index] = i;
    }

    for(int i=0;i<n;i++)
    {
      int next = suffixes[i].index + k/2;
      if(next<n)suffixes[i].rank[1] = suffixes[map[next]].rank[0];
      else suffixes[i].rank[1] = -1; 
    }

    sort(suffixes,suffixes+n,cmp);
  }

  for(int i=0;i<n;i++)
  {
    cout<<suffixes[i].index<<" ";
  }


}

int main()
{
  string s;
  cin>>s;

  build_suffix(s, s.length());

  

  return 0;
}


 



    
  
