/*
  Trie树的模板
  先对数组和查询数组分别排序，对每次查询，只把不大于限定值的元素放到树上
  然后查询一遍即可
*/

const int N = 1e5+100,M = 3e6+100;

int son[M][2],idx;
void iinsert(int x)
{
    int p = 0;
    for(int i = 30; i>=0 ; i--)
    {
        int u = x>>i&1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int search(int x)
{
    int p = 0;
    int res = 0;
    for(int i = 30; i>=0 ;i--)
    {
        int u = x>>i&1;
        if(son[p][!u]) 
        {
            p = son[p][!u];
            res += 1<<i;
        }
        else
            p = son[p][u];
    }
    return res;
}

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qs) {
        int n = nums.size();
        int m = qs.size();
        memset(son,0,sizeof son);
        for(int i = 0; i<m; i++){
            qs[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        sort(qs.begin(),qs.end(),cmp);
        
        int cnt = 0;
        vector<int> ans(m);
        for(int i = 0; i<m; i++){
            int stand = qs[i][1];
            while(cnt < n && nums[cnt] <= stand){
                iinsert(nums[cnt++]);
            }
            if(nums[0] > qs[i][1]) ans[qs[i][2]] = -1;
            else ans[qs[i][2]] = search(qs[i][0]);
        }
        return ans;
    }
};
