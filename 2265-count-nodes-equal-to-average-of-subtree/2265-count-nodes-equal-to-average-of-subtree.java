class Solution {

    HashMap<TreeNode,Integer> subsz ,subsum;
    int sol = 0;

    void dfs(TreeNode node){
        if(node == null)
            return ;

        subsz.put(node,1);
        subsum.put(node,node.val);
        if(node.left != null){
            dfs(node.left);
            subsz.put(node,subsz.get(node)+subsz.get(node.left));
            subsum.put(node,subsum.get(node)+subsum.get(node.left));
        }
        if(node.right != null){
            dfs(node.right);
            subsz.put(node,subsz.get(node)+subsz.get(node.right));
            subsum.put(node,subsum.get(node)+subsum.get(node.right));
        }

        if(node.val == (int)Math.round(subsum.get(node)/subsz.get(node)))
            sol += 1;

    }

    public int averageOfSubtree(TreeNode root){
        subsz = new HashMap<>();
        subsum = new HashMap<>();
        dfs(root);
        return sol;       
    }
}