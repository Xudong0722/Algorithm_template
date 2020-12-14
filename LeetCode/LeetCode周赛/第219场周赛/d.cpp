class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        //贪心
        //每个长方体的长宽高是不固定的，我们将每个长方体按目前的长宽高排序
        //然后对所有的长方体排序，思路：最长上升子序列
        
        int n = c.size();
        for(auto& x: c) sort(x.begin(),x.end());
        
        sort(c.begin(),c.end(),greater<vector<int>>());
        
        vector<int> dp(n+1,0);
        int ans = 0;
        for(int i = 0; i<n; i++){
            dp[i] = c[i][2];
            int x = c[i][0], y = c[i][1], z = c[i][2];
            for(int j = 0; j<i; j++){
                int u = c[j][0], v = c[j][1], w = c[j][2];
                if(x <= u && y <= v && z <= w){
                    dp[i] = max(dp[i],dp[j]+c[i][2]);
                }
            }
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};
