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
    void Inorder(TreeNode* root, vector<int> &inorder){
        if(root==NULL){
            return;
        }

        Inorder(root->left, inorder);
        inorder.push_back(root->val);
        Inorder(root->right, inorder);
    }

    TreeNode* createBST(vector<int> inorder, int start, int end){
        if(start>end){
            return nullptr;
        }

        int mid = start + (end-start)/2;
        TreeNode* leftSubtree = createBST(inorder, start, mid-1);
        TreeNode* rightSubtree = createBST(inorder, mid+1, end);
        TreeNode* rootElement = new TreeNode(inorder[mid], leftSubtree, rightSubtree);

        return rootElement;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL){
            return nullptr;
        }   
        vector<int> inorder;
        Inorder(root, inorder);
        int n = inorder.size();

        return createBST(inorder, 0, n-1);
    }
};