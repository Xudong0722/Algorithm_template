class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回m天后高度为奇数的树的数量
     * @param n int整型 
     * @param m int整型 
     * @param l int整型vector 
     * @param r int整型vector 
     * @return int整型
     */
    int oddnumber(int n, int m, vector<int>& l, vector<int>& r) {
        vector<int> a(n+1,0);
        
        for(int i = 0; i<m; ++i){
            a[l[i]] += 1;
            a[r[i]+1] -= 1;
        }
        
        for(int i = 1; i<=n; i++){
            a[i] += a[i-1];
        }
        
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if((a[i]+m)&1) ans ++;
        }
        return ans;
    }
};
