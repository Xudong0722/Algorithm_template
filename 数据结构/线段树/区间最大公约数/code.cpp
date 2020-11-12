#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long LL;  //可能会爆int

const int N = 5e5+100;

int n,m;
LL a[N];
struct TreeNode{
    int l,r;
    LL sum;   //区间和
    LL d;    //区间最大公约数
}tr[N*4];

LL gcd(LL a,LL b){
    return b==0? gcd(b,a%b):a;
}

void pushup(TreeNode& rt,TreeNode& l, TreeNode& r){
    rt.sum = l.sum + r.sum;
    rt.d = gcd(l.d, r.d);
}

void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r){
    if(l == r){
        tr[u] = {l,r,a[l]-a[l-1],a[l]-a[l-1]};  //维护差分序列
        return ;
    }
    tr[u] = {l,r,0,0};
    int mid = (l+r)>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int x,int val){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].sum += val;
        tr[u].d += val;
        return ;
    }
    
    int mid = (tr[u].l + tr[u].r)>>1;
    if(mid >=x) modify(u<<1,x,val);
    else modify(u<<1|1,x,val);
    pushup(u);
}

TreeNode query(int u,int l,int r){
    if(l<=tr[u].l && r >=tr[u].r) return tr[u];
    
    int mid = (tr[u].l + tr[u].r )>>1;
    if(mid >=r) return query(u<<1,l,r);
    else if(mid <= l) return query(u<<1|1,l,r);
    else{
        auto left = query(u<<1,l,r);
        auto right = query(u<<1|1,l,r);
        TreeNode ans;
        pushup(ans,left,right);
        return ans;
    }
}
    

int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i = 1; i<=n; ++i) scanf("%lld",&a[i]);
    
    build(1,1,n);  //建树
    char ch[2];
    int l,r;
    LL d;
    while(m--){
        scanf("%s%d%d",&ch,&l,&r);
        if(*ch == 'Q'){
            auto left = query(1,1,l);
            TreeNode right = {0,0,0,0};
            if(l+1<=r) right = query(1,l+1,r);
            printf("%lld\n",abs(gcd(left.sum,right.d)));
        }else{
            scanf("%lld",&d);
            modify(1,l,d);
            if(r+1<=n) modify(1,r+1,-d);
        }
    }
    return 0;
}
