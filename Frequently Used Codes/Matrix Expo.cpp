#include<bits/stdc++.h>
#define int long long
#define vi vector<int> 
#define vvi vector<vector<int>>
using namespace std;
int n,k;

const int mod = 1e9+7;

int m[102][102];
int res[102][102];
void multiply(int a[102][102], int b[102][102]){
    int c[102][102];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            c[i][j] = 0;
            for(int k = 0; k < n; ++k)c[i][j]+=a[i][k]*b[k][j]%mod;
            c[i][j] %= mod;
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            a[i][j] = c[i][j];
}

void power(int a[102][102], int n){
    if(n < 2)return;
    power(a,n>>1);
    multiply(a,a);
    if(n%2 == 1)
        multiply(a,m);
}

void solve(){
    cin >> n >> k;
    vi arr(n);
    for(auto &i: arr)cin >> i;
    if(k == 1)return void(cout << n);
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(__builtin_popcountll(arr[i]^arr[j]) % 3 == 0)m[i][j] = 1,res[i][j] = 1;
            else m[i][j] = 0,res[i][j] = 0;
        }

    }
    power(res,k-1);
    int ans = 0;
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < n; ++j){
            ans+=res[i][j];
            ans%=mod;
        }
    }
    cout << ans%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}