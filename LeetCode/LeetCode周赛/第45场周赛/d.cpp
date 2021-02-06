class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[1] < b[1];
    }
    vector<vector<int>> a;
    int maxValue(vector<vector<int>>& e, int k) {
        int n = e.size();
        vector<vector<int>> dp(n+10,vector<int>(k+10,0));  //dp[i][j] 表示前i个会议中参加k个的最大值
        a.push_back({-1,-1,-1});
        for(auto &x:e) a.push_back(x);
        sort(begin(a),end(a),cmp);
        
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=k; j++){
                dp[i][j] = dp[i-1][j];
                int l = 0, r = i-1;
                while(l<r){
                    int mid = (l+r+1)>>1;
                    if(a[mid][1] < a[i][0]) l = mid;
                    else r = mid-1;
                }
                dp[i][j] = max(dp[i][j],dp[l][j-1]+a[i][2]);
            }
        }
        return dp[n][k];
    }
};
