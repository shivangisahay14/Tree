    bool findSum(TreeNode* root, int targetSum,int curr_sum,bool &flag){
        
        if(!root) return false;
        
        curr_sum+=root->val;
        if(!root->left && !root->right && curr_sum==targetSum){
            flag=true;
        }
        findSum(root->left,targetSum,curr_sum,flag);
        findSum(root->right,targetSum,curr_sum,flag);
        
        return flag;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        int curr_sum=0;
        bool flag=false;
        return findSum(root,targetSum,curr_sum,flag);                
        
    }
