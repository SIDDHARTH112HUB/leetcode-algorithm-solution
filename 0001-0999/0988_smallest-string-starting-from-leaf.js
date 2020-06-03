//Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/ 
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string}
 */
var c = "abcdefghijklmnopqrstuvwxyz";
var ans = ""
var smallestFromLeaf = function(root) {
    if( !root ) return "";
    ans = "";
    solve(root, "");
    return ans;
};

var solve = function(node, str){
    if( !node ) return;
    str += c[node.val];
    if( !node.left && !node.right ){
        var ns = str.split("").reverse().join("");
        if( ans == "" || ans > ns )
            ans = ns;
        return;
    }
    solve(node.left, str);
    solve(node.right, str);
}