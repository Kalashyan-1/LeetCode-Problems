/* 

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

*/


//Time complexity O(m + n)
//Space complexity O(m + n)


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* marged = new ListNode;
        ListNode* tmp = marged;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                marged->next = list1;
                list1 = list1->next;
            } else {
                marged->next = list2;
                list2 = list2->next;
            }
            marged = marged->next;
        }

        while (list1) {
            marged->next = list1;
            list1 = list1->next;
            marged = marged->next;
        }

        while (list2) {
            marged->next = list2;
            list2 = list2->next;
            marged = marged->next;
        }

        return tmp->next;
    }
};





/*

Example:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/
