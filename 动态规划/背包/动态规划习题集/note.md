*作为动态规划习题册*

----
#目录
1.[luogu1417烹调方案](https://www.luogu.com.cn/problem/P1417)
2.[luogu1489猫狗大战](https://www.luogu.com.cn/problem/P1489)
3.[luogu1523旅行商简化版](https://www.luogu.com.cn/problem/P1523)
4.[luogu1537弹珠](https://www.luogu.com.cn/problem/P1537)
5.[luogu1622 释放囚犯](https://www.luogu.com.cn/problem/P1622)
6.[LeetCode834.树中距离之和](https://leetcode-cn.com/problems/sum-of-distances-in-tree/)
7.[luogu1725琪露诺](https://www.luogu.com.cn/problem/P1725)
8.[luogu2170选学霸](https://www.luogu.com.cn/problem/P2170)
----


# 1.[luogu1417烹调方案](https://www.luogu.com.cn/problem/P1417)
01背包的变形题，对于01背包来说，是不用考虑每个物品的枚举顺序的，因为物品的价值是固定的，但是对于此题来说，烹调顺序的不同会导致每个物品的价值不同，价值与食材的选择顺序是相关的，所以我们需要进行一个预处理:
**假设当前时刻为t， 我们先烹调 i 号食材， 再烹调 j 号食材，那么美味指数是:**
**ai -  t * bi + aj - (t + ci) * bj**
**假设当前时刻为t， 我们先烹调 j 号食材， 再烹调 i 号食材，那么美味指数是:**
**aj - t * bj + ai - (t + cj) * bi**
若前式所得价值大于后式所得价值，则需要：
**-ci * bj > -cj * bi**
即先按照上式对食材进行排序，再做一遍01背包即可

```
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int M = 1e5+100;

int T,n;
struct W{
    LL a,b,c;
    bool operator<(const W& v){
        return c*v.b<v.c*b;
    }
}w[M];
LL dp[M];

int main()
{
    cin>>T>>n;
    
    for(int i = 1; i<=n; i++){
        cin>>w[i].a;
    }
    for(int i = 1; i<=n; i++){
        cin>>w[i].b;
    }
    for(int i = 1; i<=n; i++){
        cin>>w[i].c;
    }
    
    
    sort(w+1,w+1+n);
    
    for(int i = 1; i<=n; i++){
        for(int j = T; j>=w[i].c; j--){
            dp[j] = max(dp[j], dp[j-w[i].c]+w[i].a-j*w[i].b);
        }
    }
    
    LL ans = -1e9;
    for(int i = 0; i<=T; i++) ans = max(ans,dp[i]);
    cout<<ans;
    return 0;
}
```


# 2.[luogu1489猫狗大战](https://www.luogu.com.cn/problem/P1489)
状态表示： dp[i][j][k] 表示在前 i 个人中选 j 个，能否凑成血量为 k 的队伍
那么状态转移：` dp[i][j][k] = dp[i-1][j][k] | dp[i-1][j-1][k-a[i]] `
由于只用了前一层的状态，所以我们可以优化掉第一维：
` dp[j][k] = dp[j][k] | dp[j-1][k-a[i]] `
循环完之后，遍历dp[n>>1][ 1+sum>>1 ~ 0] 即可

```
#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n;
int a[N], dp[N][N*40];
int sum;


int main()
{
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        sum += a[i];
    }
    
    dp[0][0] = 1;
    
    for(int i = 1; i<=n; i++){
        for(int j = n>>1; j>0; j--){
            for(int m = sum; m>=a[i]; m--){
                dp[j][m] = dp[j][m] | dp[j-1][m-a[i]];
            }
        }
    }
    
    for(int i = 1+sum>>1; i>=0; i--){
        if(dp[n>>1][i]){
            cout<<i<<" "<<sum-i<<endl;
            break;
        }
    }
    
    return 0;
}
```

# 3.[luogu1523旅行商简化版](https://www.luogu.com.cn/problem/P1523)
暂略~

# 4.[luogu1537弹珠](https://www.luogu.com.cn/problem/P1537)
题意：一堆物品，每个物品都有价值，判断能否从这堆物品中取出价值为总价值一半的物品。
此题可以转换为背包问题，我们假定每个物品的价值和体积一样，做一遍背包，最后判断体积为总价值一半的背包里装的物品的价值是否是背包体积即可。
此题数据较水，01背包即可切掉，但是做得时候我们还是按照多重背包去做个优化。

```
#include <bits/stdc++.h>

using namespace std;

const int N = 20010;

//背包问题， 是否能将背包为sum/2的背包装满，价值为sum/2

int a[N],w[N],v[N];
int dp[N];

int main()
{
    int idx = 0;
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]){
        
        idx++;
        if(!a[1] && !a[2] && !a[3] && !a[4] && !a[5] && !a[6]) break;
        memset(dp,0,sizeof dp);
        int cnt = 0;
        int sum = 0;
        for(int i = 1; i<=6; i++){
            int k = 1;
            sum += a[i]*i;
            while(k<=a[i]){
                cnt++;
                w[cnt] = i*k;
                v[cnt] = i*k;
                a[i] -= k;
                k<<=1;
            }
            if(a[i]>0){
                cnt++;
                w[cnt] = a[i]*i;
                v[cnt] = a[i]*i;
            }
        }
        if(sum&1){
            printf("Collection #%d:\n",idx);
            printf("Can't be divided.\n\n");
            continue;
        }
        for(int i = 1; i<=cnt; i++){
            for(int j = sum/2; j>=v[i]; j--){
                dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
            }
        }
        //cout<<dp[sum/2]<<endl;
        if(dp[sum/2] == sum/2){
            printf("Collection #%d:\n",idx);
            printf("Can be divided.\n\n");
        }else{
            printf("Collection #%d:\n",idx);
            printf("Can't be divided.\n\n");
            continue;
        }
    }
    return 0;
}
```

# 5.[luogu1622 释放囚犯](https://www.luogu.com.cn/problem/P1622)
（参考题解的第一个https://www.luogu.com.cn/problem/solution/P1622，区间DP还是写的太少了...)
区间DP，设dp[i][j] 表示释放第i 到 第 j个囚犯最少的送肉次数。
状态转移： dp[i][j] = dp[i][k-1] + dp[k+1][j] + a[j+1] - a[i-1] - 2;
即 **枚举i到j中即将释放囚犯的编号，然后通过i和j外的已释放的囚犯造成的断点(i-1 和 j+1)转移状态，这里的-2可以自己用一个序列验证一下**

在题解中，还有一种DP的思维方式是根据释放囚犯的编号先将牢房分成多个区间，然后转换成石子合并来做，甚秒~
```
#include <bits/stdc++.h>

using namespace std;

const int N = 1010, inf = 1e9;

int a[N],dp[N][N];
int n,m;

int main()
{
    cin>>n>>m;
    
    for(int i = 1; i<=m; i++){
        cin>>a[i];
    }
    
    sort(a+1,a+1+m);
    a[0] = 0, a[m+1] = n+1; //边界处理
    // memset(dp,0x3f,sizeof dp);
    for(int len = 1; len<=m; len++){
        for(int i = 1; i+len-1<=m; i++){
            int j = i+len-1;
            dp[i][j] = inf;
            for(int k = i; k<=j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k+1][j] + a[j+1]-a[i-1]-2);
            }
            // cout<<dp[i][j]<<endl;
        }
    }
    cout<<dp[1][m];
    return 0;
}
```

#6.[LeetCode834.树中距离之和](https://leetcode-cn.com/problems/sum-of-distances-in-tree/)
题意为求树上每个点到其他所有点的距离之和。
设dp[u] 表示节点u到其所有子孙的距离之和，cnt[u] 表示节点u的所有子孙的个数(包括自己)，那么容易得到状态转移方程 $dp[u] = \sum_j dp[j] + cnt[j]$（j是u的儿子）
在dfs一遍之后，我们就得到root的答案，但是题目要求每个点，我们可以做n遍dfs，但这样时间复杂度就是$N^2$了，不妨利用dp数组来优化：
对于root的儿子k，若可以把k变成root， root变成k的儿子，那么就可以直接得到答案了，我们可以用dp[root] 和dp[k] 的关系来更新实现这种变换：
 -  dp[u] -= (dp[j]+cnt[j]);   //1 和 2两步就是从u的儿子中删除 j 这一个儿子
 - cnt[u] -= cnt[j];
 - dp[j] += (dp[u]+cnt[u]);  // 3 和 4 就是将u变成j的儿子，更新dp[j]
 - cnt[j] += cnt[u];

```
const int N = 10010, M = N*2;
int h[M],e[M],ne[M],idx;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dp[N], cnt[N];  //dp[i] 表示节点i到其所有子孙的距离之和

class Solution {
public:
    vector<int> ans;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        //思路：两遍DP，然后遍历一遍DP数组
        memset(h,-1,sizeof h);
        memset(ne,0,sizeof ne);
        memset(dp,0,sizeof dp);
        memset(cnt,0,sizeof cnt);
        idx = 0;
        
        for(int i = 0; i<N-1; i++){
            int a = edges[i][0], b = edges[i][1];
            cnt[a] = 1,cnt[b] = 1;
            add(a,b);
            add(b,a);
        }

        dfs(0,-1);
        ans = vector<int>(N,0);
        dfs_ans(0,-1);
        return ans;
    }

    void dfs(int u,int f){
        for(int i = h[u]; ~i; i = ne[i]){
            int j = e[i];
            if(j == f) continue;
            dfs(j,u);
            dp[u] += dp[j] + cnt[j];
            cnt[u] += cnt[j];
        }
    }

    void dfs_ans(int u,int f){
        ans[u] = dp[u];

        for(int i = h[u]; ~i; i =  ne[i]){
            int j = e[i];
            if(j == f) continue;

            int predpu = dp[u], precntu = cnt[u];
            int predpj = dp[j], precntj = cnt[j];

            dp[u] -= (dp[j]+cnt[j]);
            cnt[u] -= cnt[j];
            dp[j] += (dp[u]+cnt[u]);
            cnt[j] += cnt[u];
            
            dfs_ans(j,u);

            //恢复现场
            dp[u] = predpu;
            dp[j] = predpj;
            cnt[u] = precntu;
            cnt[j] = precntj;
        }
    }
};
```

#7.[luogu1725琪露诺](https://www.luogu.com.cn/problem/P1725)
用dp[i]表示走到 i 获得的最大冰冻指数
那么状态转移方程非常简单： $dp[i] = dp[j] + a[i];  i-r <= j <= i-l$
状态数有N个，状态转移是O(N)的，根据这题的数据范围来看$N^2$肯定是超时的，所以需要优化一下。
其实这题和[Acwing1089.烽火传递](https://www.acwing.com/problem/content/description/1091/)有点类似，算是单调队列优化二维DP的模板吧。
我们在单调队列中存放前面合法区间的dp的max，单调队列中是单调递减的，那么每次取出队头元素进行状态转移就行了，时间复杂度是O(N)。
**关于单调队列：大概就是去头去尾再更新三个要点吧（逃**
```
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 200010;

int n,l,r;
int a[N];
int dp[N];
int q[N*2];

int main()
{
    cin>>n>>l>>r;
        
    for(int i = 0; i<=n; i++){
        cin>>a[i];
    }
    
    int hh = 0, tt = 0;
    int cur = 0;   //待入队的点的下标
    
    memset(dp,-0x3f,sizeof dp);
    dp[0] = 0;
    for(int i = l; i<=n; i++){
        while(hh<=tt && q[hh]+r<i) hh++;
        while(hh<=tt && dp[cur] >= dp[q[tt]]) tt--;
        q[++tt] = cur++;
        dp[i] = dp[q[hh]] + a[i];
        //cout<<i<<"->"<<dp[i]<<" "<<tt<<endl;
    }
    
    int ans = -0x3f3f3f3f;
    for(int i = n-r+1; i<=n; i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
```
# 8.[luogu2170选学霸](https://www.luogu.com.cn/problem/P2170)
把实力相近的人都放在一组，这一组中一旦选了一个，就必须全部选，所以我们可以先用并查集将所有实力相近的学霸合并成一个“物品”，体积和价值就是这个集合的大小，预处理之后，我们做一遍01背包即可，注意，这里让我选出数量尽可能接近m，所以可能超过m的，那我们先将背包容量扩充一下，最后遍历一遍所有体积的背包即可(在这里卡了好久，太菜了。。。)
```
#include <bits/stdc++.h>

using namespace std;

const int N = 2e4+100;

int n,m,k;
int p[N], w[N],dp[N], a[N];

//实力相近的人放在一个集合里面，如果选了其中一个，那么集合中所有的人都需要选择
//我们把每个人看做一个物品，价值和体积都为1，背包容量为m，此题就转换成了01背包问题

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    freopen("in.txt","r",stdin);
    cin>>n>>m>>k;
    for(int i = 1; i<=n; i++) {
        p[i] = i;
        w[i] = 1;
    }
    
    for(int i = 1; i<=k; i++){
        int x,y;
        cin>>x>>y;
        int px = find(x), py = find(y);
        
        if(px != py){
            p[py] = px;
            w[px] += w[py];
            // w[py] = 0;
        }
    }
    int cnt = 0;  //物品的个数（组的个数）
    for(int i = 1; i<=n; i++){
        if(p[i] == i){
            cnt ++;
            a[cnt] = w[i];
        }
    }

    for(int i = 1; i<=cnt; i++){
            for(int j = 2*m; j>=a[i]; j--){
                dp[j] = max(dp[j],dp[j-a[i]] + a[i]);
            }
    }

    int ans = 1e9, res;
    for(int i = 1; i<=2*m; i++){
        if(abs(dp[i]-m) < ans){
            ans = abs(dp[i]-m);
            res = dp[i];
        }
    }
    if(ans==1e9) cout<<0<<endl;
    else cout<<res;
    return 0;
}
```
