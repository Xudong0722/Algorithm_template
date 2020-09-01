#include<iostream>
using namespace std;
const int maxn = 1000+10;
int a[maxn][maxn],s[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);

    int n,m,q,x1,x2,y1,y2;
    cin>>n>>m>>q;

    for(int i = 1;i<=n;i++ )
        for(int j = 1;j<=m;j++ )
            cin>>a[i][j];

    for(int i = 1;i<=n;i++ )
        for(int j = 1;j<=m;j++ )
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];   //前缀和


    while(q--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<s[x2][y2] - s[x1-1][y2] -s[x2][y1-1] + s[x1-1][y1-1]<<endl;

    }

    return 0;
}
