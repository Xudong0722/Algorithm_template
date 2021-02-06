class Solution {
public:
    vector<int> nums;
    
    int maxS(){
        int n = nums.size();
        int f[n];
        f[0] = nums[0];
        int ans = f[0];
        
        for(int i = 1; i<n ;i++)
        {
            f[i] = max(f[i-1]+nums[i],nums[i]);
            ans = max(ans,f[i]);
        }
        
        return ans;
    }
    int maxAbsoluteSum(vector<int>& num) {
        nums = num;
        
        int ans = maxS();
        for(auto &x:num){
            x *= -1;
        }
        nums = num;
        ans = max(ans,maxS());
        return ans;
    }
};
