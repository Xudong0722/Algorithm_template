/*
    离线处理，对所有边从小到大排序
    然后对于每次询问，将边长小于limit的边全部加到图中，使用并查集维护连通性
*/
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[2] < b[2];
    }
    vector<int> p;
    
    int find(int x){
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = edgeList.size(), k = queries.size();
        p.resize(n);
        for(int i = 0; i<n; i++) p[i] = i;
        for(int i = 0; i<k; i++) queries[i].push_back(i);

        sort(edgeList.begin(),edgeList.end(),cmp);
        sort(queries.begin(),queries.end(),cmp);
        
        vector<bool> ans(k,0);
        
        for(int i = 0,j = 0; i<k; i++){
            while(j<m && edgeList[j][2] < queries[i][2]){
                int a = edgeList[j][0], b = edgeList[j][1];
                int pa = find(a), pb = find(b);
                if(pa != pb){
                    p[pa] = pb;
                }
                j++;
            }
            ans[queries[i][3]] = find(queries[i][0]) == find(queries[i][1]);
        }
        return ans;
    }
};
