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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty()) {
            TreeNode right = null;

            int n = q.size();

            for(int i = 0;i<n;i++) {
                TreeNode curr = q.poll();
                if(curr != null ){
                    right = curr;
                    q.offer(right.left);
                    q.offer(curr.right);
                }
            }
            if(right != null) 
                ans.add(right.val);
        }
        return ans;
    }
}
