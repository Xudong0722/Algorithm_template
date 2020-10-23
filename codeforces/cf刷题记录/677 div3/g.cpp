/*
 * Author: Moon-light
 * Time: 2020-10-21 23:46:07
 * 先求出n个点到其他所有点的最短路
 * 枚举将某条边k的权值变成0，那么每条派送的路线可以选择绕道这条路上来也可以不绕，因为花费可能不变
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
const int N = 1010,M = N*2;
const int mod = 1e9+7;
int n,m,k;
int h[N],e[M],w[M],ne[M],idx;
int dist[N][N];
PII a[N],b[N];
bool st[N];

//functions
void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int u){
    for(int i = 1; i<=n; i++) dist[u][i] = 0x3f3f3f3f;
    mst(st,0);
    dist[u][u] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,u});

    while(!heap.empty()){
        int t = heap.top().second, distance = heap.top().first;
        heap.pop();

        if(st[t]) continue;
        st[t] = true;

        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[u][j] > distance + w[i]){
                dist[u][j] = distance + w[i];
                heap.push({dist[u][j],j});
            }
        }
    }  
}
LL qmi(LL a,LL k,LL mod){
    LL res = 1;
    while(k){
        if(k&1) res = res*a%mod;
        k >>= 1;
        a = a*a%mod;
    }
    return mod;
}
int gcd(int a,int b) {
    return b==0? a:gcd(b,a%b);
}
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n>>m>>k;
    
    mst(h,-1);
    for(int i = 1; i<=m; i++){
        int ax,bx,c;
        cin>>ax>>bx>>c;
        b[i] = {ax,bx};
        add(ax,bx,c);
        add(bx,ax,c);
    }

    for(int i = 1; i<=k; i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i = 1; i<=n; i++){
        dijkstra(i);
    }
    //枚举将哪条边的权值变为0
    LL ans = 1e9;
    for(int i = 1; i<=m; i++){
        int ta = b[i].first, tb = b[i].second;
        LL res = 0;
        for(int j = 1; j<=k; j++){
            int ka = a[j].first, kb = a[j].second;
            res += min(dist[ka][kb],min(dist[ka][tb]+dist[ta][kb],dist[ka][ta]+dist[tb][kb]));
        }
        // cout<<res<<endl;
        ans = min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}
