Recursive:
class Solution
{
    public:
    Node *prev=NULL;
    void flatten(Node *root)
    {
        if(!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right=prev;
        root->left=NULL;
        prev=root;
        //code here
    }
};

Iterative:

 void flatten(TreeNode* root) {
        
        if(!root) return;
        TreeNode *curr=root;
        
        while(curr!=NULL){
            if(curr->left){
                TreeNode *prev=curr->left;
            
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
        curr=curr->right;
        }
    }
