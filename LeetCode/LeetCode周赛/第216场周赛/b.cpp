class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        int t = k - n;
        
        if(t == 0) return ans;
        int z = t/25;
        int y = t%25;
        for(int i = n-z; i<n; i++){
            ans[i] = 'z';
        }        
        ans[n-z-1] += y;

        return ans;
    }
};
