/*
 * Author: Moon_light
 * Solution: 简化公式，求约数
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
const int N = 1;
const int mod = 1e9+7;
// int c[N];
int t;
LL n,ans;

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
vector<LL> get_divisors(LL num)
{
    vector<LL> ans;
    for(LL i = 1; i<=num/i ; i++){
        if(num % i == 0){
            ans.push_back(i);
            if(i != num/i)
                ans.push_back(num/i);
        }
    }
    return ans;
}

//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n;
    auto t = get_divisors(n);
    
    int cnt = t.size();
    
    for(int i = 0; i<cnt; i++){
        LL u = t[i];
        LL q = 2*n/u-u+1;
        if(q%2==0) ans ++;
        // cout<<u<<" "<<q<<endl;
    }
    cout<<ans*2<<endl;
    
    return 0;
}
