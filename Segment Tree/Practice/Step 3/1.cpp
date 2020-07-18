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

void update(int idx, int node = 1, int start = 1, int end = n)
{

    if (start == idx && end == idx)
    {
        tree[node] = 1;
        return;
    }

    int mid = start + end >> 1;
    if (idx <= mid)
        update(idx, 2 * node, start, mid);
    else
        update(idx, 2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int l, int r, int node = 1, int start = 1, int end = n)
{
    if (l > end || r < start)
        return 0;

    if (start >= l && end <= r)
        return tree[node];

    int mid = start + end >> 1;
    int left = query(l, r, 2 * node, start, mid);
    int right = query(l, r, 2 * node + 1, mid + 1, end);
    return left + right;
}

signed main()
{
    cin >> n;
    tree.resize(5 * n);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        cout << query(p[i] + 1, n) << " ";
        update(p[i]);
    }
}