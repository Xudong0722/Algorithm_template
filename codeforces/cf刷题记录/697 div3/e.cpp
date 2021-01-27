/*
 * Author: Moon-light
 * Time: 2021-01-25 23:00:03
 * 从n个物品中拿k个，拿最大价值的方案数
 * 从小到大排序后，拿最后面k个即是最大价值
 * 我们设这k个物品中最小价值是x，k个物品中拿了m个物品价值大于x的
 * 那么我们就拿了k-m个物品价值是x的，这样只需要记录一下物品价值是x的数量再求C(cnt,k-m)即可
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
// int c[N];
int t;
int n,k;
int a[N];
int C[N][N];

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

void pre_work(){
    rep(i,0,1000){
        rep(j,0,i){
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
        }
    }
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
    pre_work();
    while(t--){
        cin>>n>>k;
        rep(i,1,n){ 
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        int mini = a[n-k+1];
        int more = 0;
        rep(i,n-k+1,n){
            if(a[i] > mini) more ++;
        }
        int cnt = 0;
        rep(i,1,n){
            if(a[i] == mini) cnt++;
        }
        k -= more;

        //ans = C(cnt,k);
        cout<<C[cnt][k]%mod<<endl;

        
    }
    return 0;
}
