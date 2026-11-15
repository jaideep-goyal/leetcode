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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr= head;

        while(curr) {
            ListNode* nextNode = curr-> next;
            curr -> next = prev;

            prev = curr;
            curr = nextNode;
        }
        return prev;

    }
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return;

        //find the middle node
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        //reverse the second half of linkedlist
        ListNode* second = reverse(slow->next);

        slow -> next = NULL; // split into two halfs

        //merge it
        ListNode* first = head;

        while(second) {
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;

            first -> next = second;
            second -> next = temp1;

            first = temp1;
            second = temp2;
        }
        
    }
};