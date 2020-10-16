/*
  考虑异或操作和按位与操作， 只有1&1 和 0&0 才满足题意
  如果我们将每个数都写成32位二进制的表示，可以发现
  如果两个数的最高位1不在同一位，那么一定不会满足条件，因为1^0 为1
  所以对于答案来说，满足条件的最高位1一定在同一位，所以我们记录每个数的最高位为1的情况即可
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
const int N = 1e5+100;
const int mod = 1e9+7;
LL cnt[40];
bool st[N];
int a[N];
int t,n;    


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
        cin>>n;

        rep(i,1,n) cin>>a[i];
        
        mst(cnt,0);
        mst(st,false);

        LL ans = 0;
        per(i,31,0){
            rep(j,1,n){
                if((a[j]>>i)&1 && !st[j]){
                    cnt[i] ++;   //记录每个数的最高位
                    st[j] = true;
                }
            }
        }

        //假设最高位在30是1的数有n个，那么他对答案的贡献是 1+2+3+4+...+n-1 = n*(n-1)/2
        rep(i,0,31){
            if(cnt[i]) ans += cnt[i]*(cnt[i]-1)/2;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}
