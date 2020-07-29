#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfStones function below.
string gameOfStones(int n)
{
    vector<int> dp(n);
    for (int i = 1; i <= n; i++){
        if (n == 2 || n == 3 || n == 5) dp[i] = 1;
        if (n == 1 || n == 4) dp[i] = 2;
    }
    for (int i = 6; i <= n; i++){
        if(dp[i-2] == 2 || dp[i-3] == 2 || dp[i-5] == 2) dp[i] = 1;
        else dp[i] = 2;
    }
    if(dp[n] == 1) return "first";
    return "second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
