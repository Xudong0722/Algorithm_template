/*
 * Author: Moon-light
 * 很基础的一道题，以为自己写的是前缀和，但是前缀和那里没有转移。。所以耽误了一会时间
 * dp[i][j] 表示到(i,j) 的方案数
 * 因为可以跳着走，所以dp[i][j] 可以从这一行前面所有的路上转移过来，也可以从这一列上所有前面的
 * 路上转移过来，也可以从左上方转移过来
 * 这样转移是n方的，那么我们可以用三个前缀和来记录三个方向的方案和
 * 那么每一次转移都是O(1)
 * 
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
const int N = 2020;
const int mod = 1e9+7;
int n,m;
char g[N][N];
int dp[N][N];
int a[N][N],b[N][N],c[N][N];

//functions
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
    cin>>n>>m;

    rep(i,1,n){
        rep(j,1,m){
            cin>>g[i][j];
        }
    }

    a[1][1] = b[1][1] = c[1][1] = dp[1][1] = 1;
    rep(i,1,n){
        rep(j,1,m){
            if(i ==1 && j==1) continue;
            if(g[i][j] == '#'){
                dp[i][j] = a[i][j] = b[i][j] = c[i][j] = 0;
                continue;
            }
            dp[i][j] = ((LL)a[i][j-1] + b[i-1][j]%mod + c[i-1][j-1])%mod;
            a[i][j] = ((LL)dp[i][j] + a[i][j-1])%mod;
            b[i][j] = ((LL)dp[i][j] + b[i-1][j])%mod;
            c[i][j] = ((LL)dp[i][j] + c[i-1][j-1])%mod;
        }
    }
    cout<<dp[n][m]%mod<<endl;
    return 0;
}
