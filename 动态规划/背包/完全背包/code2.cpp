#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1010];
int n,w,v,m;

int main()
{
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>v>>w;
        for(int j = v; j<=m; j++){
            dp[j] = max(dp[j],dp[j-v]+w);
        }
    }
    cout<<dp[m];
    return 0;
}
