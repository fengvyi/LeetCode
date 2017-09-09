/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

// Solution 1: O(n^2)
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return NULL;
		for (int i = 0, j = 1; j < lists.size(); i++, j++)
			lists[j] = mergeTwoLists(lists[i], lists[j]);
		return *(lists.end() - 1);
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 || !l2) return l1 ? l1 : l2;
		ListNode head(0);
		ListNode* cur = &head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;
		return head.next;
	}
};

// Solution 2: O(nlogn)
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto comp = [](int a, int b) { return a > b; };
		priority_queue<int, vector<int>, decltype(comp)>pq(comp);
		for (auto x : lists)
			while (x) pq.push(x->val), x = x->next;
		ListNode head(0);
		ListNode* cur = &head;
		while (!pq.empty()) {
			ListNode* node = new ListNode(pq.top());
			cur->next = node;
			cur = cur->next;
			pq.pop();
		}
		return head.next;
	}
};

// Or just store the ListNode* in priority_queue.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b){ return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>pq(comp);
        for(auto x: lists)
            while(x) pq.push(x), x = x->next;
        ListNode head(0);
        ListNode* cur = &head;
        while(!pq.empty()){
            cur->next = pq.top();
            cur = cur->next;
            pq.top()->next = NULL;
            pq.pop();
        }
        return head.next;
    }
};
