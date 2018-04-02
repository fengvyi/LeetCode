/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode res(0);
        res.next = head;
        ListNode* pre = &res, *cur = head, *next = cur ? cur->next : NULL;
        while(cur){
            bool dup = false;
            while(next && next->val == cur->val){
                dup = true;
                next = next->next;
            }
            if(dup){
                cur = next;
                next = next ? next->next : NULL;
                pre->next = cur;
            }
            else{
                pre = cur;
                cur = next;
                next = next ? next->next : NULL;
            }
        }
        return res.next;
    }
};
