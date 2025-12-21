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

        ListNode* newHead = nullptr;

        while (head) {
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;

            // case 1: empty sorted list OR insert at beginning
            if (!newHead || temp->val <= newHead->val) {
                temp->next = newHead;
                newHead = temp;
            }
            else {
                // find correct position
                ListNode* curr = newHead;
                while (curr->next && curr->next->val < temp->val) {
                    curr = curr->next;
                }
                temp->next = curr->next;
                curr->next = temp;
            }
        }
        return newHead;
    }
};