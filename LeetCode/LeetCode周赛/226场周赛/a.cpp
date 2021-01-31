class Solution {
public:
    int countBalls(int low, int high) {
        vector<int> a(100,0);
        for(int i = low; i<=high; i++){
            int sum = 0;
            int t = i;
            
            while(t){
                sum += t%10;
                t/=10;
            }
            a[sum] ++;
        }
        
        sort(rbegin(a),rend(a));
        return a[0];
    }
};
