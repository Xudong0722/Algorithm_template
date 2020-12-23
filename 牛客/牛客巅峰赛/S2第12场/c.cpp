/*
  一道非常巧妙的思维题。
  对于一对音符组合，如果都弹奏效果+z，都不谈奏效果-z，弹奏其中一个没有额外加成
  可以做这样一个转化：
  先将答案减去z，再对一个音符组合的x和y单独效果都增加z，那么对于上述的三种情况：
  1.都弹奏 z = -z + 2*z
  2.都不谈奏 -z
  2.弹奏其中一个 -z + z = 0
  可以看出来是等价的，那么问题就转化成在一个数字序列中选出一些数，使得总和最大

*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 
     * @param m int整型 
     * @param a int整型vector 
     * @param b int整型vector<vector<>> 
     * @return long长整型
     */
    long long wwork(int n, int m, vector<int>& a, vector<vector<int> >& b) {
        typedef long long LL;
        LL res = 0;
        vector<LL> c(n+1,0);
        for(int i = 1 ;i<=n; i++) c[i] = a[i-1];
        for(int i = 0; i<m; ++i){
            int x = b[i][0], y = b[i][1], z = b[i][2];
            c[x] += z, c[y] += z;
            res -= z;
        }

        for(int i = 1; i<=n; i++){
            if(c[i]>0) res += c[i];
        }
        return res;
    }
};
