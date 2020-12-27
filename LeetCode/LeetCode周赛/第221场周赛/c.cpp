/*  
  按照题意模拟即可，注意判断边界
*/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> res;
        
        for(int i = 0; i<m; i++){
            int x = 0, y = i;
            int ans = -1;
            while(1){
                if(grid[x][y] == 1){
                    if(y + 1 >= m) break;
                    if(grid[x][y+1] == -1) break;
                    x++;
                    y++;
                }else{
                    if(y-1 < 0) break;
                    if(grid[x][y-1] == 1) break;
                    x++;
                    y--;
                }
                if(y < 0 || y >=m) break;
                if(x>=n) {
                    ans = 1;
                    break;
                }
            }
            if(ans == 1)res.push_back(y);
            else res.push_back(-1);
        }
        return res;
    }
};
