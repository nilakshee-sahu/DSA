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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* front = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || head->next == nullptr)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalf = reverseList(slow);

        while(secondHalf != nullptr){
            if(firstHalf->val != secondHalf->val)
                return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};