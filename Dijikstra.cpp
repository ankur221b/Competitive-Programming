// Time complexity O(E log V)
// space complexity O(V)


#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define INF 100000000

void dijikstra(map<int, vector<pii> > edges,int src,int dest,int n)
{
    // n - no of vertices
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    vector<int> dis(n+1,INF);

    pq.push({0,src});
    dis[src]=0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
    
        for(auto i:edges[u])
        {
            int v = i.first;
            int weight = i.second;

            if(dis[u]+weight < dis[v])
            {
                dis[v] = dis[u]+weight;
                pq.push({dis[v],v});
            }
        }
    }

}
