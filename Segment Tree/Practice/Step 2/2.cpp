#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n, m;
vector<LL> tree, arr;
void update(LL idx, LL val, LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start == idx && end == idx)
    {
        tree[node] = val;
        arr[idx] = val;
        return;
    }
    LL mid = start + end >> 1;
    if (idx <= mid)
        update(idx, val, 2 * node, start, mid);
    else
        update(idx, val, 2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

LL query(LL k, LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start == end)
        return start;

    LL left_ones = tree[2 * node];
    LL right_ones = tree[2 * node + 1];

    LL mid = start + end >> 1;
    if (k < left_ones)
        return query(k, 2 * node, start, mid);
    else
        return query(k - left_ones, 2 * node + 1, mid + 1, end);
}

signed main()
{
    LL t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        tree.resize(4 * n);
        arr.resize(n);
        for (LL i = 0; i < n; i++)
        {
            cin >> arr[i];
            update(i, arr[i]);
        }
        for (LL i = 0; i < m; i++)
        {
            LL a, b;
            cin >> a >> b;
            if (a == 1)
            {
                update(b, !arr[b]);
            }
            else
            {
                auto ans = query(b);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
