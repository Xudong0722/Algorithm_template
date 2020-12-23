class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回牛牛获得的快乐指数
     * @param n int整型 题单里的题目数量
     * @return int整型
     */
    int solve(int n) {
        int ans = 0;
        
        for(int i = 1; i<=n; i++){
            if(check(i)) ans += i;
        }
        return ans;
    }
    
    bool check(int x){
        double res = 0;
        for(int i = 1; i<=x; i++){
            if(x%i==0) res += i;
        }
        if(res/x < 2.0) return true;
        return false;
    }
};
