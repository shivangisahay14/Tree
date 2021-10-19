 vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        queue<TreeNode*>q;

        if(root==NULL) return ans;

        q.push(root);
        while(!q.empty()){
            int n=q.size();
            ans.push_back(q.back()->val);
            while(n--){
                TreeNode *t=q.front();
                q.pop();

                if(t->left) {
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }

        }
            return ans;
        
    }
