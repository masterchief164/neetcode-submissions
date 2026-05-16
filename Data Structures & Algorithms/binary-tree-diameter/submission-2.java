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
    public int diameterOfBinaryTree(TreeNode root) {
        int ans[] = new int[1];

        dfs(root, ans);

        return ans[0];
    }

    int dfs(TreeNode node, int[] ans) {
        if(node == null) return 0;

        int l = dfs(node.left, ans);
        int r = dfs(node.right, ans);

        ans[0] = Math.max(ans[0], l+r);

        return 1 + Math.max(l, r);
    }
}
