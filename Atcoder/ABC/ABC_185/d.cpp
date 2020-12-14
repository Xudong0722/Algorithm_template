/*
 * Author: Moon-light
 * 
 * 思路：因为不能碰到蓝色的方块，所以我们只能找蓝色方块分割开的白色序列中找最小的连续的子序列
 * 然后求次数即可，注意首尾的边界情况
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
LL n,m;
LL a[N];


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
    cin>>n>>m;

    for(int i = 1; i<=m; i++){
        cin>>a[i];
    }   
    sort(a+1,a+1+m);

    if(m == 0){
        cout<<1<<endl;
        return 0;
    }
    if(n == m) {
        cout<<0<<endl;
        return 0;
    }
    
    LL range = a[1] - 1;
    LL last = a[1];
    for(int i = 2; i<=m; i++){
        LL t = a[i] - last - 1;
        if(range  == 0) range = t;
        else if(t > 0) range = min(range,t);
        last = a[i];
    }
    if(n > last){
        if(range == 0) range = (n-last);
        else range = min(range,n-last);
    }
        
    //cout<<range<<endl;
    LL ans = 0;
    last = a[1];
    if(a[1] > 1){
        ans += (a[1]-2)/range+1;
    }
    for(int i = 2; i<=m; i++){
        int cnt = a[i]-last-1;
        ans += (cnt-1)/range+1;
        last = a[i];
    }
    if(n>last)
        ans += (n-last-1)/range + 1;
    cout<<ans<<endl; 
    return 0;
}
