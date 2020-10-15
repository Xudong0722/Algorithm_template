/*
    （为了简化描述过程，我们对一个2*2的瓷砖四个小块编号为
    a b
    c d）
    通过模拟样例我们可以发现，如果要构造一个对称的正方形地块，需要满足三个条件
    1.m是大于0的偶数
    2.对角线上的瓷砖满足： b = c
    3.非对角线的瓷砖：
        所有种类的瓷砖中存在这样两种砖或一种砖： a1 = a2, d1 = d2, b1 = c2, c1 = b2
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
#define per(i,a,b) for(int i = (b);i>=(a); --i)
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
const int N = 110;
const int mod = 1e9+7;
int t,n,m;  
int a[N][4][4];



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
        cin>>n>>m;
        rep(i,1,n){
            cin>>a[i][1][1]>>a[i][1][2]>>a[i][2][1]>>a[i][2][2];
        }

        bool fg = false;
        rep(i,1,n){
            if(a[i][1][2] == a[i][2][1]){   //对角线上的瓷砖
                fg = true;
                break;
            }
        }
        if(!fg || m&1){
            cout<<"NO"<<endl;
            continue;
        }

        fg = false;
        rep(i,1,n){
            int tl = a[i][1][1], tr = a[i][1][2];
            int bl = a[i][2][1], br = a[i][2][2];
            rep(j,1,n){
                int j_tl = a[j][1][1], j_tr = a[j][1][2];
                int j_bl = a[j][2][1], j_br = a[j][2][2];
                if(tl == j_tl && br == j_br && tr==j_bl && bl == j_tr){
                    fg = true;
                    break;
                }
            }
        }
        if(fg){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}
