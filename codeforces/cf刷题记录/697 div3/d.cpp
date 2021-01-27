/*
 * Author: Moon-light
 * Time: 2021-01-25 23:00:03
 * 分别对b=1和b=2的应用按空间从大到小进行排序
 * 假设我们卸载了L个b=1的应用，R个b=2的应用，答案就是L+R*2
 * 对于当前的答案，如果我们继续向后删除一个b=1的应用，R只可能减小不可能增加
 * 那么我们可以令R=count(b=2),L = 0， 然后用双指针维护序列
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
int t,n,m;
int a[N],b[N];
int c1[N],c2[N];

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



bool cmp(int x,int y){
    return x>y;
}
//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>t;
    while(t--){
        cin>>n>>m;

        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>b[i];
        int cnt1 = 0, cnt2 = 0;
        rep(i,1,n){
            if(b[i] == 1){
                c1[++cnt1] = a[i];
            } 
            else {
                c2[++cnt2] = a[i];
            }
        }
        
        sort(c1+1,c1+1+cnt1,cmp);
        sort(c2+1,c2+1+cnt2,cmp);

        LL res = 0, sum = 0;
        int l = 0, r = cnt2;
        rep(i,1,cnt2){
            res += c2[i];
        }
        int ans = INT_MAX;
        for(; l<=cnt1; l++){
            sum += c1[l];
            while(r >= 1 && res + sum - c2[r] >= m){
                res -= c2[r--];
            }
            // cout<<l<<" "<<r<<" "<<res<<" "<<sum<<endl;
            if(res + sum >= m) ans = min(ans,2*r+l);
        }

        if(ans == INT_MAX) cout<<"-1"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
