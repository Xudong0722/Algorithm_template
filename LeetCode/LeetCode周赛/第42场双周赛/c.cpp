class Solution {
public:
    string maximumBinaryString(string b) {
        int n = b.size();
        
        for(int i = 0; i<n; i++){
            if(b[i] == '0'){
                if(i + 1>=n) break;
                if(b[i+1] == '0'){
                    b[i] = '1';
                }else{
                    int j = i+1;
                    int cnt = 0;
                    for(; j<n; j++){
                        if(b[j] == '0') cnt ++;
                    }
                    int k = i;
                    for(int j = 0;j<cnt; j++){
                        b[k++] = '1';
                    }
                    b[k++] = '0';
                    for(; k<n; k++){
                        b[k] = '1';
                    }
                    break;
                }
            }
        }
        return b;
    }
};
