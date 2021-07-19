string serialize(TreeNode* root) {
        if(!root)
            return "null";
      return to_string(root->val)+","+ serialize(root->left) +","+serialize(root->right);        
        
    }
    TreeNode* helper(queue<string> &q)
    {
        if(q.empty())
        {
            return NULL;
        }
        string f = q.front();
        q.pop();
        if(f=="null")
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(f));
        root->left = helper(q);
        root->right = helper(q);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        queue<string> q;
        string temp="";
        for(auto i:data)
        {
            if(i==',')
            {
                q.push(temp);
                temp="";
                continue;
            }
            temp += i;
        }
        
        TreeNode* root = helper(q);
        return root;
        
    }
