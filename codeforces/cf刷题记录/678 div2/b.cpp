/*
 * Author: Moon-light
 * Time: 2020-10-27 15:02:47
 * 先构造n-1*n-1个1型矩阵
 * 最后一列和最后一行除最后一个数外放一个数，该数满足+n-1是质数，本身不是质数
 * 再找最后一个数满足上述要求的即可，满足+2*（n-1）是质数，本身不是质数
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
int t,n;
int a[N][N];


//functions
bool isprime(int x){
    if(x<2) return false;
    for(int i = 2; i<=x/i; i++){
        if(x%i==0) return false;
    }
    return true;
}

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

        rep(i,1,n-1){
            rep(j,1,n-1){
                a[i][j] = 1;
            }
        }
        
        int k = 1;
        rep(i,1,1000){
            if(isprime(i+n-1) && !isprime(i)){
                k = i;
                break;  
            }
        }
        rep(i,1,n){
            a[i][n] = k;
            a[n][i] = k;
        }
        int t = (n-1) * k;
        
        for(int i = 1; ; i++){
            if(isprime(t+i)&&!isprime(i)){
                k = i;
                break;
            }
        }
        

        a[n][n] = k;

        rep(i,1,n){
            rep(j,1,n){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
