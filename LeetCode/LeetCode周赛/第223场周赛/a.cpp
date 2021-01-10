// c = a ^ b  -> b = a ^ c, a = b ^ c
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        
        int n = encoded.size();
        ans.push_back(first);
        for(int i = 0; i<n; i++){
            ans.push_back(encoded[i]^first);
            first = encoded[i]^first;
        }
        // ans.push_back(first);
        return ans;
    }
};
