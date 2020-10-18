/*
  哈希  O(N)
  记录每个字符第一次出现的位置，然后向后遍历时查表
  如果之前出现过，更新答案
  如果没有出现，插入表中
*/
class Solution {
public:
    map<char,int> h;
    int maxLengthBetweenEqualCharacters(string s) {
        h.clear();
        int n = s.size();
        
        int ans = -1;
        for(int i = 0; i<n; i++){
            if(h.count(s[i])){
                ans = max(ans,i-h[s[i]]-1);
            }else{
                h[s[i]] = i;
            }
        }
        return ans;
    }
};
