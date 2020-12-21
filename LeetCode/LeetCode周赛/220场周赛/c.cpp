/*
    暴力的话是N^2的dp，
    通过转移方程可以看出来我们只会遍历前面一段区间的状态的最大值
    所以可以使用单调队列优化
*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> a(n+1);
        
        for(int i = 1; i<=n; i++){
            a[i] = nums[i-1];
        }
        vector<int> dp(n+1,0);
        
        dp[1] = a[1];
        
        int hh = 0, tt = 0;
        vector<int> q(n+1,0);
        q[0] = 1;
        for(int i = 2; i<=n; i++){
            if(q[hh] < i-k) hh++;
            dp[i] = dp[q[hh]] + a[i];
            while(hh<=tt && dp[q[tt]] <= dp[i]) tt--;
            q[++tt] = i;
        }
        return dp[n];
    }
};
