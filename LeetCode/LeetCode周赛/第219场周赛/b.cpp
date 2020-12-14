class Solution {
public:
    int minPartitions(string n) {
        int m = n.size();
        int ans = n[0]-'0';
        
        for(int i = 1; i<m; i++){
            int t = n[i]-'0';
            if(t > ans){
                ans = t;
            }
        }
        
        return ans;
    }
};
