class Solution {
public:
    void add(char &x,int y){
        x = '0' + (x-'0'+y)%10;
    }
    
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        
        string ans (n,'9');
        
        //b是偶数， 那么无论如何轮转，都只有一开始在奇数位上的数可以累加
        //b是奇数， 那么轮转一次后，原来所有在偶数位上的都来到奇数位，可以进行累加操作
        //由于这些奇数集和偶数集没有交集，所以先后顺序对答案没有影响
        
        if(b&1){
            for(int i = 0; i<10; ++i){
                for(int j = 1; j<n; j+=2) add(s[j],a); 
                for(int j = 0; j<10; j++){
                    for(int k = 0; k<n; k+=2) add(s[k],a);
                    string t = s;
                    for(int u = 0; u<n; u++){
                        t = t.substr(n-b)+t.substr(0,n-b);
                        ans = min(ans,t);
                    }
                }
                
            }
        }else{
            for(int i = 0; i<10; ++i){
                for(int j = 1; j<n; j+=2) add(s[j],a);
                string t = s;
                for(int u = 0; u<n; u++){
                    t = t.substr(n-b) + t.substr(0,n-b);
                    ans = min(ans,t);
                }
            }
        }
        return ans;
    }
};
