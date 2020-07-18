
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define loop(i, a, b) for (LL i = a; i < b; i++)
int n;
vector<int> tree;

void update(int idx, int val = 0, int node = 1, int start = 0, int end = n - 1)
{
    if (start == idx && end == idx)
    {
        tree[node] = 0;
        return;
    }

    int mid = start + end >> 1;

    if (idx <= mid)
        update(idx, val, 2 * node, start, mid);
    else
        update(idx, val, 2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int k, int node = 1, int start = 0, int end = n - 1)
{
    //base case
    if (start == end)
        return start;

    //no of 1s in left & right subtree
    int left = tree[2 * node];
    int right = tree[2 * node + 1];

    int mid = start + end >> 1;
    if (k <= left) //yahi aana chahiye equality i think
        return query(k, 2 * node, start, mid);

    return query(k - left, 2 * node + 1, mid + 1, end);
}
signed main()
{
    cin >> n;
    vector<int> arr(n);
    tree.resize(4 * n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = query(i - arr[i] + 1);
        cout << ans[i] << " ";
        update(ans[i]);
    }
}
