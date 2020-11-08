// time complexity O(E+V)
// space complexity O(V)

void dfs(int src,stack<int>& s,int *vis,vector<int> adj[])
{
    vis[src]=1;
    for(int i:adj[src])
    {
        if(!vis[i])dfs(i,s,vis,adj);
    }
    s.push(src);
}

void dfs2(int src,stack<int>& s,int *vis,vector<vector<int>>& adj)
{
    vis[src]=1;
    for(int i:adj[src])
    {
        if(!vis[i])dfs2(i,s,vis,adj);
    }
}

int kosaraju(int n, vector<int> adj[])
{
    // Your code here
    stack<int> s;
    
    int vis[n+1]={0},c=0;
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])dfs(i,s,vis,adj);
    }
    
    for(int i=0;i<=n;i++)vis[i]=0;
    
    vector<vector<int>> revadj(n+1);
    
    for(int i=0;i<n;i++)
    {
        for(int j:adj[i])revadj[j].push_back(i);
    }
    
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        
        if(!vis[node])
        {
            c++;
            dfs2(node,s,vis,revadj);
        }
    }
    return c;

}
