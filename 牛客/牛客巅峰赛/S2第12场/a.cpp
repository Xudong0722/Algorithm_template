class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 判断x是不是好数
     * @param x int整型 待判断的数
     * @return bool布尔型
     */
    bool judge(int x) {
        int last = x%10;
        int first = 0;
        
        while(x){
            if(x/10 == 0) first = x%10;
            x/=10;
        }
        return first == last;
    }
};
