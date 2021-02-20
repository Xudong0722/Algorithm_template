class Solution {
public:
    bool check(string s){
        map<char,bool> h;
        for(auto x:s){
            h[x] = true;
        }
        for(auto x:s){
            if(islower(x)){
                char u = toupper(x);
                if(!h[u]) return false;
            }else{
                char u = tolower(x);
                if(!h[u]) return false;
            }
            
        }
        return true;
    }
    
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans;
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                string t = s.substr(i,j-i+1);
                if(check(t)){
                    if(t.size() > res){
                        res = t.size();
                        ans = t;
                    }
                }
            }
        }
        if(!res) return "";
        return ans;
    }
};
