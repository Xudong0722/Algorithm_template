const int N = 100, M = 2e5+100;

bool st[N][N];
int h[M],e[M],ne[M],idx;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

class Solution {
public:
    int gcd(int a,int b){
        return b == 0?a:gcd(b,a%b);
    }
    vector<vector<int>> g;
    vector<int> ans,d,tb;
    
    vector<int> getCoprimes(vector<int>& a, vector<vector<int>>& edges) {
        int n =a.size();
        memset(h,-1,sizeof h),idx = 0;
        ans = vector<int> (n,-1);
        d = vector<int> (n,0),tb = vector<int> (51,-1);
        g = vector<vector<int>>(51);
        for(int i = 1; i<=50; i++){
            for(int j = 1; j<=50;j ++){
                if(gcd(i,j) == 1){
                    g[i].push_back(j);
                }
            }
        }
        for(auto &it:edges){
            int a = it[0], b = it[1];
            add(a,b);
            add(b,a);
        }
        dfs(a,0,-1);
        return ans;
    }
    
    void dfs(vector<int>& a,int u,int fa){
        for(auto &x: g[a[u]]){
            if(tb[x] != -1){
                if(ans[u] == -1 || d[ans[u]] < d[tb[x]]){
                    ans[u] = tb[x];
                }
            }
        }
        int t = tb[a[u]];
        tb[a[u]] = u;
        for(int i = h[u]; ~i; i = ne[i]){
            int j = e[i];
            if(j == fa) continue;
            d[j] = d[u] + 1;
            dfs(a,j,u);
        }
        tb[a[u]] = t;
    }
};
