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
void push_back(ListNode* &head, ListNode* &tail, int val){
        ListNode* newNode = new ListNode(val);

        if(head != NULL){
            tail->next = newNode;
            tail = newNode;
        }
        else{
            head = tail = newNode;
            return;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = l1;
        ListNode* second = l2;
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        int carry = 0;
        while(first || second || carry){
            int val1 = first? first->val : 0;
            int val2 = second? second->val : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            carry = sum / 10;
            
            push_back(ansHead, ansTail, digit);

            if(first) first = first->next;
            if(second) second = second->next;
        }
        return ansHead;
    }
};