class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(s[l] == s[r] && l<r){ 
            while(l<r && s[l+1] == s[l]) l++;
            while(r>l && s[r-1] == s[r]) r--;
            if(l >= r) return 0;
            l++,r--;
        }
        return r-l+1;
    }
};
