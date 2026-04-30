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
private:
    ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    while(head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head) return NULL;
        head = reverse(head);
        int maxval = head->val;
        ListNode* curr = head;
        while(curr && curr->next) {
            if(curr->next->val < maxval) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
                maxval = curr->val;
            }
        }
        return reverse(head);
    }
};
