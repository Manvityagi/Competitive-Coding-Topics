#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n, m;
vector<LL> tree, arr;
//store max number in range in tree node 
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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

LL query(LL x, LL node = 1, LL start = 0, LL end = n - 1)
{
    //base case
    if (start == end)
    {
        if (arr[start] >= x)
            return start;
        else
            return -1;
    }

    int leftmax = tree[2 * node];
    int rightmax = tree[2 * node + 1];

    int mid = start + end >> 1;
    if (leftmax >= x)
        return query(x, 2 * node, start, mid);

    return query(x, 2 * node + 1, mid + 1, end);
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
            LL a, b, c;
            cin >> a;
            if (a == 1)
            {
                cin >> b >> c;
                update(b, c);
            }
            else
            {
                LL x;
                cin >> x;
                auto ans = query(x);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
