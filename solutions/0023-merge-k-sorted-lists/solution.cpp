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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 0; i<n; i++) {
            ListNode* curr = lists[i];
            while(curr) {
                q.push(curr->val);
                curr = curr->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr2 = dummy;
        while(!q.empty()) {
            int num = q.top();
            q.pop();
            ListNode* curr1 = new ListNode(num);
            curr2->next = curr1;
            curr2 = curr2->next;
        }
        return dummy->next;
    }
};
