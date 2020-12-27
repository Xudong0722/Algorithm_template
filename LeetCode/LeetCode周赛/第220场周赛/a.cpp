/*
    按要求模拟即可
*/
class Solution {
public:
    string reformatNumber(string number) {
        string t;
        for(auto x: number){
            if(isdigit(x)){
                t += x;
            }
        }

        string ans;
        int n = t.size();
        int cnt = n/3;
        if(cnt*3 == n){
            for(int i = 0; i<n; i++){
                if((i+1)%3==0 && i+1!=n){
                    ans += t[i];
                    ans += "-";
                }else{
                    ans += t[i];
                }
            }
        }else{
            for(int i = 0; i<n; i++){
                if(i == n-3){
                    ans += t[i];
                    ans += "-";
                    ans += t[i+1];
                    ans += t[i+2];
                    break;
                }
                if((i+1)%3 == 0){
                    ans += t[i];
                    ans += "-";
                }else{
                    ans += t[i];
                }
            }
        }

        return ans;
    }
};
