void Diagonaltraversal(Node *root,map<int,vector<int>> &m,int d){
    if(!root) return ;
    
    m[d].push_back(root->data);
    Diagonaltraversal(root->left,m,d+1);
    Diagonaltraversal(root->right,m,d);
}

vector<int> diagonal(Node *root)
{
    vector<int>ans;
    if(!root) return ans;
    map<int,vector<int>>m;
    int d=0;
    Diagonaltraversal(root,m,d);
    
    for(auto x:m){
        for(auto y:x.second){
            ans.push_back(y);
        }
    }
    return ans;
    
}
