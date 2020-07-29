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
int v, e;
const int N = 1e5 + 10;
vector<int> g[N], euler, visited, discovery, levels, segtree, eLevel;

void eulerTour(int u, int &idx, int level)
{
    discovery[u] = idx;
    visited[u] = 1;
    levels[u] = level;
    euler[idx++] = u;
    for (auto &v : g[u])
    {
        if (!visited[v])
        {
            eulerTour(v, idx, level + 1);
            euler[idx++] = u;
        }
    }
}

void eulerLevel()
{
    int m = euler.size();
    for (int i = 0; i < m; i++)
        eLevel[i] = levels[euler[i]];
}

void build(int start, int end, int node = 1)
{
    if (start == end)
    {
        segtree[node] = start;
        return;
    }

    int mid = start + end >> 1;
    build(start, mid, 2 * node);
    build(mid + 1, end, 2 * node + 1);
    int left = segtree[2 * node]; //this will return index
    int right = segtree[2 * node + 1];
    segtree[node] = eLevel[left] <= eLevel[right] ? left : right;
}

//find ans for range(l,r)
int query(int l, int r, int start, int end, int node = 1)
{
    //out of range
    if (r < start || l > end)
        return INT_MAX;

    //complete ooverlap
    if (l >= start && r <= end)
        return segtree[node];

    int mid = start + end >> 1;
    int left = query(l, r, start, mid, 2 * node);
    int right = query(l, r, mid + 1, end, 2 * node + 1);

    if (left == INT_MAX)
        return right;
    if (right == INT_MAX)
        return left;

    int ans = eLevel[left] <= eLevel[right] ? left : right;

    return ans;
}

int LCA(int root, int x, int y)
{
    int m = euler.size();
    x = discovery[x], y = discovery[y];
    if (x > y)
        swap(x, y);
    return query(x, y, 0, m - 1);
}

int main()
{
    cin >> v;
    visited.resize(v), discovery.resize(v), euler.resize(2 * v), levels.resize(v);
    for (int i = 0; i < v - 1; i++)
    {
        int src, dest;
        cin >> src >> dest;

        g[src].PB(dest);
        g[dest].PB(src);
    }
    int index = 0;
    eulerTour(1, index, 0);
    int m = euler.size();
    segtree.resize(4 * m);
    eLevel.resize(m);
    eulerLevel();
    build(0, m - 1);

    int t;
    cin >> t;
    while (t--)
    {
        int type;
        cin >> type;
        int node1, node2;
    
        cin >> node1 >> node2;
        int lca = LCA(1, node1, node2);

    }
    return 0;
}
