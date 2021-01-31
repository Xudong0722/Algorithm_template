/*
 * Author: Moon_light
 * Solution: BFS+状压DP
 * 题解：https://www.acwing.com/solution/content/28736/
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define lowbit(x) ((x)&(-x))
#define sz(x) ((int)x.size())
#define fr(x) freopen(x,'r',stdin)
#define fw(x) freopen(x,'w',stdout)
#define mst(x,a) memset(x,a,sizeof(x))
#define all(a) begin(a),end(a)
#define bitcnt(x) (__builtin_popcountll(x))
#define rep(i,a,b) for(int i = (a);i<=(b); ++i)
#define per(i,a,b) for(int i = (a);i>=(b); --i)
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VB;
typedef double db;

template <class T> void clear(T& a) { T().swap(a);}
template <class T,class S>
inline bool upmin(T& a,const S&b){ return a>b ? a=b,1:0;}
template <class T,class S>
inline bool upmax(T&a, const S&b){ return a<b? a=b,1:0;}

//fast read(improved by fread)
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline int redi() {
    int ret = 0,f = 0;char ch = getc();
    while (!isdigit (ch)) {
        if (ch == '-') f = 1;
        ch = getc();
    }
    while (isdigit (ch)) {
        ret = ret * 10 + ch - 48;
        ch = getc();
    }
    return f?-ret:ret;
}

//global variable
const int N = 1e5+100;
const int mod = 1e9+7,inf = 1e9;

int n,m,k;

//functions
LL qmi(LL a,LL k,LL mod){
    LL res = 1;
    while(k){
        if(k&1) res = res*a%mod;
        k >>= 1;
        a = a*a%mod;
    }
    return res%mod;
}
int gcd(int a,int b) {
    return b==0? a:gcd(b,a%b);
}
bool isprime(int x){
    if(x<2) return false;
    for(int i = 2; i<=x/i; i++){
        if(x%i == 0) return false;
    }
    return true;
}

//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n>>m;

    VVI e(N);
    int x,y;
    
    rep(i,1,m){
        cin>>x>>y;
        x --, y--;
        e[x].pb(y);
        e[y].pb(x);
    }

    cin>>k;
    VI c(k);
    VVI dp(1<<k,VI(k,inf));  // dp[i][j] 表示已经走过了集合i(二进制表示)中所有的点且最后一步走到j的最小代价
    VVI dist(k,VI(k,0));  //dist[i][j] 表示i个j之间的最短距离
    rep(i,0,k-1){
        cin>>x;
        c[i] = --x;
    }

    rep(i,0,k-1){
        VI d(N,inf);
        queue<int> q;
        q.push(c[i]);
        d[c[i]] = 0;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int &x:e[t]){
                if(d[x] != inf) continue;
                d[x] = d[t] + 1;
                q.push(x);
            }
        }
        rep(j,0,k-1){ 
            dist[i][j] = d[c[j]];  //更新i和j之间的最短距离
        }
    }
    
    // 初始化
    for(int i = 0; i<k; i++){
        dp[1<<i][i] = 1; 
    }

    for(int i = 0; i<1<<k; i++){
        for(int j = 0; j<k; j++){
            if(dp[i][j] == inf) continue;
            for(int u = 0; u<k; u++){
                if(u == j) continue;
                if(i>>u&1) continue;  //当前i中没走到的点为u，向u转移
                dp[i+(1<<u)][u] = min(dp[i+(1<<u)][u],dp[i][j] + dist[j][u]);
            }
        }
    }
    
    int ans = inf;
    for(int i = 0; i<k; i++){
        ans = min(ans,dp[(1<<k)-1][i]);
    }
    if(ans == inf) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
