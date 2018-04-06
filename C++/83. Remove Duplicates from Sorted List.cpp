// Recursive
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        auto p = deleteDuplicates(head->next);
        head->next = p;
        return p->val == head->val ? p : head;
    }
};

// Non-recursive
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = head, *cur = head->next;
        while(cur){
            pre->val == cur->val ? pre->next = cur->next : pre = cur;
            cur = cur->next;
        }
        return head;
    }
};
