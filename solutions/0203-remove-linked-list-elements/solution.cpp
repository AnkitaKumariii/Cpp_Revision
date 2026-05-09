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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        while(head && head->val == val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        ListNode *temp = head;
        ListNode* prev = NULL;
        while(temp) {
            if(temp->val == val) {
                prev->next = prev->next->next;
                ListNode* del = temp;
                temp = temp->next;
                delete del;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
