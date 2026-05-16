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
    public int goodNodes(TreeNode root) {
        int[] ans = new int[1];
        int maxi = Integer.MIN_VALUE;
        
        dfs(root, ans, maxi);
        return ans[0];
    }

    void dfs(TreeNode node, int[] ans, int maxi) {
        if(node == null) {
            return;
        }

        if(node.val >= maxi) 
            ans[0]++;
        
        maxi = Math.max(node.val, maxi);
        dfs(node.left, ans, maxi);
        dfs(node.right, ans, maxi);
    }
}
