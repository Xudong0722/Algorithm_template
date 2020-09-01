#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5+100;

int a[N];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i = 1; i<=n; i++) scanf("%d",&a[i]);
    
    for(int i = 1; i<=n ;i++) a[i] += a[i-1];
    
    while(m --)
    {
        int l,r;
        
        scanf("%d%d",&l,&r);
        
        printf("%d\n",a[r]-a[l-1]);
    }
    
    
    return 0;
}
