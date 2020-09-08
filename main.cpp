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
    void IterateTree(TreeNode **parent, TreeNode **next, TreeNode* root) {
        if (root != nullptr) {
            IterateTree(parent, next, root->left);
            
            root->left = nullptr;
            if (*parent == nullptr) {
                *parent = root;
                *next = *parent;
            }
            else {
                (*next)->right = root;
                *next = (*next)->right;
            }
            
            IterateTree(parent, next, root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = nullptr;
        TreeNode* next = nullptr;
        
        IterateTree(&res, &next, root);
        
        return res;
    }
};
