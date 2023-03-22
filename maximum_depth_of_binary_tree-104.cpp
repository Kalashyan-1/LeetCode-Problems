/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
//Space complexity O(n)


class Solution {
public:
    int maxDepth(TreeNode* root) {
       if (!root) {
        return 0;
	   }
    TreeNode* tmp = nullptr;
    std::queue<TreeNode*> queue;
    int size = 0;
    int height = 0;
    queue.push(root);

    while (!queue.empty()) {
        size  = queue.size();
        ++height;
        for (int i = 0; i < size; ++i) {
            tmp = queue.front();
            queue.pop();
            if (tmp->left) {
                queue.push(tmp->left);
            }
            if (tmp->right) {
                queue.push(tmp->right);
            }
        }
    }
    return height;
    }
};



/*
Example:

Input: root = [3,9,20,null,null,15,7]
Output: 3
*/
