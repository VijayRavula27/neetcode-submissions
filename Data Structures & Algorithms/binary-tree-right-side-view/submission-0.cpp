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
    vector<int> rightSideView(TreeNode* root){
        int level = 1;
        vector<int> ans;
        Right_view(root, ans, level);

        return ans;
    }
    void Right_view(TreeNode* root, vector<int> &ans, int level){
        if(root == nullptr) return;

        if(ans.size() < level){
            ans.push_back(root->val);
        }

        Right_view(root->right, ans, level+1);
        Right_view(root->left, ans, level+1);
    }
};