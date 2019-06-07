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

struct edge
{
    int src,dest,weight;
};


int m,n,a,b,w,tmp=0;
edge v[10001];
int dist[10001],vis[1001];

int bellman(int src)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=src;j<m;j++)
        {
            vis[j]=1;
            if( dist[v[j].dest] > dist[v[j].src] + v[j].weight && dist[v[j].src]!=INT_MAX)
            {
                dist[v[j].dest] = dist[v[j].src] + v[j].weight;
            }
        }
    }

    for(int i=src;i<m;i++)
    {
        if( dist[v[i].dest] > dist[v[i].src] + v[i].weight && dist[v[i].src]!=INT_MAX)
        {
            return 1;
        }
    }

    return 0;

}

int main()
{
    fast_io;

    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin >> v[i].src >> v[i].dest >> v[i].weight;      
    }

    for(int i=0;i<m;i++)
    {
        if(!vis[i])
        {
            dist[v[i].src]=0;
            tmp=bellman(i);
        }
        if(tmp==1)break;
    }

      
  cout<<tmp;



    



  
}