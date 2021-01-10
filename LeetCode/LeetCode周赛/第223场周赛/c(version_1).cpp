
const int N = 1e5+100;

int p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        for(int i = 0; i<n; i++) p[i] = i;
        for(auto &x:allowedSwaps){
            int a = x[0], b = x[1];
            int pa = find(a), pb = find(b);          
            p[pa] = pb;
        }    
        map<pair<int,int>, int> h;
        for(int i = 0; i<n; i++){
            int fa = find(i);
            h[{fa,source[i]}]++;
        }
        for(int i = 0; i<n; i++){
            int fa = find(i);
            h[{fa,target[i]}]--;
            
        }

        int ans = 0;
        map<pair<int,int>, int> st;
        for(int i = 0; i<n; i++){
            int fa = find(i);
            if(st.count({fa,source[i]})) continue;
            if(h.count({fa,source[i]})){
                if(h[{fa,source[i]}] >0) ans += h[{fa,source[i]}];
                st[{fa,source[i]}] = 1;
            }
        }
        return ans;
    }
};
