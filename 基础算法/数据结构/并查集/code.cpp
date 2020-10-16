//Acwing.836合并集合
//https://www.acwing.com/problem/content/838/
#include<iostream>
using namespace std;
const int maxn  = 1e5+100;

int p[maxn];   //存储每个点的祖宗节点

int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int main(void)
{
    int n,m;
    cin>>n>>m;
    for(int i = 1; i<=n;i++)
        p[i] = i;
    while(m--)
    {
        char op[2];
        int a,b;
        cin>>op>>a>>b;
        if(op[0]=='M') p[find(a)] = find(p[b]);
        else
            if(find(a) == find(b))
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
    }
    return 0;
}
