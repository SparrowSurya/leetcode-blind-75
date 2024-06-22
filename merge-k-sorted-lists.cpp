#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
		if (lists.size() == 1) return lists[0];

		int mid = lists.size() / 2;
		vector<ListNode*> lt(lists.begin(), lists.begin()+mid);
		vector<ListNode*> rt(lists.begin()+mid, lists.end());

		ListNode* left = mergeKLists(lt);
		ListNode* right = mergeKLists(rt);
		
		return merge(left, right);
    }

	ListNode* merge(ListNode* list1, ListNode* list2) {
		ListNode *dummy = new ListNode();
		ListNode *ptr = dummy;

		while ((list1 != nullptr) && (list2 != nullptr)) {
			if (list1->val <= list2->val) {
				ptr->next = list1;
				list1 = list1->next;
			} else {
				ptr->next = list2;
				list2 = list2->next;
			}
			ptr = ptr->next;
		}

        if (list1 != nullptr) ptr->next = list1;
        if (list2 != nullptr) ptr->next = list2;r

		return dummy->next;
	}
};
