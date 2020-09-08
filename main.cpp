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
    void AddNode(std::vector<TreeNode *> &vec, TreeNode* root) {
        if (root != nullptr) {
            AddNode(vec, root->left);
            root->left = nullptr;
            vec.push_back(root);
            AddNode(vec, root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        std::vector<TreeNode *> vec;
        
        AddNode(vec, root);
        TreeNode* res = nullptr;
        TreeNode* next = res;
        
        if (vec.size() >= 1) {
            res = vec[0];
            next = res;
        }
        
        for (int i = 1; i < vec.size(); ++i) {
            next->right = vec[i];
            next = next->right;
        }
        
        return res;
    }
};
