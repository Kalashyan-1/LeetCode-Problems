/* 

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
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

//Time complexity Q(n2)
//Sapce complexity O(1)
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode* tmp = head;
        ListNode* tmp2 = nullptr;
        ListNode* prev = nullptr;
        ListNode* tmp3 = nullptr;
        while (tmp != nullptr) {
            tmp2 = tmp->next;

            if (prev == nullptr || prev->val >= tmp->val) {
                tmp->next = prev;
                prev = tmp;
            } else {
                tmp3 = prev;
                while (tmp3->next != nullptr && tmp3->next->val < tmp->val) {
                    tmp3 = tmp3->next;
                }
                tmp->next = tmp3->next;
                tmp3->next = tmp;
            }
            tmp = tmp2;
        }
        head = prev;
        return head;
	}
};



// Second Solution
/*
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) {return head;}
        ListNode* tmp = head;
        ListNode* tmp3 = head;
        ListNode* tmp2 = head->next;
        while (tmp2 != nullptr) {
            
            while (tmp3 != tmp2) {
                if (tmp3->val > tmp2->val) {
                    std::swap(tmp3->val, tmp2->val);
                }
                tmp3 = tmp3->next;
            }
            tmp3 = head;
            tmp2 = tmp2->next;
        }
        return head;
    }
};
*/

//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
