/*
  因为排队的学生会一直轮换，所以出现了无法吃午餐的情况只可能是当前的午餐剩下的所有学生都不喜欢
*/
class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& san) {
        int n = s.size();  
        int ans = n;  
        int cnt1 = 0, cnt0 = 0;
        for(int x:s){
            if(x == 1) cnt1++;
            else cnt0 ++;
        }
        for(int x:san){
            if(x == 1){
                if(cnt1){
                    cnt1--;
                    ans --;
                }else break;
            }else{
                if(cnt0){
                    cnt0--;
                    ans --;
                }else break;
            }
        }
        return ans;
    }
};
