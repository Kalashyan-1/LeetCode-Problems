/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp = head;
        ListNode* tmp1;
        if (tmp) {

            while (tmp->next != nullptr) {

                if (tmp->next->val == val) {
                    tmp1 = tmp->next->next;
                    delete tmp->next;
                    tmp->next = tmp1;
                } else {
                    tmp = tmp->next;
                }
            }
            if (head->val == val) {
                tmp1 = head->next;
                delete head;;
                head = tmp1;
            }
        }
        return head;
    }
};


