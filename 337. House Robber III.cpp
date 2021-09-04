class Solution {
public:
    
    class housepair{
        public:
        int withrob=0;
        int withoutrob=0;
    };
    
    housepair rob_(TreeNode* root){
        
        housepair ans;
        if(!root) return ans;
        
        housepair l=rob_(root->left);
        housepair r=rob_(root->right);        
        
        
        ans.withrob=root->val+l.withoutrob+r.withoutrob;
        
        ans.withoutrob=max(l.withrob,l.withoutrob)+max(r.withrob,r.withoutrob);
        
        return ans;
    }
    int rob(TreeNode* root) {
        
        housepair res=rob_(root);
        
        return max(res.withrob,res.withoutrob);
        
    }
};
