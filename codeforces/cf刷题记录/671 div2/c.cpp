/*
 * Author: Moon-light
 * Time: 2020-10-20 14:51:38
 其实题意理解了很简单，就是最少几轮比赛让所有人都感染（我一开始一位感染之后rating就布不能变了，其实感染只是一个状态，只有killjoy的rating不能变化且他不能参与contest）
 那么就很简单了：
 1.如果所有人一开始的rating都是x，那么0场比赛即可
 2.如果一部分人被感染了，那么只要1场比赛将其他未被感染的分数全变成x，与之相对的变化量放在感染者上
 3.如果没有人被感染，但如果所有的rating之和等于n*x（情况2也包含这种情况），那么也只用一场比赛即可，否则，先通过一场比赛感染一个人，再转换成第2种情况，那么也只要2场即可
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
const int N = 1e3+100;
const int mod = 1e9+7;
int t;  
int n,x;
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
    cin>>t;
    while(t--){
        cin>>n>>x;
        rep(i,1,n) cin>>a[i];
        int iec = 0,sum = 0;
        rep(i,1,n){
            sum += a[i];
            if(a[i] == x) iec++;
        }

        if(iec==n) cout<<0<<endl;
        else{
            if(iec==0){
                if(sum==n*x) cout<<1<<endl;
                else cout<<2<<endl;
            }else cout<<1<<endl;
        }
    }
    return 0;
}
