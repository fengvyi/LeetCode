#include <bits/stdc++.h>

using namespace std;

vector <int> longestCommonSubsequence(vector <int> a, vector <int> b) {
    int n = a.size(), m = b.size();
    vector<int>res;
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    int maxlen = 0;
    for(int i = 1; i <= n; i++){
        int tmp = maxlen;
        for(int j = 1; j <= m; j++){
            dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
            maxlen = max(maxlen, dp[i][j]);
        }
    }
    
    int r = n, c = m;
    
    while(res.size() < maxlen){
        if(dp[r][c] == dp[r - 1][c]) r--;
        else if(dp[r][c] == dp[r][c - 1]) c--;
        else{
            res.push_back(a[r - 1]);
            r--;
            c--;
        }
        
    }
    reverse(res.begin(), res.end());    
    return res;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    vector <int> result = longestCommonSubsequence(a, b);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
