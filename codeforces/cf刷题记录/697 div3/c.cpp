/*
 * Author: Moon-light
 * Time: 2021-01-25 23:00:03
 * 排序后， 遍历每一个关系，二分找到第一个大于当前男生编号的关系
 * 如果这个关系中女生序号也满足条件，那么就从这个关系往后除去那些与女生编号相同的都是答案
 * 维护一段中女生编号相同的可以先记录女生各个编号的数量，然后在遍历过程中维护已经用掉了多少个
 * 记录答案时候减去即可
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
// int c[N];
int t;
int xa,xb,k;
struct A{
    int x,y;
    bool operator<(const struct A&W){
        if(x < W.x) return true;
        if(x > W.x) return false;
        return y < W.y;
    }
}a[N];
int u[N],v[N];
int cb[N],ub[N];
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
    cin>>t;
    while(t--){
        cin>>xa>>xb>>k;
        rep(i,1,xb) ub[i] = 0;
        rep(i,1,xb) cb[i] = 0;
        rep(i,1,k) cin>>u[i];
        rep(i,1,k){
          cin>>v[i];  
          cb[v[i]] ++;
        } 
        rep(i,1,k){
            a[i] = {u[i],v[i]};
        }
 
        sort(a+1,a+1+k);
        LL ans = 0;
        rep(i,1,k-1){
            int tx = a[i].x, ty = a[i].y;
            int l = i+1, r = k;
            while(l<r){
                int mid = (l+r)>>1;
                if(a[mid].x > tx) r = mid;
                else l = mid+1;
            }
            int uy = a[l].y;
            if(a[l].x == tx) break;
            if(uy == ty){
                l ++, r = k;
                ans += (k-l+1);
                ans -= (cb[ty]-2-ub[ty]);
            }else{
                ans += (k+1-l);
                ans -= (cb[ty]-1-ub[ty]);
            }
            ub[ty] ++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
