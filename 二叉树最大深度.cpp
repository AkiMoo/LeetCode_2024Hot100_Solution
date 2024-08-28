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
    int ans = 0;
    int maxDepth(TreeNode* root) {
        return maxfind(root,1);
    }
    void maxfind(TreeNode* root, int deep){
        while(root->left!=nullptr||root->right!=nullptr){
            if(root->left!=nullptr){
                maxfind(root->left,deep+1);
            }
            else if(root->right!=nullptr){
                maxfind(root->right,deep+1);
            }
            else{
                ans = max(ans,deep);
            }
        }
    }
};
