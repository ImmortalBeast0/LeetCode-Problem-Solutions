class Solution {
    int sol = 0;
    int[] dfs(TreeNode node){
        if(node == null)
            return new int[]{0,0};

        int[] vals = {1,node.val};
        
        int[] tmp = dfs(node.left);
        vals[0] += tmp[0];
        vals[1] += tmp[1];

        tmp = dfs(node.right);
        vals[0] += tmp[0];
        vals[1] += tmp[1];
        
        if(vals[1] / vals[0] == node.val)
            sol += 1;
        
        return vals;
    }

    public int averageOfSubtree(TreeNode root){
        dfs(root);
        return sol;       
    }
}