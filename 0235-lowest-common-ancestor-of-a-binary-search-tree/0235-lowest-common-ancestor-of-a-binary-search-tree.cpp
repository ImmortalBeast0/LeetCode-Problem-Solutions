class Solution {
public:
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    bool srch(TreeNode* root ,TreeNode* key ,stack<TreeNode*>& s){
        if(root == nullptr) return false;
        if(root == key){
            s.push(root);
            return true;
        }
        s.push(root);
        if(srch(root->left,key,s))
            return true;
        s.pop();
        s.push(root);
        if(srch(root->right,key,s))
            return true;
        s.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool f1 = srch(root,p,s1);
        bool f2 = srch(root,q,s2);
        if(f1 & f2){

            while(s1.size() > s2.size()) s1.pop();
            while(s1.size() < s2.size()) s2.pop();
            while(!s1.empty() && !s2.empty()){
                if(s1.top()->val == s2.top()->val)
                    return s1.top();
                s1.pop();
                s2.pop();
            }
            return nullptr;
        }else
            return nullptr;
    }
};