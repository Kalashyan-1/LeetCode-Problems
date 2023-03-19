/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp = head;
        ListNode* tmp2 = head;
        ListNode* next;
        while (tmp != nullptr) {
            next = tmp->next;
            if (tmp == head) {
                tmp->next = nullptr;
            } else {
                tmp->next = tmp2;
            }
            tmp2 = tmp;
            tmp = next;
        }
        return tmp2;
    }

};


