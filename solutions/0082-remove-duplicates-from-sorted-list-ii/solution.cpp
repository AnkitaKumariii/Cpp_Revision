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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(curr) {
            if(curr->next != NULL && curr->val == curr->next->val) {
                int data = curr->val;
                while(curr && curr->val == data) {
                    curr = curr->next;
                }
                prev->next = curr;
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
