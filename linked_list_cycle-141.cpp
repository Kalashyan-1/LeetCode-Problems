/*

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time complexity O(n2)
// Sapce complexty O(1)


class Solution {
public:
    bool hasCycle(ListNode *head) {
       if (!head) {return head;}
       ListNode* tmp = head;
       ListNode* tmp2 = head->next;
       if (tmp == tmp2) {return true;}
       while (tmp2 != nullptr) {
           while (tmp != tmp2) {
               if (tmp2->next == tmp ) {
                   return true;
               }
               tmp = tmp->next;
           }
           if (tmp->next == tmp) {return true;}
           tmp2 = tmp2->next;
           tmp = head;
       }
       return false;
    }
};


/*

Example:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
*/