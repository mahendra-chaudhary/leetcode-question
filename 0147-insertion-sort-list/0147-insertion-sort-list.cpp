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
    ListNode* insertionSortList(ListNode* head) {


        ListNode* dummy = new ListNode(1000);

        while(head){
            ListNode* next = head->next;
            ListNode* temp = dummy ;



        while(temp->next && temp->next->val < head->val){
            temp = temp->next;
        }
            head->next = temp->next;
            temp->next = head;
            head = next;


        }

        return dummy->next;

        // while (head) {
        //     ListNode* temp = head;
        //     head = head->next;
        //     temp->next = nullptr;

        //     // case 1: empty sorted list OR insert at beginning
        //     if (!newHead || temp->val <= newHead->val) {
        //         temp->next = newHead;
        //         newHead = temp;
        //     }
        //     else {
        //         // find correct position
        //         ListNode* curr = newHead;
        //         while (curr->next && curr->next->val < temp->val) {
        //             curr = curr->next;
        //         }
        //         temp->next = curr->next;
        //         curr->next = temp;
        //     }
        // }
        // return newHead;
    }
};