TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root) return NULL;
        
        if(root->val==p->val or root->val==q->val) return root;
        
        TreeNode *l=lowestCommonAncestor(root->left,p,q);
        TreeNode *r=lowestCommonAncestor(root->right,p,q);
        
        if(l && r){
            return root;
        }
        if(l){
            return l;
        }
        if(r){
            return r;
        }
        return NULL;        
    }
