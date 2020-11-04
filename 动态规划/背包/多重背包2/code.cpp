#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 12010,M = 2010;  //N表示物品的最多个数

int n,m;
int v[N],w[N];
int f[M];

int main()
{
    cin>>n>>m;
    
    int idx = 1;
    for(int i = 1; i<=n; i++){
        int a,b,s;
        cin>>a>>b>>s;
        
        int t = 1;
        while(t<s){
            w[idx] = t*b;
            v[idx++] = t*a;
            s -= t;
            t<<=1;
        }
        w[idx] = s*b;
        v[idx++] = s*a;
    }
    
    n = idx; //组数
    for(int i = 1; i<=n ;i++)
        for(int j = m; j>=v[i] ; j--)
            f[j] = max(f[j],f[j-v[i]] + w[i]);
    
    cout<<f[m]<<endl;
    
    return 0;
}
