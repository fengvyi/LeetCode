/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // Solution 1.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int len = 0;
        ListNode* p = head;
        while(p) p = p->next, len++;
        k = k % len;
        if(k == 0) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(k > 0) fast = fast->next, k--;
        while(fast->next) fast = fast->next, slow = slow->next;
        
        ListNode* res = slow->next;
        
        slow->next = NULL;
        fast->next = head;
        
        return res;
    }
};

// Solution 2.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;
        ListNode* tail(head), *cur(head), *res;
        
        int len = 1;
        while(tail->next) tail = tail->next, len++;
        
        k = k % len;
        if(!k) return head;
        k = len - k;
        
        while(--k) cur = cur->next;
        
        res = cur->next;
        cur->next = NULL;
        tail->next = head;
        
        return res;
    }
};
