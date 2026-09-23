/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root == NULL) return NULL;
        // if(root->val > p->val && root->val > q->val) {
        //     return lowestCommonAncestor(root->left , p , q);
        // } else if (root->val < p->val && root->val < q->val) {
        //     return lowestCommonAncestor(root->right , p , q);
        // } else {
        //     return root;
        // }


         if(root == NULL) return NULL;
        if(root == p || root == q) return root;

     
        TreeNode* leftLca = lowestCommonAncestor(root->left , p , q);
        TreeNode* rightLca = lowestCommonAncestor(root->right , p ,q);
        if(leftLca && rightLca) return root;
        else if(leftLca) return leftLca;
        else return rightLca;
    }
};