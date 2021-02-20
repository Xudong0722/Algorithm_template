int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> vis;
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int n = w.size(), m = w[0].size();
        ans = vector<vector<int>> (n, vector<int>(m,0));
        vis = vector<vector<bool>> (n+1,vector<bool>(m+1,0));
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(w[i][j] == 1){
                    vis[i][j] = true;
                    q.push({i,j});
                    
                }
            }
        }
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int i = t.first, j = t.second;
            for(int k = 0; k<4; k++){
                int tx = i + dx[k];
                int ty = j + dy[k];
                if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty]) continue;
                ans[tx][ty] = ans[i][j] + 1;
                q.push({tx,ty});
                vis[tx][ty] = true;
            }
        }
        return ans;
    }
    
};
