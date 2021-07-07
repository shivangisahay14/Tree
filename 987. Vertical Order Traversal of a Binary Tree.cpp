class Solution {
public:
   void width(TreeNode* root, int &minM, int &maxM, int v) {
        if (v < minM) minM = v;
        if (v > maxM) maxM = v;
        
        if (root->left != NULL) {
            width(root->left, minM, maxM, v - 1);
        }
        if (root->right != NULL) {
            width(root->right, minM, maxM, v + 1);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int idx = 0;
        int w = 0;
        int minM = INT_MAX;
        int maxM = INT_MIN;
        width(root, minM, maxM, 0);
        w = abs(minM) + maxM;
        idx = w - abs(maxM);
                
        vector<vector<int>> v(w + 1);
        
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, idx));
        
        int sz = 0;
        pair<TreeNode*, int> n;
        
        while (!q.empty()) {
            sz = q.size();
            
            vector<vector<int>> vLevel(w + 1);
            for (int i = 0; i < sz; i++) {
                n = q.front();
                q.pop();
                                
                vector<int> temp = vLevel[n.second];
                temp.push_back((n.first)->val);
                vLevel[n.second] = temp;                                
                
                if ((n.first)->left != NULL) {
                    q.push(pair<TreeNode*, int>((n.first)->left, n.second - 1));
                } 
                if ((n.first)->right != NULL) {
                    q.push(pair<TreeNode*, int>((n.first)->right, n.second + 1));
                }
            }
            
            for (int i = 0; i < vLevel.size(); i++) {
                sort(vLevel[i].begin(), vLevel[i].end());               
                v[i].insert(v[i].end(), vLevel[i].begin(), vLevel[i].end());
            }
        }
        return v;
        
    }
};
