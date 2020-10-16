//Acwing》835Trie字符串统计
//https://www.acwing.com/problem/content/837/
#include<iostream>
using namespace std;
const int maxn = 1e5+100;

int son[maxn][26],letter[maxn],idx = 0;   
char str[maxn];
//son数组存的是每个节点的子节点
//letter[x]表示以x编号为结尾的节点的单词数目
//idx类比于链表里的idx，表示节点的编号

void insert(char* str)
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    letter[p]++;
}
int query(char* str)
{
    int p = 0;
    for(int i = 0;str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return letter[p];
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        cin>>op>>str;
        if(*op=='I')insert(str);
        if(*op=='Q')cout<<query(str)<<endl;
    }
    return 0;
}
