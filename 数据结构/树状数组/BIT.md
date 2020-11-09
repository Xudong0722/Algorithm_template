~~复习一下树状数组~~

# 树状数组
一种用于处理单点修改和区间查询的数据结构。
**树状数组C的定义： C[x] = Sum   a[x-lowbit(x)+1,x]**, 即数组C表示原数组某一区间段的和。

# lowbit操作
```
int lowbit(int x){
    return x&-x;
}
```

# 单点修改 O(logN)
对于树形结构，我们如果修改一个点的话，对于他祖宗节点的影响是单一的，即我们可以通过一层一层向上更新包含这个节点的所有C数组的值。
```
int update(int u,int x){
    for(int i = u; i<=n; i+=lowbit(i)){
        c[i] += x;
    }
}
```



# 区间查询 O(lonN)
根据树状数组的含义，在求区间和时我们就可以按照如下方法：

**Sum(x)  = C[x] + C[x-lowbit(x)] + C[y-lowbit(y)] + C[z-lowbit(z)] + ... (x,y,z,....>=0)**
其中 y = x-lowbit(x)     z = y-lowbit(y)....

为什么这样求是对的呢？
我们将每个C[i] 展开看看:

Sum(x) = C[x] + C[x-lowbit(x)] + ...

Sum(x) = **Sum**  a[x-lowbit(x)+1,x]   + **Sum**  a[x-lowbit(x)-(y-lowbit(y)+1, x-lowbit(x)] + ...

这里就可以看出来，其实就是把二进制x每次减去低位1即lowbit(x)

以下图为例， **sum(7) = C(7) + C(7-1) + C(6-2) + C(4-4) =  C(7) + C(6) + C(4)**

![BIT](https://upload-images.jianshu.io/upload_images/19138073-c139763f46b8657a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

```
int sum(int x){
    int res = 0;
    for(; x; x-=lowbit(x)){
        res += c[x];
    }
    return res;
}
```
可参考学习的博客：
https://www.cnblogs.com/xenny/p/9739600.html

# 例题
待更
