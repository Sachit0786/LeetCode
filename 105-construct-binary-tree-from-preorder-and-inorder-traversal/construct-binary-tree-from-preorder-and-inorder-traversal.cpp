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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int &currIndex){
        if(start>end){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[currIndex++]);

        int i;
        for(i=start; i<end; i++){
            if(inorder[i]==root->val){
                break;
            }
        }

        TreeNode* leftSubTree = constructTree(preorder, inorder, start, i-1, currIndex);
        TreeNode* rightSubTree = constructTree(preorder, inorder, i+1, end, currIndex);

        root->left = leftSubTree;
        root->right = rightSubTree;

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int currIndex = 0;
        TreeNode* root = constructTree(preorder, inorder, 0, preorder.size()-1, currIndex);
        return root;   
    }
};