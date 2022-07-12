class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val > key) {
            root->left = deleteNode(root->left ,key);
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right ,key);
        }
        else {
            if(root->left == NULL) return root->right ;
            if(root->right == NULL) return root->left ;
            root->val = successor(root->right);
            root->right = deleteNode( root->right , root->val);
        }
        return root;
    }    
    
    private:
    int successor(TreeNode* root){
        if(root ==NULL){
            return -1;
        }
        if(root->left == NULL){
            return root->val;
        }
         return successor(root->left);
    }
    
};