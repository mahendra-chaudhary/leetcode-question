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
    ListNode* convertarraytolinklist(vector<int>& arr){
        // Create a dummy node to serve
        // as the head of the linked list
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        int n  = arr.size();

        for(int i = 0;i<n;i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }


        return dummyNode->next;

    }

   
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<int> arr;

        int n = lists.size();

        for(int i = 0;i<n;i++){
            ListNode* temp = lists[i];
            
            while(temp != NULL) {
                arr.push_back(temp->val);
                // move the next node 
                temp = temp->next;

            }

        } // sort the arry

        sort(arr.begin(),arr.end());



        return convertarraytolinklist(arr);




        
    }
};