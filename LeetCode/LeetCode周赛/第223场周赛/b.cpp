/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        auto idx = head;
        while(idx){
            n++;
            idx = idx->next;
        }
        int fr = k, sc = n-k+1;
        if(fr == sc) return head;
        
        int i = 1;
        auto x = head;
        while(i!=fr && x && x->next){
            i ++;
            x = x->next;
            if(i == fr) break;
        }

        int j = 1;
        auto y = head;
        while(j != sc && y && y->next){
            j ++;
            y = y->next;
            if(j == sc ) break;
        }
        cout<<y->val<<endl;
        swap(x->val,y->val);
        
        return head;
    }
};
