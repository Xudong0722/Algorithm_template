/*
    dp[i][j] 表示当前序列[i,j] 情况下先手和后手的得分差值
    核心： 最坏的情况下最好
    先手A 后手B
    假如先手A当前拿i， 那么当前的最低分差为sum(i+1,j) + min(A-B)
    这里的min(A-B)是[i+1,j]局面下B先手
    我们用num表示前一人拿走i后，后一人面对[i+1,j]局面时他的选择造成的最大分差 即num = dp[i+1][j]
    即num = max(B-A)
    那么有
    min(A-B) = -max(B-A)
    所以先手拿i后的最低得分差是 sum(i+1,j) - dp[i+1][j]
    先手拿j后的最低得分差是 sum(i,j-1) - dp[i][j-1]
    根据最坏的情况下最好的原则
    我们选取这两种选法中最好的那一个即可
*/

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        
        vector<int> s(n+1,0);
        
        for(int i = 1; i<=n; i++){
            s[i] = s[i-1] + stones[i-1];
        }
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int k = 2; k<=n; k++){
            for(int i = 1; i+k-1<=n; i++){
                int j = i+k-1;
                int ti = s[j] - s[i] - dp[i+1][j];
                int tj = s[j-1]-s[i-1] - dp[i][j-1];
                dp[i][j] = max(ti,tj);
            }
        }
        return dp[1][n];
    }
};
