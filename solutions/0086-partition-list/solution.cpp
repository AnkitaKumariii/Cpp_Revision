/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyNode1 = new ListNode(0);
        ListNode* dummyNode2 = new ListNode(0);
        ListNode* small = dummyNode1;
        ListNode* large = dummyNode2;
        ListNode* current = head;
        while(current != NULL) {
            if(current->val < x) {
                small->next = current;
                small = small->next;
            }
            else {
                large->next = current;
                large = large->next;
            }
            current = current->next;
        }
        large->next = NULL;
        small->next = dummyNode2->next;
        return dummyNode1->next;
    }
};
