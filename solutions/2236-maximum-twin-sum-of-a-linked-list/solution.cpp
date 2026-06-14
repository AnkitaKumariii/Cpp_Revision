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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode *curr = head;
        while(curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        int maxi = 0;
        int n = st.size();
        curr = head;
        for(int i = 0; i<n/2; i++) {
            maxi = max(maxi, curr->val + st.top());
            st.pop();
            curr = curr->next;;
        }
        return maxi;
    }
};
