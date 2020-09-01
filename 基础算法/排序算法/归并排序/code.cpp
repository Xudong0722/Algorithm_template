#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5+100;

int a[N],t[N];
int n;

void merge_sort(int a[],int l,int r){
    if(l>=r) return ;
    int mid = (l+r)>>1;
    
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    
    int k = 0, i = l, j = mid+1;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            t[k++] = a[i++];
        }else{
            t[k++] = a[j++];
        }
    }
    
    while(i<=mid) t[k++] = a[i++];
    while(j<=r) t[k++] = a[j++];
    
    for(int i = l,j = 0; i<=r; i++){
        a[i] = t[j++];
    }
}

int main()
{
    cin>>n;
    
    for(int i = 0; i<n;i++)
        scanf("%d",&a[i]);
    
    merge_sort(a,0,n-1);
    
    for(int i = 0 ;i<n; i++)
        printf("%d ",a[i]);
    
    return 0;
}
