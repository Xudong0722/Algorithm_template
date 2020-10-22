/*
 * Author: Moon-light
 * Time: 2020-10-21 23:46:07
 * 先离散化
 * 如果匪帮的种类数目是1，那么一定无解，否则可以把另一个匪帮的地区作为中间区
 * 构造路的话，直接让一个种类鱼其他所有种类的相连，再让第二个种类的与第一个种类中剩余的相连即可
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
const int N = 5010;
const int mod = 1e9+7;
int t;
int x,cnt[N];
VVI h;
int n,idx,mx_cnt;
map<int,int> st;

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
        h = VVI(N);
        st.clear();
        mst(cnt,0);
        mx_cnt = 0,idx = 0;
        rep(i,1,n){
            cin>>x;
            if(!st.count(x)){
                st[x] = ++idx;
                cnt[idx]++;
                h[idx].pb(i);
                mx_cnt = max(mx_cnt,cnt[idx]);
            }else{
                cnt[st[x]] ++;
                h[st[x]].pb(i);
                mx_cnt = max(mx_cnt,cnt[idx]);
            }
        }

        if(idx==1){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            int f = h[1][0];
            rep(i,2,idx){
                int m = h[i].size();
                rep(j,0,m-1){
                    cout<<f<<" "<<h[i][j]<<endl;
                }
            }
            int se = h[2][0];
            rep(i,1,h[1].size()-1){
                cout<<h[1][i]<<" "<<se<<endl;
            }
        }
    }
    return 0;
}
