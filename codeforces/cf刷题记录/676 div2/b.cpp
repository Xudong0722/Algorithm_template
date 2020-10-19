/*
 * Author: Moon-light
 * Time: 2020-10-19 15:34:42
 容易发现，我们只要关注s的右边，s的下边，f的上边以及f的左边这四个数即可
 保证最后s旁边的两位都是1，f旁边的两位都是0 或者  s旁边的两位都是0，f旁边的两位都是1
 这样无论他选则0还是1，都不可能走到(n,n)
 分类讨论即可
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
const int N = 250;
const int mod = 1e9+7;
int t,n;
char s[N][N];



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

void out(int x){
    cout<<x<<'\n';
}
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>t;
    while(t--){
        cin>>n;

        rep(i,1,n){
            rep(j,1,n) cin>>s[i][j];
        }
        
        int s_right = s[1][2]=='1'?1:0;
        int s_bottom = s[2][1]=='1'?1:0;
        int f_top = s[n-1][n]=='1'?1:0;
        int f_left = s[n][n-1]=='1'?1:0;

        int cnt_s = s_right+s_bottom;
        int cnt_f = f_left+f_top;

        if(cnt_s==2 && cnt_f==0){
            out(0);
        }else if(cnt_s==0 && cnt_f==2){
            out(0);
        }else if(cnt_s==0 && cnt_f==1){
            out(1);
            if(!f_top){
                cout<<n-1<<" "<<n<<endl;
            }else{
                cout<<n<<" "<<n-1<<endl;
            }
        }else if(cnt_f==0 && cnt_s==1){
            out(1);
            if(!s_right){
                cout<<1<<" "<<2<<endl;
            }else{
                cout<<2<<" "<<1<<endl;
            }
        }else if(cnt_s==2 && cnt_f==2){
            out(2);
            cout<<1<<" "<<2<<endl;
            cout<<2<<" "<<1<<endl;
        }else if(!cnt_s && !cnt_f){
            out(2);
            cout<<1<<" "<<2<<endl;
            cout<<2<<" "<<1<<endl;
        }else if(cnt_s==2 && cnt_f==1){
            out(1);
            if(f_left){
                cout<<n<<" "<<n-1<<endl;
            }else{
                cout<<n-1<<" "<<n<<endl;
            }
        }else if(cnt_s==1 && cnt_f==2){
            out(1);
            if(s_bottom){
                cout<<2<<" "<<1<<endl;
            }else{
                cout<<1<<" "<<2<<endl;
            }
        }else{
            out(2);
            if(s_right && f_left){
                cout<<1<<" "<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
            }else if(s_right && f_top){
                cout<<1<<" "<<2<<endl;
                cout<<n<<" "<<n-1<<endl;
            }else if(s_bottom && f_top){
                cout<<2<<" "<<1<<endl;
                cout<<n<<" "<<n-1<<endl;
            }else{
                cout<<2<<" "<<1<<endl;
                cout<<n-1<<" "<<n<<endl;
            }
        }
    }
    return 0;
}
