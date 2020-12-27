class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        
        int last = 0;
        double ans = 0;
        
        for(int i = 0;i<n; i++){
            int st = max(customers[i][0],last);
            ans += (st + customers[i][1] - customers[i][0]);
            last = st + customers[i][1];
        }
        
        return ans/n;
    }
};
