/*
  贪心， 对于较短的高度差我们尽量避免使用梯子
  等价于  ==   将所有的高度差放在堆里，先全部用梯子，如果梯子不够用了，我们可以将堆顶（小根堆）的
  元素即高度差最小的那块的梯子撤掉而是用砖头，这样肯定能到最远
*/
class Solution {
public:

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> h;
        
        int sum = 0;
        for(int i = 1; i<n; i++){
            int d = heights[i] - heights[i-1];
            if(d < 0) continue;
            h.push(d);
            if(h.size() > ladders){
                int t = h.top();
                h.pop();
                sum += t;
            }
            if(sum > bricks){
                return i-1;
            }
        }
        return n-1;
    }
};
