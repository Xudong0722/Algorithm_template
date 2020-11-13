/*
    通过此题加深对lazy tag的理解： 
    即对于每一次的区间修改，我们不必将这个区间包含的所有节点立即更新，
    这样的时间消耗是我们无法忍受的，那么可不可以等到用的时候再更新呢
    我们通过引入懒标记或者叫延迟标记，对于某个区间修改，我们不向下一直递归修改，
    事先在节点上打上一个懒标记并更新这个区间的值，等到更新或者查询的时候，如果递归到了这个节点，
    我们将这个懒标记传给他的左右儿子，并且清空自己的懒标记
    
    即如果某个区间得到了懒标记，他不会向下传递，他会先更新自己的值
    等某次修改或者查询走到了这个区间，他将自己的懒标记传递给左右儿子并将自己的懒标记清空
    
    对于此题的懒标记，我们可以先乘后加 这样mul = mul * _mul, add = add*_mul + _add
    而先加后乘 mul = mul * _mul add = add + _add/mul 引入了小数会降低精度，所以我们选择先乘后加
    
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 1e5+100;

int n,m,p;
int a[N];

struct Node{
    int l,r;
    int sum,add,mul;   //需要两个lasy tag
}tr[N*4];

void pushup(int u){
    tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum)%p;
}

void solve(Node& rt,int add,int mul){
    rt.sum = ((LL)rt.sum * mul + (LL)(rt.r-rt.l+1)*add)%p;  //更新自己的值
    rt.mul = (LL)rt.mul * mul %p;              //为自己打上标记
    rt.add = ((LL)rt.add * mul + add)%p;
}

void pushdown(int u){
    solve(tr[u<<1],tr[u].add,tr[u].mul);  //传给左右儿子懒标记
    solve(tr[u<<1|1],tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;   //清空自己的标记
}

void build(int u,int l,int r){
    if(l == r){
        tr[u] = {l,r,a[l],0,1};
        return ;
    }
    tr[u] = {l,r,0,0,1};
    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int l,int r,int add,int mul){
    if(l<=tr[u].l && r>=tr[u].r) {
        solve(tr[u],add,mul);
        return ;
    }
    
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >>1;
    if(mid >= l) modify(u<<1,l,r,add,mul);
    if(r > mid) modify(u<<1|1,l,r,add,mul);
    pushup(u);
    
}

int query(int u,int l,int r){
    if(l<=tr[u].l && r>=tr[u].r){
        return tr[u].sum;
    }
    
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) >>1;
    int res = 0;
    if(mid >=l) res = query(u<<1,l,r);
    if(r >mid) res = (res + query(u<<1|1,l,r))%p;
    return res;
}
int main()
{
    scanf("%d%d",&n,&p);
    
    for(int i = 1; i<=n; ++i) scanf("%d",&a[i]);
    build(1,1,n);
    
    scanf("%d",&m);
    int op,t,g,c;
    while(m--){
        scanf("%d%d%d",&op,&t,&g);
        
        if(op == 1){
            scanf("%d",&c);
            modify(1,t,g,0,c);
        }else if(op == 2){
            scanf("%d",&c);
            modify(1,t,g,c,1);
        }else{
            printf("%d\n",query(1,t,g));
        }
    }
    
    return 0;
}
