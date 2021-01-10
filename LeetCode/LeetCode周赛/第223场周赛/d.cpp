//暴搜
class Solution {
public:
    int ans,total;
    vector<int> a;
    vector<int> job;
    
    void dfs(int u,int j,int res){
        if(res > ans) return ;
        if(j == total){
            ans = res;
            return ;
        }
        
        //分配给之前的工人
        for(int i = 0; i<u; i++){
            a[i] += job[j];
            dfs(u,j+1,max(res,a[i]));
            a[i] -= job[j];
        }
        
        //将这份工作交给一个新的工人来做
        if(u < a.size()){
            a[u] = job[j];
            dfs(u+1,j+1,max(res,a[u]));
            a[u] = 0;
        }
    }
    
    //dfs ，对每份工作来说，可以分配给之前的工人，也可以让一个新的工人来做
    int minimumTimeRequired(vector<int>& jobs, int k) {
        ans = 1e9;
        job = jobs,total = jobs.size();
        a.resize(k);
        dfs(0,0,0);  //当前用到的工人， 当前遍历到第几份工作, 当前答案
        return ans;
    }
};
