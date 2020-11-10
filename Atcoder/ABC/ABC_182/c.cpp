/*
 * Author: Moon-light
 * 题意：最少删掉几个数，使得剩下的数字是3的倍数
 * 可以使用二进制枚举，如果某一位是1就将这一位删掉，然后看剩下的数字是否是3的倍数，是否比当前答案小，
 * 是则更新答案，否则继续遍历下一个方案
 * 时间复杂度： 二进制枚举是O(n*2^n) n是数字位数
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
const int N = 1110;
const int mod = 1e9+7;
bool st[N];
int n;
string s;
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

int check(LL x){
    int res = 0;
    rep(i,0,31){
        if(x>>i&1) res++;
    }
    return res;
}

LL solve(LL x){
    mst(st,1);
    LL res = 0;
    for(int j = 0;j<n; j++){
        if(x>>j&1) st[j] = false;
    }

    for(int j = 0;j<n; j++){
        if(!st[j]) continue;
        res = res*10 + a[j];
    }
    return res;
}
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>s;

    n = s.size();

    LL mul = 0;
    for(int i = 0; i<n; i++){
        a[i] = s[i]-'0';
        mul = mul*10 + a[i];
    }
    if(mul % 3 == 0){
        cout<<0<<endl;
        return 0;
    }
    int ans = 20;
    for(LL i = 1; i<1<<n; i++){
        LL t = solve(i);
        if(t % 3 == 0){
            ans = min(ans,check(i));
        }
    }
    if(ans !=20 && ans != n)
        cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
