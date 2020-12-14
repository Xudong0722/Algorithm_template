/*
 * Author: Moon-light
 * 
 * 题意: 有两个长度分别为N和M的序列A,B
 * 删除序列A中的a个元素得到A' , 0<=a<=N
 * 删除序列B中的b个元素得到B' , 0<=b<=M
 * 使得A'的长度等于B'的长度
 * 令x = a + b
 *   y = Sum of i A'i != B'i 
 * 
 * 思路: 编辑距离模型
 * 设dp[i][j] 表示对A前i个及对B前j个元素的最小答案
 * 那么对于当前的A[i]和 B[j]
 * 有三种情况： 1.删除A[i]，保留B[j] dp[i-1][j] + 1
 *              2.保留A[i]，删除B[j] dp[i][j-1] + 1
 *              3.保留A[i], 保留A[j] dp[i-1][j-1] + (a[i]==b[j]?0:1)
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
const int N = 1010;
const int mod = 1e9+7;

int n,m;
int a[N],b[N];
int dp[N][N];

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

    rep(i,1,n) cin>>a[i];
    rep(i,1,m) cin>>b[i];

    //initialization
    rep(i,1,n) dp[i][0] = i;
    rep(i,1,m) dp[0][i] = i;

    rep(i,1,n){
        rep(j,1,m){
            //删一个
            dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
            //不删
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i]==b[j]?0:1));
        }
    }
    cout<<dp[n][m];
    return 0;
}
