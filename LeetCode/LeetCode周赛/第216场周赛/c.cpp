/*
 前缀和
 对于每一个位置的数，如果删除了，只会影响他后面的数，这个位置后面的奇数位变成偶数位
 偶数位变成奇数位，只要利用前缀和求出这两段的和比较即可

*/
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> od(n+1,0),ev(n+1,0);
        ev[0] = nums[0];
        
        for(int i = 1; i<n; i++){
            if(i % 2) {
                od[i] = od[i-1] + nums[i];
                ev[i] = ev[i-1];
            }else {
                ev[i] = nums[i] + ev[i-1];
                od[i] = od[i-1];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            if(i == 0){
                if(od[n-1] == ev[n-1]-ev[0]) ans ++;
                continue;
            }
            if(ev[i-1]+od[n-1]-od[i] == od[i-1]+ev[n-1]-ev[i]){
                ans ++;
            }
        }
        
        return ans;
    }
};
