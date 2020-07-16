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

struct info
{
    int sum;
    int ans;
    int start_ans;
    int end_ans;

    info(int val = 0) : sum(val), ans(val), start_ans(val), end_ans(val) {}
};

vector<info> tree;

void update(int idx, int val, int node = 1, int start = 0, int end = n - 1)
{
    if (start == idx && end == idx)
    {
        tree[node] = info(val);
        return;
    }
    int mid = start + end >> 1;
    if (idx <= mid)
        update(idx, val, node * 2, start, mid);
    else
        update(idx, val, 2 * node + 1, mid + 1, end);

    auto left = tree[node * 2];
    auto right = tree[2 * node + 1];

    int op1 = left.ans;
    int op2 = right.ans;
    int op3 = left.end_ans + right.start_ans;

    tree[node].sum = left.sum + right.sum;
    tree[node].ans = max(op1, max(op2, op3));
    tree[node].start_ans = max(left.start_ans, left.sum + right.start_ans);
    tree[node].end_ans = max(right.end_ans, left.end_ans + right.sum);
}

signed main()
{
    LL t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        tree.resize(4 * n);
        for (LL i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            update(i, a);
        }
        for (LL i = 0; i < m; i++)
        {
            int idx, v;
            cin >> idx >> v;

            if (i == 0)
                cout << max(tree[1].ans, 0) << "\n";
            update(idx, v);
            cout << max(tree[1].ans, 0) << "\n";
        }
    }
    return 0;
}
