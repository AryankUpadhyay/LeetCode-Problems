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
    bool deleteLeaf(TreeNode* root, int target){
        if(root->left==NULL && root->right==NULL && root->val==target){
            return true;
        }
        bool lf=true, rg=true;
        if(root->left!=NULL){
            lf=deleteLeaf(root->left, target);
        }
        if(root->right!=NULL){
            rg=deleteLeaf(root->right, target);
        }
        if(lf){
            root->left=NULL;
        }
        if(rg){
            root->right=NULL;
        }
        if(lf && rg && root->val==target){
            return true;
        }
        return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL){
            return root;
        }
        deleteLeaf(root, target);
        if(root->left==NULL && root->right==NULL && root->val==target){
            return NULL;
        }
        return root;
    }
};