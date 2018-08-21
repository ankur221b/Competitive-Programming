#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define MAX 500000

ll tree[4*MAX];
ll lazy[4*MAX];

// Building the segment tree

void build(int start,int end,int node,int *v)
{
	if(end < start)return; //out of range

	if(start==end)
	{
		tree[node]=v[start]; //initialise the value
        return;
	}

	int mid = (start+end) >> 1;

	build(start,mid,2*node,v); //left child
	build(mid+1,end,2*node+1,v); //right child

	tree[node] = tree[2*node]+tree[2*node+1]; //root value

}

// Increment value in range [l, r] by val

void update(int start, int end, int node, int l, int r, int val)
{
    if(start>end)return; //out of range

	if(lazy[node]!=0)
	{
		tree[node] += (end-start+1)*lazy[node]; //updating the node 

		if(start!=end)
		{
			lazy[2*node] += lazy[node]; //marking child as lazy
			lazy[2*node+1] += lazy[node]; // marking child as lazy
		}

		lazy[node]=0; //reset the node
	}

	if(end<l || start>r)return; //this segment is out of range

	if(l<=start && end<=r) //this segment is fully within range
	{
		tree[node]+=(end-start+1)*val; 
	
		if(start!=end) // if current node is not leaf node
		{
                    lazy[2*node]+=val;
                    lazy[2*node+1]+=val;
		}

		lazy[node]=0;

		return;
	}

	int mid = (start+end) >> 1;

	update(start,mid,2*node,l,r,val); // update left child
	update(mid+1,end,2*node+1,l,r,val); // update right child

	tree[node] = tree[2*node] + tree[2*node+1]; // update root value
	
}

// query to get sum of elements in range [l, r]

ll query(int start, int end, int node, int l, int r)
{
    if(start>end || end<l || start>r)return 0; // out of range

	if(lazy[node]!=0)
	{
		tree[node] += (end-start+1)*lazy[node]; //updating the node

		if(start!=end)
		{
			lazy[2*node] += lazy[node]; // marking child as lazy
			lazy[2*node+1] += lazy[node]; // marking child as lazy
		}

		lazy[node]=0; //reset the node
	}

	if(l<=start && end<=r) //this segment is fully within range
	{
		return tree[node];
	}

	int mid = (start+end) >> 1;

	ll p1=query(start,mid,2*node,l,r); //query left child
	ll p2=query(mid+1,end,2*node+1,l,r); //query right child

	return (p1+p2); //return the sum

}


int main() {

    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));

    int n=10;
    int v[n];

    for(int i=0; i<n; i++)v[i]=1;
    
    build(0, n-1, 1, v);
    
    update(0,n-1,1,4,8,2);  // Incrementing the range [4, 8] by 2
    update(0,n-1,1,2,6,5);   // Incrementing the range [2, 6] by 5
    update(0,n-1,1,3,6,3);  // Incrementing the range [3, 6] by 3

    cout << query(0,n-1,1,3,8);  //Get the sum of elements in range [3, 8]

    
return 0;
}
