// 没有划掉的数至少具有两个不同的质因子
// 2^k*3  k = log2(n/3)
// x^k*2  k = logx(n/2)
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7, M = 8*N+100,mod = 1e9+7;

typedef long long LL;

int prime[N];
bool st[M];
int n,cnt;
LL ans = 1;

LL qmi(LL a,LL k){
    LL res = 1;
    while(k){
        if(k&1) res = res*a%mod;
        k >>= 1;
        a = a*a%mod;
    }
    return res;
}
LL solve(int x){
    LL k = 1;
    if(x == 2) k = log2(n/3);
    else k = log2(n/2)/log2(x);
    return qmi(x,k);
}
void get_prime(int x){
    for(int i = 2; i<=x; i++){
        if(!st[i]){
            prime[cnt++] = i;
            ans = (ans*solve(i))%mod;
        }
        for(int j = 0; prime[j]*i<=x; j++){
            st[prime[j]*i] = true;
            if(i%prime[j] == 0) break;
        }
    }
}
int main()
{
    cin>>n;
    
    get_prime(n/2);
    
    if(ans==1) cout<<"empty";
    else cout<<ans<<endl;
    
    return 0;
}
