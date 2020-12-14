/*
思路： 模拟即可
*/
class Solution {
public:
    int numberOfMatches(int n) {
        int left = n;
        
        int ans = 0;
        while(left > 1){
            if(left%2){
                ans += (left-1)/2;
                left = (left-1)/2+1;
            }else{
                ans += left/2;
                left = left/2;
            }
        }
        return ans;
    }
};
