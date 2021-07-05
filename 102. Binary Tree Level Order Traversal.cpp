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
