/*
 * Author: Moon-light
 * Time: 2020-10-29 08:45:42
 * dp[i][j] 表示前i分钟内烹饪j个菜品的最优解
 * 不选第j个：dp[i][j] = dp[i-1][j]
 * 选第j个： dp[i][j] = dp[i-1][j-1] + abs(i-a[j])
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
const int N = 210,M = N*2;
const int mod = 1e9+7;
int t,n;
int a[N],dp[M][N];


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
    cin>>t;
    while(t--){
        cin>>n;
        rep(i,1,n) cin>>a[i];
        sort(a+1,a+1+n);
        mst(dp,0x3f);
        dp[0][0] = 0;

        rep(i,1,2*n){
            rep(j,0,n){
                dp[i][j] = min(dp[i][j],dp[i-1][j]);
                if(j)dp[i][j] = min(dp[i][j],dp[i-1][j-1]+abs(i-a[j]));
            }
        }
        int ans = 1e9;
        rep(i,1,2*n){
            ans = min(ans,dp[i][n]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
