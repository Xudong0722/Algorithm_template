/*
  在最坏情况下，即数组原本是严格单调递减的，那么需要的移动次数是n-1 + n-2 + n-3 + ... + 1 = n*(n-1)/2
  即比题目要求的最大次数少1，等价于只有这种一种情况才不满足要求，那么我们只要遍历一遍数组，确认是不是这种数组即可。
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
//global variable
const int N = 5e4+100;
const int mod = 1e9+7;
int t,n;
int a[N],tmp[N];


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

// LL merge_sort(int x[],int l,int r){
//     if(l>=r) return 0;

//     int mid = (l+r)>>1;
//     LL res = merge_sort(x,l,mid) + merge_sort(x,mid+1,r);

//     int i = l, j = mid+1;
//     int k = 0;
//     while(i<=mid && j<=r){
//         if(x[i] <= x[j]) tmp[k++] = x[i++];
//         else{
//             res += mid-i+1;
//             tmp[k++] = x[j++];
//         }
//     }
//     while(i<=mid) tmp[k++] = x[i++];
//     while(j<=r) tmp[k++] = x[j++];
//     for(int i = l,u = 0; i<=r; i++,u++)x[i] = tmp[u];
//     return res;
// }
//


//code from here! Come on! Have a pleasant experience~
int main()
{
    IO;
    cin>>t;
    while(t--){
        cin>>n;

        rep(i,1,n) cin>>a[i];
        bool flag = false;
        rep(i,2,n){
            if(a[i]>=a[i-1]){
                flag = true;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
