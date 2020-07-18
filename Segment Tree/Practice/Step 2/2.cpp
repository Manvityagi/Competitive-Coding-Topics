
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
LL n;
vector<LL> tree, ones;

void update(LL idx, LL val, LL node = 1, LL start = 0, LL end = n - 1)
{
    if (start == idx && end == idx)
    {
        tree[node] = val;
        ones[idx] = val;
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
    //base case
    if (start == end)
        return start;

    LL left_ones = tree[2 * node];
    LL right_ones = tree[2 * node + 1];

    LL mid = start + end >> 1;
    if (k < left_ones)
        return query(k, 2 * node, start, mid);
    
        return query(k - left_ones, 2 * node + 1, mid + 1, end);
}
signed main()
{
    cin >> n;
    vector<LL> arr(n);
    tree.resize(4 * n);
    vector<LL> ans(n);
    ones.resize(n);
    fill(ones.begin(), ones.end(), 1);
    for (LL i = 0; i < n; i++)
    {
        cin >> arr[i];
        update(i, ones[i]);
    }

    //for(LL i = 1; i <= 9; i++) cout<< tree[i] << " ";
    //      cout << "\n\n";

    for (LL i = n - 1; i >= 0; i--)
    {
        LL k = i - arr[i];

        ans[i] = query(k);
        // cout << "found " << k << " at " << ans[i] << "\n";
        update(ans[i], 0);
        // for(LL i = 0; i < n; i++) cout<< ones[i] << " ";
        // cout << "\n";
    }

    for (auto a : ans)
        cout << a + 1 << " ";
}
