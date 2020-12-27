/*
  模拟即可
*/
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        
        int a = 0, b = 0;
        string q = "aeiouAEIOU";
        map<char,bool> h;
        h.clear();
        for(auto x:q) h[x] = true;
        
        for(int i = 0; i<n/2; i++){
            if(h.count(s[i])) a++;
            else b++;
        }
        
        for(int i = n/2; i<n; i++){
            if(h.count(s[i])) a--;
            else b--;
        }
        
        if(a==0&&b==0) return true;
        return false;
    }
};
