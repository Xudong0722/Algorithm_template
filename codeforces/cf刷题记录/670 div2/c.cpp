/*
 * Author: Moon-light
 * Time: 2020-10-30 09:45:57
 * 关于树的重心的性质：
 *  1.删除重心后所得的所有子树，节点数不超过原树的1/2，一棵树最多有两个重心；

　　2.树中所有节点到重心的距离之和最小，如果有两个重心，那么他们距离之和相等；

　　3.两个树通过一条边合并，新的重心在原树两个重心的路径上；

　　4.树删除或添加一个叶子节点，重心最多只移动一条边；

    5.一棵树最多有两个重心，且相邻。


    根据以上性质，我们先找树的重心，如果只有一个，那么随便删除重心的相连边再连上即可
    如果有两个，找其中一个重心的相连边，注意，这条边与另一个重心不能相连，删除这条边
    让另一个重心与这条边的顶点相邻即可
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
const int N = 1e5+100, M = 2*N;
const int mod = 1e9+7;
int t,n,cnt;   //cnt表示重心的数量
int h[N],e[M],ne[M],idx;
bool st[N];
int x,y;


//functions
void add(int a,int b){
    e[idx] = b,ne[idx] = h[a], h[a] = idx++;
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

int dfs(int u,int fa){
    st[u] = true;
    int now = 1, res = 0;  
    //now表示以当前节点为根的子树所含节点的个数
    //res表示删除u与当前节点相连的边之后的最大连通子图的节点个数
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        if(!st[j]){
            int s = dfs(j,u);
            res = max(res,s);
            now += s;
        }
    }
    res = max(res,n-now);
    if(res<<1 <= n) {   //性质1：删除重心后所得的所有子树的节点个数不会超过n/2
        y = x, x = u;
        cnt++;
    }
    return now;
}
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>t;
    mst(st,0);
    while(t--){
        cin>>n;

        int a,b;
        cnt = 0;
        mst(h,-1);
        mst(st,0);

        idx = 0;
        rep(i,1,n-1){
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
        x = y = 0;
        dfs(1,0);

        if(cnt==1){
            int j = e[h[x]];
            cout<<x<<" "<<j<<endl;
            cout<<x<<" "<<j<<endl;
        }else{
            //cout<<x<<" "<<y<<endl;
            int t = x;
            for(int i = h[t]; ~i; i = ne[i]){
                int j = e[i];
                if(j != y){
                    x = j;  
                    break;
                }
            }
            cout<<t<<" "<<x<<endl;
            cout<<y<<" "<<x<<endl;
        }
    }
    return 0;
}
