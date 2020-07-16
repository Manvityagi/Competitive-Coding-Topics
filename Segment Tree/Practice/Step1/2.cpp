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
LL n, m;
LL movex[] = {0, 0, 1, -1};
LL movey[] = {1, -1, 0, 0};
vector<LL> arr, tree;

void build(LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    LL mid = start + end >> 1;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

void update(LL idx, LL val, LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start == idx && end == idx)
    {
        arr[idx] = val;
        tree[node] = val;
        return;
    }

    LL mid = start + end >> 1;
    if (idx <= mid)
        update(idx, val, 2 * node, start, mid);
    else
        update(idx, val, 2 * node + 1, mid + 1, end);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

LL query(LL l, LL r, LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start > r || end < l)
        return LONG_LONG_MAX;

    if (start >= l && end <= r)
        return tree[node];

    LL mid = start + end >> 1;

    LL left = query(l, r, 2 * node, start, mid);
    LL right = query(l, r, 2 * node + 1, mid + 1, end);

    return min(left, right);
}

signed main()
{
    LL t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        arr.resize(n);
        tree.resize(4 * n);
        for (LL i = 0; i < n; i++)
            cin >> arr[i];

        build();
        for (LL i = 0; i < m; i++)
        {
            LL a, b, c;
            cin >> a >> b >> c;

            if (a == 1)
            {
                update(b, c);
            }
            else
            {
                cout << query(b, c - 1) << "\n";
            }
        }
    }
    return 0;
}
