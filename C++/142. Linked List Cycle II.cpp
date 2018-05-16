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
    ListNode *detectCycle(ListNode *head) {
        auto one = head, two = head, meet = head;
        while(two && two->next){
            one = one->next;
            two = two->next->next;
            if(one == two){
                meet = one;
                break;
            }
        }
        if(!two || !two->next) return NULL;
        auto p = head;
        while(p != meet){
            p = p->next;
            meet = meet->next;
        }
        return p;
    }
};
