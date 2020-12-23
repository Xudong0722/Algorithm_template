const int mod = 1e9+7;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param arr int整型vector 
     * @param a int整型 
     * @param b int整型 
     * @return int整型
     */
    int countTriplets(vector<int>& arr, int a, int b) {
        int ans = 0;
        
        int n = arr.size();
        for(int j = 1; j<n-1; j++){
            int left = 0, right = 0;
            for(int i = 0; i<j; i++){
                if(abs(arr[i]-arr[j]) <= a) left ++;
            }
            for(int k = j+1; k<n; k++){
                if(abs(arr[k]-arr[j]) <= b) right ++;
            }
            ans =  (ans + (long long)left * right)%mod;
        }
        return ans;
    }
};
