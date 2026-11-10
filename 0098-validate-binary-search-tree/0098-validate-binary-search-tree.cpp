class Solution {
public:
    vector<int> nums;
    void rec(TreeNode* root){

        if(root == nullptr)
            return ;
        rec(root->left);
        nums.push_back(root->val);
        rec(root->right);
    }

    bool isValidBST(TreeNode* root){
        rec(root);
        for(int i=1;i<nums.size();i++)
            if(nums[i-1] >= nums[i])
                return false;
        return true;      
    }
};