/*
 * Author: Moon_light
 * Solution: 二进制枚举方案
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
// int c[N];
int t;
int n,m,k;
PII a[N];
int c[N],d[N];
bool st[N];

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
// void update(int u,int x){
//     for(int i = u; i<=n; i+=lowbit(i)){
//         c[i] += x;
//     }
// }
// LL sum(int x){
//     LL res = 0;
//     for(; x; x-=lowbit(x)){
//         res += c[x];
//     }
//     return res;
// }
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n>>m;

    rep(i,1,m){
        cin>>a[i].first>>a[i].second;
    }

    cin>>k;

    rep(i,1,k){
        cin>>c[i]>>d[i];
    }
    int ans = 0;
    for(int i = 0; i<(1<<k); i++){
        mst(st,0);
        for(int j = 0; j<k; j++){
            if(i>>j&1){
                st[d[j+1]] = 1;
            }else{
                st[c[j+1]] = 1;
            }
        }

        int res = 0;
        rep(i,1,m){
            if(st[a[i].first] && st[a[i].second]) res ++;
        }
        ans = max(res,ans);
    }
    cout<<ans<<endl;
    return 0;
}
