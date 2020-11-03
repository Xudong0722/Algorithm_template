/*
 * Author: Moon-light
 * 分成三种情况讨论
 * 1.只有一位，看是否是8即可
 * 2.有两位，判断这两位的组合
 * 3.大于三位，因为1000是8的倍数，所以我们只用看后三位是否可以整除8即可
 * 枚举三位数中8的倍数，如果原字符串中出现了这三位数，那么就可以找到答案
 * 如果找遍了所有的三位数，原字符串中都没有，那么不能通过重新排列找到答案
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
const int N = 11;
const int mod = 1e9+7;
string s;
int cnt[N];
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

bool check(int t){
    mst(a,0);
    while(t){
        a[t%10] ++;
        t/=10;
    }

    rep(i,0,9){
        if(a[i] > cnt[i]){
            return false;
        }
    }
    return true;
}
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>s;
    int n = s.size();
    rep(i,0,n-1) cnt[s[i]-'0'] ++;

    if(n == 1){
        int t = s[0]-'0';
        if(t==8){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }else if(n == 2){
        int u = s[0]-'0', v = s[1]-'0';
        if((u*10+v)%8 == 0 || (v*10+u)%8 == 0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else{
        for(int i = 104; i<1000; i+=8){
            if(check(i)){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }
    return 0;
}
