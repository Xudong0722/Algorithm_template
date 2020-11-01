/*
  参考题解：https://leetcode-cn.com/problems/kth-smallest-instructions/solution/di-k-tiao-zui-xiao-zhi-ling-by-zerotrac2/
  组合数的问题，这篇题解说的很明白了。
*/

const int N = 31;
int c[N][N];


class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int h = destination[1];  //answer中H的个数
        int v = destination[0];  //answer中V的个数
        
        string ans = "";
        for(int i = 0; i<=30; i++){
            for(int j = 0; j<=i; j++){
                if(!j) c[i][j] = 1;
                else c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
        int cnt = h+v;
        for(int i = 0; i<cnt; ++i){
            if(h>0){
                int d = c[h+v-1][h-1];
                if(k>d){
                    ans += 'V';
                    v--;
                    k -= d;
                }else{
                    ans += 'H';
                    h--;
                }
            }else{
                ans += 'V';
                v--;
            }
        }
        return ans;
    }
};
