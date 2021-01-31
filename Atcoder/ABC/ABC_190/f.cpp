/*
 * Author: Moon_light
 * Solution: 逆序对
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
// int c[N];
int t;
int n;
int a[N],tmp[N];
int c[N],b[N];
//functions
LL qmi(LL a,LL k,LL mod){
    LL res = 1;
    while(k){
        if(k&1) res = res*a%mod;
        k >>= 1;
        a = a*a%mod;
    }
    return res%mod;
}
int gcd(int a,int b) {
    return b==0? a:gcd(b,a%b);
}
bool isprime(int x){
    if(x<2) return false;
    for(int i = 2; i<=x/i; i++){
        if(x%i == 0) return false;
    }
    return true;
}

LL merge_sort(int q[], int l, int r)
{
    if (l >= r) return 0;

    int mid = l + r >> 1;

    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else
        {
            res += mid - i + 1;
            tmp[k ++ ] = q[j ++ ];
        }
    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];

    return res;
}

// void update(int u,int x){
//     for(int i = u; i<=n; i+=lowbit(i)){
//         c[i] += x;
//     }
// }
// LL sum(int x){
//     LL res = 0;
//     for(; x; x-=lowbit(x)){
//         res += c[x];
//     }
//     return res;
// }
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>n;

    rep(i,0,n) {
        cin>>b[i];
        c[i] = b[i];
    }
    
    LL ans = merge_sort(b,0,n-1);

    cout<<ans<<endl;
    int idx = 0 ;
    LL k = c[idx];
    rep(i,1,n-1){
        int u = (k==0?0:k);
        ans = ans - u + (n-1-k);
        cout<<ans<<endl;
        k = c[++idx];  
    }
    return 0;
}
