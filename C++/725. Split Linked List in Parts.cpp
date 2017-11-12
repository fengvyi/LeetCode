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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*>res;
        int len = 0;
        ListNode* head = new ListNode(0), *pre = root, *cur = head, *next, *p = root;
        while(p && ++len) p = p->next;
        int m = len % k, l = len / k;
        while(k--){
            cur->next = pre;
            for(int i = 0; i < l; i++) cur = cur->next;
            if(m) cur = cur->next, m--;
            next = cur->next;
            cur->next = NULL;
            res.push_back(pre);
            pre = next;
            cur = head;
        }
        return res;
    }
};
