/*
 * Author: Moon-light
 * 考虑空格时候的状态转移：
 * 如果g[i][j] 是空格， 那么有三种填法：
 *          1. R (i,j)->(i,j+1)
 *          2. D (i,j)->(i+1,j)
 *          3. X (i,j)->(i,j+1) && (i+1,j)
 * 这三种填法中，X和R都可以向右转移，X和D都可以向下转移
 * 那么对于空格，我们只要对dp[i][j]*2/3即可向两个方向转移
 * 最终乘以空格的方案数3^(n*m-k)即可 ps：注意逆元
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
const int N = 5010;
const int mod = 998244353;

int n,m,k;
char g[N][N];
int dp[N][N];

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
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n>>m>>k;

    int a,b;
    char ch;
    rep(i,1,n) rep(j,1,m) g[i][j] = '#';
    rep(i,1,k){
        cin>>a>>b>>ch;
        g[a][b] = ch;
    }
    
    dp[1][1] = 1;
    int inv = qmi(3,mod-2,mod);

    rep(i,1,n){
        rep(j,1,m){

            if(g[i][j] == 'X' || g[i][j] == 'R'){
                dp[i][j+1] = (dp[i][j+1] + dp[i][j])%mod;
            }
            if(g[i][j] == 'X' || g[i][j] == 'D'){
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) %mod;
            }
            
            if(g[i][j] == '#'){
                dp[i+1][j] = ((LL)2*inv*dp[i][j]%mod + dp[i+1][j])%mod;
                dp[i][j+1] = ((LL)2*inv*dp[i][j]%mod + dp[i][j+1])%mod;
            }
        }
    }
    
    cout<<(LL)dp[n][m]*qmi(3,n*m-k,mod)%mod;
    return 0;
}
