/*
 * Author: Moon-light
 * Time: 2020-10-21 23:46:07
 * 如果所有的食人鱼体积一样，那么没有优势食人鱼
 * 否则，我们一定能找到一个优势食人鱼
 * 这样想，我们找到体积最大的鱼，只要这些鱼两端或者一端的体积比它小，它就是一条优势食人鱼
 * 如果这些鱼周围没有满足条件的，那么肯定是第一种情况
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
const int N = 3e5+100;
const int mod = 1e9+7;
int t;
int n,a[N];

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

        bool flag = true;
        int mx = 0;
        rep(i,1,n){
            cin>>a[i];
            mx = max(mx,a[i]);
            if(i>1 && a[i] != a[i-1]) flag = false;
        }
        a[0] = a[n+1] = 1e9+7;
        if(flag) cout<<-1<<endl;
        else{
            int ans;
            if(n==1) cout<<1<<endl;
            else{ 
                rep(i,1,n){
                    if(a[i] == mx){
                        if(a[i] >a[i-1] || a[i]>a[i+1]){
                            ans = i;
                            break;
                        }
                    }
                }
                cout<<ans<<endl;
            }
        }

    }
    return 0;
}
