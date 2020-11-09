/*
题目地址：https://www.acwing.com/problem/content/248/

 树状数组的板子题，题目要求某个区间加一个数，查询某一个元素的值
 虽然像是区间修改，单点查询，但我们可以通过构建差分数组转换为单点修改，区间查询，也即树状数组的问题

*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5+100;

typedef long long LL;

int a[N];
LL c[N];
int n,m;

int lowbit(int x){
    return x&-x;
}

LL update(int u,int x){
    for(int i = u; i<=n; i+=lowbit(i)){
        c[i] += x;
    }
}


LL sum(int x){
    LL res = 0;
    for(; x; x-=lowbit(x)){
        res += c[x];
    }
    return res;
}
int main()
{
    cin>>n>>m;
    
    for(int i = 1; i<=n; i++) cin>>a[i];
    
    for(int i = 1; i<=n; i++) update(i,a[i]-a[i-1]);  //构建差分数组
    
    while(m--)
    {
        char op[2];
        int l,r,d;
        scanf("%s",op);
        if(*op == 'C')
        {
            cin>>l>>r>>d;
            update(l,d);
            update(r+1,-d);
        }
        else
        {
            scanf("%d",&l);
            cout<<sum(l)<<endl;
        }
    }
    return 0;
}

