class Solution {
public:
    vector<int> p;
    
    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        
        for(int i = 0; i<n; i++) p.push_back(i);
        
        for(auto &x:allowedSwaps) p[find(x[0])] = find(x[1]);
        
        vector<unordered_multiset<int>> h(n);
        for(int i = 0; i<n; i++){
            h[find(i)].insert(source[i]);
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            auto &arr = h[find(i)];
            if(arr.count(target[i])) arr.erase(arr.find(target[i]));
            else ans ++;
        }
        return ans;
        
    }
};
