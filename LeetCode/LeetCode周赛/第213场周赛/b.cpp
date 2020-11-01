/*
  dp[i][1] 表示以第i个位置为止， 元音a结尾的方案数
  dp[i][2] 表示到第i个位置为止， 元音e结尾的方案数
  ...
  则 dp[i][j] = sum of dp[i-1][1~j]
*/
class Solution {
public: 
    vector<vector<int>> dp;
    int countVowelStrings(int n) {
        dp = vector<vector<int>> (n+1,vector<int>(6,0));
        
        dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = 1;
        for(int i = 2; i<=n; i++){
            for(int j = 1; j<=5; j++)
                for(int k = 1; k<=j; k++){
                    dp[i][j] += dp[i-1][k];
                }
        }
        
        return dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5];
    }
};
