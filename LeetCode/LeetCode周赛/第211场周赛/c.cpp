/*
  将年龄按从小到大排序后，容易发现
  我们如果想找得分最高的队伍，其实就是在这一个序列中找和最大的单调递增子序列，这里的递增指得分递增，注意不是严格单调递增
  因为年龄是单增的，所以如果所选的队伍得分也是单增的话一定可以保证他们之间没有矛盾
*/

truct A{
    int ae;
    int se;
    bool operator<(const A& W){
        if(ae<W.ae) return true;
        else if(ae == W.ae){
            return se <= W.se;
        }
        return false;
    }
}a[1010];

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int ans = 0;
        
        int n = scores.size();
        for(int i = 0; i<n; i++){
            a[i] = {ages[i],scores[i]};
        }
        
        sort(a,a+n);
        
        vector<int> dp(n,0);
        
        dp[0] = a[0].se;
        for(int i = 1; i<n; i++){
            dp[i] = a[i].se;
            for(int j = 0; j<i; j++){
                if(a[i].se >= a[j].se){
                    dp[i] = max(dp[i],dp[j] + a[i].se);
                }
            }
        }
        
        for(int i = 0; i<n; i++) ans = max(ans,dp[i]);
        return ans;
    }
};
