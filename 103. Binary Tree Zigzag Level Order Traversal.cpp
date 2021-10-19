    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
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
        for(int i = 1; i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;

        
    }
//using 2 stacks:
vector <int> zigZagTraversal(Node* root)
{
    vector<int>ans;
    if (!root)
        return;

    // declare two stacks
    stack<struct Node*> currentlevel;
    stack<struct Node*> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty   
    bool lefttoright = true;
    while (!currentlevel.empty()) {

        // pop out of stack
        struct Node* temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp) {

            // print the data in it
            ans.push_back(temp->data);

            // store data according to current
            // order.
            if (lefttoright) {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}
