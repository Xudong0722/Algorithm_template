/*
 * Author: Moon-light
 * Time: 2020-10-20 14:51:38
 与d1的构造方法一模一样
 只需要在统计cheap ice sphere的时候再遍历一遍数组即可
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
const int N = 1e5+100;
const int mod = 1e9+7;
int t,n;
int a[N];



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
    cin>>n;
    VI ans(n+1);
    priority_queue<int,vector<int>,greater<int>> hp;
    rep(i,1,n){ 
        cin>>a[i];
        hp.push(a[i]);
    } 

    int cnt = 0;
    for(int i = 2; i<=n; i+=2){
        int t = hp.top();
        hp.pop();
        ans[i] = t;
    }
    for(int i = 1; i<=n; i+=2){
        int t = hp.top();
        hp.pop();
        ans[i] = t;
    }
    if(n<=2){
        cout<<0<<endl;
        rep(i,1,n) cout<<a[i]<<" ";
    }else{
        for(int i = 2; i<n; i+=2){
            if(ans[i] < ans[i-1] && ans[i] < ans[i+1]) cnt++;
        }
        cout<<cnt<<endl;
        rep(i,1,n) cout<<ans[i]<<" ";
    }
    
    return 0;
}
