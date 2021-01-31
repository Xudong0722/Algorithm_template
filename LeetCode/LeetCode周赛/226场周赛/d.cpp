class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n,vector<bool>(n,0));  //dp[i][j] 表示串i~j是否是一个回文串

        for(int i = n-1; i>=0; i--){
            dp[i][i] = true;
            for(int j = i+1; j<n; j++){
                if(s[i] == s[j]){
                    if(i+1 == j) dp[i][j] = true;
                    if(dp[i+1][j-1]) dp[i][j] = true;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(!dp[0][i]) continue;
            for(int j = i+1; j+1<n; j++){
                if(dp[i+1][j] && dp[j+1][n-1]) return true;
            }
        }
        return false;
    }
};
