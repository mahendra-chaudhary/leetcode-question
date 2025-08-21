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
    ListNode* reverseList(ListNode* head) {


    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next; // अगला node याद रखो
        curr->next = prev;     // link को उल्टा कर दो
        prev = curr;           // prev को आगे बढ़ाओ
        curr = nextNode;       // curr को आगे बढ़ाओ
    }

    return prev; 
    }
};