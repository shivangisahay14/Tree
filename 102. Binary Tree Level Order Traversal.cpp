vector<int> levelOrder(Node* node)
    {
        vector<int>ans;
        queue<Node*>q;
        Node *p=node;
        
        q.push(p);
        ans.push_back(p->data);
        
        while(!q.empty()){
            p=q.front();
            q.pop();
            if(p->left){
                ans.push_back(p->left->data);
                q.push(p->left);
            }
            
            if(p->right){
                ans.push_back(p->right->data);
                q.push(p->right);
            }
        }
        return ans;
    }


store in 2D vector:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        TreeNode *p=root;
        
        if(root==NULL) return ans;
        
        q.push(p);

        
        while(!q.empty())
    {
        vector<int> temp;
        int n =q.size();

        for(int i = 1; i <= n; i++)
        {
             p = q.front();
             q.pop();
             temp.push_back(p -> val);
             
             if(p -> left)
                 q.push(p -> left);
             if(p -> right)
                 q.push(p -> right);
        }
        
        
        ans.push_back(temp);
        
    }
        return ans;
        
    }
