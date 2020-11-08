// time complexity O(E logV)
// space complexity O(v) MinHeap

#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int> 

void primMST(map<int,vector<pii>>& graph,int n)
{
	int total = 0, u,v,weight;
	vector<int> key(n,INT_MAX);
	vector<bool> vis(n,false);

	priority_queue<pii,vector<pii>,greater<pii> >pq;
	key[0]=0;

	pq.push({0,0});

	while(!pq.empty())
	{	
		u = pq.top().second;
		pq.pop();
		if(vis[u])continue;
		vis[u]=true;

		total += key[u];
		
		for(pii k:graph[u])
		{
			v = k.first;
			weight = k.second;

			if(!vis[v] && weight<key[v])
			{
				key[v]=weight;
				pq.push({key[v],v});
			}
		}
	}

	cout<<total;
	
}

int main()
{
	int n,m,a,b,w;
	cin>>n>>m;
	map<int,vector< pair<int,int> >> graph;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		graph[a-1].push_back({b-1,w});
		graph[b-1].push_back({a-1,w});
	}

	primMST(graph,n);
}
