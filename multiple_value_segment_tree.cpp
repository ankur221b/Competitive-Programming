#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ss second
#define MAX 1000001
#define MOD 1000000007
#define INF INT_MAX

// PROBLEM HACKEREARTH - "INCREMENTAL QUERIES"

struct node {
    ll counte = 0;
    ll counto = 0;
    ll max = 0;
    ll sum = 0;
};
node *tree = new node[500000];
void buildTree(ll* arr, ll start, ll end, ll tn) {

    if (end < start)return ;

    if (start == end) {
        if (arr[start] % 2 == 0) {
            tree[tn].counte = 1;
            tree[tn].counto = 0;
            tree[tn].max = arr[start];
            tree[tn].sum = arr[start];
        } else {
            tree[tn].counto = 1;
            tree[tn].counte = 0;
            tree[tn].max = arr[start];
            tree[tn].sum = arr[start];
        }
        return;
    }
    ll mid = (start + end) / 2;
    buildTree(arr, start, mid, tn * 2);
    buildTree(arr, mid + 1, end, tn * 2 + 1);

    tree[tn].counte = tree[tn * 2].counte + tree[tn * 2 + 1].counte;
    tree[tn].counto = tree[tn * 2].counto + tree[tn * 2 + 1].counto;
    tree[tn].max = max(tree[tn * 2].max, tree[tn * 2 + 1].max);
    tree[tn].sum = tree[tn * 2].sum + tree[tn * 2 + 1].sum;
    return;

}
void update(ll* arr, ll start, ll end, ll tn, ll id, ll val) {
    if (start == end) {
        arr[id] = val;
        if (arr[id] % 2 == 0) {
            tree[tn].counte = 1;
            tree[tn].counto = 0;
            tree[tn].max = val;
            tree[tn].sum = val;
        } else {
            tree[tn].counto = 1;
            tree[tn].counte = 0;
            tree[tn].max = val;
            tree[tn].sum = val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    if (id > mid) {
        update(arr, mid + 1, end, 2 * tn + 1, id, val);
    }
    else {
        update(arr, start, mid, 2 * tn, id, val);
    }
    tree[tn].counte = tree[tn * 2].counte + tree[tn * 2 + 1].counte;
    tree[tn].counto = tree[tn * 2].counto + tree[tn * 2 + 1].counto;
    tree[tn].max = max(tree[tn * 2].max, tree[tn * 2 + 1].max);
    tree[tn].sum = tree[tn * 2].sum + tree[tn * 2 + 1].sum;
    return;

}
node query(ll* arr, ll start, ll end, ll tn, ll l, ll r) {
    node result;
    result.counte = 0;
    result.counto = 0;
    result.max = 0;
    result.sum = 0;

    if (start > r || end < l) {
        return result;
    }
    if (start >= l && end <= r) {
        return tree[tn];
    }
    ll mid = (start + end) / 2;
    if (l > mid) {
        return query(arr, mid + 1, end, tn * 2 + 1, l, r);
    } if (r <= mid) {
        return query(arr, start, mid, tn * 2, l, r);
    }

    node left = query(arr, start, mid, tn * 2, l, r);
    node right = query(arr, mid + 1, end, tn * 2 + 1, l, r);

    result.counte = left.counte + right.counte;
    result.counto = left.counto + right.counto;
    result.max = max(left.max, right.max);
    result.sum = left.sum + right.sum;

    return result;



}

int main()
{
    // fast_io;

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif


    ll n, k, t = 1, x, y, q, l, r, c;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> q;
        ll v[n];
        for (int i = 0; i < n; i++)cin >> v[i];

        buildTree(v, 0, n - 1, 1);


        for (int k = 0; k < q; k++)
        {
            cin >> c >> l >> r;


            if (c == 1)
            {
                update(v, 0, n - 1, 1, l - 1, r);
            }
            if (c == 2)
            {
                node ans = query(v, 0, n - 1, 1, l - 1, r - 1);
                ll sum = ((r - l + 1) * ans.max) - ans.sum;
                ll res = 0;
                if (ans.max & 1)
                {
                    sum -= ans.counte;
                    res += ans.counte;
                }
                else
                {
                    sum -= ans.counto;
                    res += ans.counto;
                }
                res += sum / 2;
                cout << res << endl;
            }
        }
    }
}