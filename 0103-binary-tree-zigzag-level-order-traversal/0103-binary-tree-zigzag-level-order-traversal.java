/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root){

        List<List<Integer>> ans = new ArrayList<>();
        Deque<TreeNode> q = new ArrayDeque<>();
        int lvl = 0;//or depth;
        if(root != null)
            q.addLast(root);
        while(!q.isEmpty()){
            int sz = q.size();
            ArrayList<Integer> list = new ArrayList<>();
            while(sz-- > 0){
                TreeNode u = q.pollFirst();
                if(lvl % 2 == 0)
                    list.add(u.val);
                else
                    list.addFirst(u.val);
                if(u.left != null)
                    q.addLast(u.left);
                if(u.right != null)
                    q.addLast(u.right);
            }
            lvl += 1;
            ans.add(list);
        }

        return ans;
    }
}