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
#define MAX 100001
#define MOD 1000000007
#define mod 100000




int main()
{
  fast_io;
    int n,m,a,b,w;
    pii node;
    cin>>n>>m;

    map< int,vector<int> > v;
    map< pii, int > weight;
    map<int,bool> vis;
    map<int,int> dist;
    priority_queue<pii, vector<pii>, greater<pii> > q;


    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        v[a].push_back(b);
        weight[{a,b}]=w;
    
    }

    cin >> a >> b;

    for(int i=1;i<=n;i++)
    {
        dist[i]=INT_MAX;
        vis[i]=0;
    }

    dist[a]=0;


    q.push({dist[a],a});

    while(!q.empty())
    {
        node = q.top();
        q.pop();
        

        for(int i:v[node.ss])
        {
            if( dist[node.ss] + weight[{node.ss,i}] < dist[i])
            {
              dist[i] = dist[node.ss] + weight[{node.ss,i}];
              q.push({dist[i],i});
            }
        }

    }


    
    if(dist[b]==INT_MAX)cout<<-1;
    else cout<<dist[b];








    



  
}