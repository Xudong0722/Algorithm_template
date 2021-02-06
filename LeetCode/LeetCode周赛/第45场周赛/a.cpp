class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> h(110,0);
        for(auto x:nums){
            h[x] ++;
        }
        int ans = 0;
        for(int i = 1; i<=100; i++){
            if(h[i] == 1) ans += i;
        }
        return ans;
    }
};
