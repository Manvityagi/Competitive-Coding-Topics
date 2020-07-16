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
vector<LL> arr;
vector<pair<LL, LL>> tree;

void build(LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start == end)
    {
        tree[node] = MP(arr[start], 1);
        return;
    }
    LL mid = start + end >> 1;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    LL minval = min(tree[2 * node].F, tree[2 * node + 1].F);
    LL cnt;
    if (minval == tree[2 * node].F && minval == tree[2 * node + 1].F)
        cnt = tree[2 * node].S + tree[2 * node + 1].S;
    else
        cnt = minval == tree[2 * node].F ? tree[2 * node].S : tree[2 * node + 1].S;
    tree[node] = MP(minval, cnt);
}

void update(LL idx, LL val, LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start == idx && idx == end)
    {
        arr[idx] = val;
        tree[node] = MP(val, 1);
        return;
    }
    LL mid = start + end >> 1;

    if (idx <= mid)
        update(idx, val, 2 * node, start, mid);
    else
        update(idx, val, 2 * node + 1, mid + 1, end);

    LL minval = min(tree[2 * node].F, tree[2 * node + 1].F);
    LL cnt;
    if (minval == tree[2 * node].F && minval == tree[2 * node + 1].F)
        cnt = tree[2 * node].S + tree[2 * node + 1].S;
    else
        cnt = minval == tree[2 * node].F ? tree[2 * node].S : tree[2 * node + 1].S;
    tree[node] = MP(minval, cnt);
}

pair<LL, LL> query(LL l, LL r, LL node = 1, LL start = 0, LL end = n - 1)
{
    if (l > end || r < start)
        return MP(LONG_LONG_MAX, 0);

    if (start >= l && end <= r)
        return tree[node];

    LL mid = start + end >> 1;

    auto left = query(l, r, 2 * node, start, mid);
    auto right = query(l, r, 2 * node + 1, mid + 1, end);

    if (left.F == right.F)
    {
        auto ans = MP(left.F, left.S + right.S);
        return ans;
    }
    else if (left.F < right.F)
        return left;

    return right;
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
                auto ans = query(b, c - 1);
                cout << ans.F << " " << ans.S << "\n";
            }
        }
    }
    return 0;
}
