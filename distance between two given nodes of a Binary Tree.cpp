Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(!root) return NULL;
        
        if(root->data==n1 or root->data==n2) return root;
        
        Node *l=lca(root->left,n1,n2);
        Node *r=lca(root->right,n1,n2);
        
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
int Distance(Node *root,int val){
    if(!root) return 0;
    if(root->data==val) return 1;
    
    int a=Distance(root->left,val);
    int b=Distance(root->right,val);
    
    if(!a && !b){
        return 0;
    }
    return a+b+1;
}
int findDist(Node* root, int a, int b) {
    
    Node *LCA=lca(root,a,b);
    int dist=Distance(LCA,a)+Distance(LCA,b)-2;
    
    return dist;
    
}
