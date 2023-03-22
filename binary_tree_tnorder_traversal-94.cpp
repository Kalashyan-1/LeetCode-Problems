/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Time complexity O(n)
//Space complexity O(1)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        TreeNode* tmp = root;
        TreeNode* tmp2 = nullptr;
        while (tmp != nullptr) {
            if (tmp->left == nullptr) {
                std::cout << tmp->val;
                res.push_back(tmp->val);
                tmp = tmp->right;
            } else {
                tmp2 = tmp->left;
                while (tmp2->right != nullptr && tmp2->right != tmp) {
                    tmp2 = tmp2->right;
                }
                if (tmp2->right == nullptr) {
                    tmp2->right = tmp;
                    tmp = tmp->left;
                } else {
                    std::cout << tmp2->right->val;
                    res.push_back(tmp2->right->val);
                    tmp2->right = nullptr;
                    tmp = tmp->right;
                }
            }
        }
        return res;
    }
};


/*
Example:
Input: root = [1,null,2,3]
Output: [1,3,2]
*/
