
#include <bits/stdc++.h>
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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* ans = head;

        while(head) {
            while(!st.empty() && head->val > st.top()->val) st.pop();
            if (!st.empty()) st.top()->next = head;
            else ans = head;

            st.push(head);
            head = head->next;
        }

        return ans;
    }
};