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
    void reorderList(ListNode* head) { 
        if (!head || !head->next) return;
        ListNode* slow = head; 
        ListNode* fast = head;  
        while (fast && fast->next) {
            slow = slow->next;   
            fast = fast->next->next;   
        }
        ListNode* curr = slow->next; 
        slow->next = NULL;  
        ListNode* prev = NULL;
        while(curr) {
            ListNode* temp = curr->next; 
            curr->next = prev;  
            prev = curr;   
            curr = temp;     
        }
        ListNode* curr1 = head;
        curr = prev;
        while(curr) {
            ListNode* temp1 = curr1->next;
            ListNode* temp2 = curr->next;
            curr1->next = curr;
            curr->next = temp1;
            curr1 = temp1;
            curr = temp2;
        }
    }
};
