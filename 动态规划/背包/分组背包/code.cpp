#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int f[N];
int s[N];
int w[N][N],v[N][N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        cin>>s[i];
        for(int j = 1; j<=s[i]; j++){
            cin>>v[i][j]>>w[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = m; j>=0; j--)
            for(int k = 0; k<=s[i]; k++)
            if(j>=v[i][k])
                f[j] = max(f[j],f[j-v[i][k]] + w[i][k]);
    }
    cout<<f[m]<<endl;
    return 0;
}
