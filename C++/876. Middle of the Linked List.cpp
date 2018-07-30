class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto a = head, b = head;
        while(b && b->next) a = a->next, b = b->next->next;
        return a;
    }
};
