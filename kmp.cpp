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

void prefix(string s, int* v, int n)
{
  int i=0,j=1;

  v[0]=0;

  while(j<n)
  {
    if(s[i]==s[j])
    {
      v[j]=i+1;
      i++;
      j++;
    }
    else
    {
      if(i>0)
      {
        i=v[i-1];
      }
            else
            {
                v[j]=0;
                j++;
            }
    }
  }
}

vector<int> search(string pat, string txt)
{
    string s = pat + '$' + txt;
    int i=0, j=0,n=s.length();
    vector<int> pos;
    int v[n];    

    prefix(s,v,n);

    for(int i=pat.length();i<n;i++)
    {
        if(v[i]==pat.length())
        {
            pos.push_back(i-pat.length()*2);
        }
    }
    
    return pos;
}


int main()
{
  string pat,txt;
  cin>>pat>>txt;

  vector<int> pos = search(pat,txt);
  for(int i:pos)cout<<i<<" ";

  return 0;
}


 



    
  
