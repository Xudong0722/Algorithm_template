/*
    滑动窗口/双指针
    用一个哈希表维护区间的信息
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,bool> h;
        int ans = 0;
        int sum = 0;
        int n = nums.size();
        queue<int> q;
        
        for(int i = 0; i<n; i++){
            if(q.empty()) {
                q.push(i); 
                h[nums[i]] = true;
                sum += nums[i];
                ans = max(ans,sum);
            }else{
                while(h[nums[i]] == true && !q.empty()){
                    int t = q.front();
                    q.pop();
                    h[nums[t]] = false;
                    sum -= nums[t];
                }
                sum += nums[i];
                h[nums[i]] = true;
                q.push(i);
                ans = max(ans,sum);
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};
