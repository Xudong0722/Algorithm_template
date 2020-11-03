/*
 * Author: Moon-light
 * 判断一下斜率即可
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
const int N = 110;
const int mod = 1e9+7;
int n;
PII a[N];

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

bool check(int i,int j,int k){
    int xa = a[i].fi, ya = a[i].se;
    int xb = a[j].fi, yb = a[j].se;
    int xc = a[k].fi, yc = a[k].se;
    if(a[i].fi == a[j].fi && a[i].fi == a[k].fi) return true;
    if(a[i].se == a[j].se && a[i].se == a[k].se) return true;
    
    if((xa == xb && xc != xa) || (xa == xc && xb != xa)) return false;
    if((yb-ya)*(xc-xa) == (yc-ya)*(xb-xa)) return true;
}
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n;
    rep(i,1,n) cin>>a[i].fi>>ja[i].se;

    rep(i,1,n){
        rep(j,1,n){
            rep(k,1,n){
                if(i == j || i == k || j == k) continue;
                if(check(i,j,k)){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
