typedef pair<int,int> PII;
class Solution {
public:
    priority_queue<PII,vector<PII>,greater<PII> >h;
    int eatenApples(vector<int>& app, vector<int>& d) {
        int ans = 0;
        
        int n = app.size();
        
        for(int i = 0;i<=40000; i++){
            if(i<n && app[i]){
                h.push({i+d[i],app[i]});
            }
            
            while(!h.empty() && h.top().first <i+1) h.pop();
            
            if(!h.empty()){
                auto t = h.top();
                h.pop();
                if(t.second){
                    ans ++;
                    if(t.second >1){
                        t.second--;
                        h.push(t);
                    }
                }
            }
        }
        return ans;
    }
};
