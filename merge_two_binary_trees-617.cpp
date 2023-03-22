/*
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

*/

//Time complexity O(n)
//Sapce complexity O(n)

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


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) {
            return root2;
        } else if (!root2) {
            return root1;
        }

        std::vector<std::pair<TreeNode*, TreeNode*>> vec;
        vec.push_back({root1, root2});
        std::pair<TreeNode*, TreeNode*> tmp;
        while (!vec.empty()) {
            tmp = vec.back();
            vec.pop_back();

            if (!tmp.first || !tmp.second) {
                continue;
            }

            tmp.first->val += tmp.second->val;

            if (!tmp.first->left) {
                tmp.first->left = tmp.second->left;
            } else {
                vec.push_back({tmp.first->left, tmp.second->left});
            }

            if (!tmp.first->right) {
                tmp.first->right = tmp.second->right;
            } else {
                vec.push_back({tmp.first->right, tmp.second->right});
            }
         }
        return root1;
    }
};

/*
Example:

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
*/
