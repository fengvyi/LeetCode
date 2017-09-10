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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        ListNode* slow(head), *fast(head), *next;
        while(fast){
            int i = k - 1;
            while(fast && i--) fast = fast->next;
            if(fast){
                next = fast->next;
                reverse(pre, slow, fast, next);
                pre = slow;
                slow = next;
                fast = next;
            }
        }
        return res->next;
    }
    
    void reverse(ListNode* left, ListNode* start, ListNode* end, ListNode* right){
        ListNode* pre(left), *cur(start), *next;
        ListNode* tmp = start;
        while(cur != right){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        left->next = pre;
        tmp->next = right;
    }
};

// Solution 2.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy, *cur(head), *next, *tmp, *p, *ppre, *ccur;
        while(cur){
            p = cur;
            for(int i = 1; i < k && p; i++) p = p->next;
            if(!p) break;
            ppre = pre;
            ccur = cur;
            pre = p->next;
            tmp = p->next;
            while(cur != tmp){
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            ppre->next = pre;
            pre = ccur;
        }
        return dummy.next;
    }
};
