/*
 * Author: Moon-light
 * 记录每个位置的最大前缀和以及前缀和即可
 * 每走一步，走到的最大位置是上一层的最终位置加上这一层的最大前缀和，更新答案
 * 这一层的终点即上一层的终点加上这一层的前缀和即可
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
const int N = 2e5+100;
const int mod = 1e9+7;
int a[N];
LL s[N];
LL nm[N];
LL mx[N];
int n;

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
    cin>>n;
    LL ans = 0;
    nm[1] = -2;
    rep(i,1,n){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
        if(i == 1){
            nm[1] = a[1];
            mx[1] = max(nm[1],0LL);
        }else{
            nm[i] = nm[i-1] + a[i];
            mx[i] = max(mx[i-1],nm[i]);
        }
    }
    //rep(i,1,n) cout<<mx[i]<<endl;
    ans = max(ans,(LL)a[1]);
    LL now = a[1];
    rep(i,2,n){
        ans = max(ans, now + mx[i]);
        now += s[i];
    }
    cout<<ans<<endl;
    return 0;
}
