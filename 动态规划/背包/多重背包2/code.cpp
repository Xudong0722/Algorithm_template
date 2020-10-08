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
    
    int idx = 0;
    for(int i = 1; i<=n ;i++)
    {
        int a,b,s;
        cin>>a>>b>>s;
        
        int k = 1; 
        while(k<=s)
        {
            idx++;
            v[idx] = a * k;
            w[idx] = b * k;
            s-=k;
            k<<=1;
        }
        if(s>0)
        {
            idx++;
            w[idx] = b * s;
            v[idx] = a * s;
        }
    }
    
    n = idx; //组数
    for(int i = 1; i<=n ;i++)
        for(int j = m; j>=v[i] ; j--)
            f[j] = max(f[j],f[j-v[i]] + w[i]);
    
    cout<<f[m]<<endl;
    
    return 0;
}
