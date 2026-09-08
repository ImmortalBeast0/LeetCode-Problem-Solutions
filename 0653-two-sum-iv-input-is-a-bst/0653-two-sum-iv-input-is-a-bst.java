class Solution {

    boolean dfs(TreeNode node ,TreeNode root ,int k){
        if(node == null)
            return false;
        
        if(bs(root,node,k - node.val))
            return true;

        if(dfs(node.left,root,k) || dfs(node.right,root,k))
            return true;

        return false;
    }

    boolean bs(TreeNode node ,TreeNode a ,int t){
        if(node == null)
            return false;
        if(node.val == t && a != node)
            return true;
        if(node.val < t && bs(node.right,a,t))
            return true;
        else if(bs(node.left,a,t))
            return true;
        return false;
    }

    public boolean findTarget(TreeNode root, int k) {
        return dfs(root,root,k);
    }
}