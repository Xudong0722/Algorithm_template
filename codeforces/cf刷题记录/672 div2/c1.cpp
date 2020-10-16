/*
  dp[i][0][0]  表示不拿i，且下一个该拿的应该放在偶数位
  dp[i][0][1]  表示不拿i，且下一个该拿的应该放在奇数位
  dp[i][1][0]  表示拿i，且把a[i] 放在偶数位
  dp[i][1][1]  表示拿i，且把a[i] 放在奇数位
  状态转移方程见代码，很好理解
  （注意，用long long， 有测试点会爆int）
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
//global variable
const int N = 3e5+100;
const int mod = 1e9+7,inf = 1e9;
int t,n,q;
LL a[N];
LL dp[N][2][2];


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
        cin>>n>>q;
        rep(i,1,n) dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -inf;
        rep(i,1,n) cin>>a[i];

        dp[1][0][1] = 0;
        dp[1][1][1] = a[1];
        // dp[1][1][0] = 0;
        // dp[1][0][0] = 0;
        rep(i,2,n){
            //不选i
            dp[i][0][0] = max(dp[i-1][1][1], dp[i-1][0][0]);//当前数不选且下一个应该放偶数位
            dp[i][0][1] = max(dp[i-1][1][0], dp[i-1][0][1]);//当前数不选且下一个应该放奇数位
            //选i且当前数在奇数位
            dp[i][1][1] = max(dp[i-1][0][1], dp[i-1][1][0]) + a[i];
            //选i且当前数放在偶数位
            dp[i][1][0] = max(dp[i-1][0][0], dp[i-1][1][1]) - a[i];
        }

        LL ans = -1;
        rep(i,1,n){
            // ans = max(ans,max(dp[i][0][0],dp[i][0][1]));
            ans = max(ans,dp[i][1][1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
