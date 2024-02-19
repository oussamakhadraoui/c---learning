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
    int getDecimalValue(ListNode* head) {
        ListNode * temp=head;
        int counter=0,ans=0;
        while(temp!=nullptr){
            counter++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->val==1)
            ans+=pow(2,counter-1);
            counter--;
            temp=temp->next;
        }
        return ans;
    }
};