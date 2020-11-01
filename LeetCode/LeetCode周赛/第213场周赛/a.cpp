/*
  暴力遍历一遍即可
*/
class Solution {
public:
    vector<bool> st;
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        int a = pieces.size();
        
        for(int i = 0; i<n;){
            int u = i;
            for(int j = 0; j<a; j++){
                int k = 0;
                if(arr[u] != pieces[j][0]) continue;
                while(k<pieces[j].size() && u<n && arr[u] == pieces[j][k]){
                    u++;
                    k++;
                }
                if(k != pieces[j].size()){
                    return false;
                }
                if(u == i){
                    return false;
                }
                break;
            }
            if(u == i){
                return false;
            }
            
            i = u;
        }
        return true;
    }
};
