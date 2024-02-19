#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
 ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        //step1: find the middle
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }

        //step2: reverse the linked list after middle
        ListNode* reverseKaHead = reverseLL(slow->next);
        slow->next = reverseKaHead;

        //step3: start comparing both halves
        ListNode* temp1 = head;
        ListNode* temp2 = reverseKaHead;

        while(temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        return true;
    }
};