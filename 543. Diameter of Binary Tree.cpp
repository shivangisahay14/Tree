int solve(TreeNode *root,int& ans){
        
        if(root==NULL) {return 0;}
        
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        
        ans=max(ans,1+l+r);
        
        return 1+(max(l,r));
        
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) {return 0;}
        int ans=INT_MIN;
        solve(root,ans);
        
        return ans-1;
        
        
    }
