#include<iostream>
const int maxn = 100000+100;
int a[maxn],b[maxn];
using namespace std;
void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,m,l,r,c;
    cin>>n>>m;

    for(int i = 1;i<=n;i++ ) cin>>a[i];
    for(int i = 1;i<=n;i++ ) insert(i,i,a[i]);

    while(m--)
    {
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    for(int i = 1;i<=n;i++ )
        b[i]+=b[i-1];
    for(int i =1;i<=n;i++ )
        cout<<b[i]<<" ";
    cout<<"\n";
    return 0;
}
