class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& a, vector<string>& b) {        
        string s1 = "",s2 = "";
        
        for(auto x:a) s1 += x;
        for(auto x:b) s2 += x;
        return s1 == s2;
    }
};
