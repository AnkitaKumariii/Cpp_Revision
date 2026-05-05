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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        k = k % n; 
        if (k == 0) return head;
        for(int i = 0; i<k; i++) {
            ListNode* prev = nullptr;
            ListNode* temp = head;
            while (temp->next) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
