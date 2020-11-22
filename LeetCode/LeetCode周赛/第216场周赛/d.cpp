/*
  二分答案
  如果最低能量和消耗能量差值越大的话，我们就要先处理这些
  如果差值相同，那么贪心的考虑的话，我们需要尽可能先处理难处理的，也就是最低能量需求大的
  这样，我们可以先对所有方案按上述规则排序，然后二分答案

*/
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int minimumEffort(vector<vector<int>>& tasks) {
        n = tasks.size();
        sort(tasks.begin(),tasks.end(),[](vector<int> &a,vector<int>& b){
            return (a[1]-a[0]) > (b[1]-b[0]) || ((a[1]-a[0]) == (b[1]-b[0]) && b[1] < a[1]);
        });
        t = tasks;
        int l = 1, r = 1e9;
        
        while(l<r){
            int mid = (l+r)>>1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    bool check(int x){
        bool res = true;
        for(int i = 0; i<n; i++){
            if(x >= t[i][1]){
                x -= t[i][0];   
            }else{
                res = false;
                break;
            }
        }
        return res;
    }
};
