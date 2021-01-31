// Solution
 
//n个点和n-1条边，所以这个图是一棵树
//n个点中有两个点的出入度是1，其他都是2
//我们找出这两个点，以任意一点为根，不断添加点即可

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ax) {
        int n = ax.size();
        map<int,int> din,dout;
        map<int,vector<int>> h;
        set<int> e;
        for(auto &x:ax){
            int u = x[0], v = x[1];
            e.insert(u);
            e.insert(v);
            h[u].push_back(v);
            h[v].push_back(u);
            din[u] ++;
            din[v] ++;
            dout[u] ++;
            dout[v] ++;
        }
        
        int first = 1e6, last = 0;
        for(auto &x:e){
            if(din[x] + dout[x] == 2){
                if(first == 1e6) first = x;
                else last = x;
            }
        }
        
        vector<int> ans;
        ans.push_back(first);
        map<int,bool> st;
        st[first] = true;
        int cnt = 1,now = first;
        while(cnt <= n){
            for(auto &y:h[now]){
                if(st[y]) continue;
                ans.push_back(y);
                st[y] = true;
                cnt ++;
                now = y;
                break;
            }
        }
        return ans;
    }
};
```
