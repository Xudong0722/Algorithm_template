class Solution {
public:
    bool canChoose(vector<vector<int>>& g, vector<int>& a) {
        int n = g.size();
        int idx = 0;
        int m = a.size();
        for(int i = 0; i<n; i++){
            int u = 0, cnt = g[i].size();
            int now = idx;
            int fst = -1;
            for(; now < m; now ++){
                if(g[i][u] == a[now]){
                    u ++;
                    if(u==1) fst = now;
                }else{
                    if(u){
                        u = 0;
                        now = fst;
                    }
                }
                if(u == cnt){
                    idx = ++ now;
                    break;
                }
            }
            if(u != cnt) return false;
            if(i == n-1 && u == cnt) return true;
            if(idx == m) return false;
        }
        return false;
    }
};
