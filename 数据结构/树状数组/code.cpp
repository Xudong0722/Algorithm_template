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
