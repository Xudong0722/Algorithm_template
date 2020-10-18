/*
  两个数的最大公因数大于threshold，换个角度考虑，哪两个数的最大公因数一定大于threshold？
  假设第一个数是x(x>threshold),那么2x, 3x,4x,...,nx与x的最大公因数就是x,一定是满足条件的
  所以我们枚举最大公因数,从threshold+1开始,他与他的倍数组成的城市一定有路径直通
  然后用并查集维护所有连通的集合即可
*/
const int N = 1e4+100;
int p[N];

int find(int x){
    if(p[x] != x){
        p[x] = find(p[x]);
    }
    return p[x];
}
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int m = queries.size();
        for(int i = 1; i<=n; i++) p[i] = i;
        
        //ai != aj 且最大公因数要严格大于threshold,所以从threshold+1开始
        for(int i = threshold+1; i<=n; i++){
            for(int j = i; j<=n; j+=i){
                p[find(i)] = find(j);
            }
        }
        vector<bool> ans(m);
        
        for(int i = 0; i<m; i++){
            int a = queries[i][0], b = queries[i][1];
            ans[i] = (find(a) == find(b));
        }
        return ans;
    }
};
