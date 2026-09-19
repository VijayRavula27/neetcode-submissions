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
    int maxi = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxsum(root);

        return maxi;
    }
    int maxsum(TreeNode* root){
        if(root == nullptr) return 0;

        int left = maxsum(root->left);
        if(left < 0) left = 0;
        int right = maxsum(root->right);
        if(right < 0) right = 0;
        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }
};
