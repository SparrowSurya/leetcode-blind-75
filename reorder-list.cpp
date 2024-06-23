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
    void reorderList(ListNode* head) {
		if ((head == nullptr) || (head->next == nullptr)) return;

		ListNode *slow = head;
		ListNode *fast = head;

		while (fast != nullptr) {
			if ((fast->next != nullptr) && (fast->next->next != nullptr)) {
				fast = fast->next->next;
				slow = slow->next;
			} else {
				break;
			}
		}

		ListNode *mid = slow;
		ListNode *ptr = head;

		mid = dfs(mid->next, ptr);
		mid->next = nullptr;
	}

	ListNode *dfs(ListNode *node, ListNode *ptr) {
		if (node == nullptr) return ptr;

		ptr = dfs(node->next, ptr);

		ListNode *ptr_next = ptr->next;
		ptr->next = node;
		node->next = ptr_next;
		return ptr_next;
    }
};
