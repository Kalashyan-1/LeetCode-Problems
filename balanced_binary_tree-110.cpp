
/*
Given a binary tree, determine if it is height-balanced
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

    bool isBalanced(TreeNode* root) {

    if (!root) return true;

    std::vector<TreeNode*> vec;
    vec.push_back(root);
    std::vector<std::pair<int, int>> vec2;
    vec2.push_back({depth(root->left), depth(root->right)});
    std::pair<int, int> p;
    TreeNode* tmp;
    while (!vec.empty()) {
        tmp = vec.back();
        vec.pop_back();
        if (tmp->left) {
            vec.push_back(tmp->left);
        }
        if (tmp->right) {
            vec.push_back(tmp->right);
        }

        p = vec2.back();
        if (!(-1 <= (p.first - p.second) && (p.first - p.second) <= 1)) {
            return false;
        }
        vec2.pop_back();
        vec2.push_back({depth(tmp->left), depth(tmp->right)});

    }
        return true;
    }

private:
    int depth(TreeNode* root);
};

int Solution::depth(TreeNode* root) {
     if (!root) {return 0;}
     int depth = 0;
     int size;
     std::queue<TreeNode*> q;
     TreeNode* tmp;
     q.push(root);
     while (!q.empty()) {
        size = q.size();
        ++depth;
        for (int i = 0; i < size; ++i) {
            tmp = q.front();
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
     }
     return depth;
 }


/*
Example:

Input: root = [3,9,20,null,null,15,7]
Output: true
*/





