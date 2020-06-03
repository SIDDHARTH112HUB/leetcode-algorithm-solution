//Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ 
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var m = {}
var verticalTraversal = function(root) {
    if( !root ) return [];
    m = {};
    solve(root, 1000, 1);
    var ans = [];
    for( var idx in m){
        ans.push([]);
        for( var height in m[idx]){
            m[idx][height].sort((a,b)=>a-b);
            m[idx][height].forEach(n=>ans[ans.length-1].push(n));
        }
    }
    return ans;
};

var solve = function(node, idx, height){
    if( !node ) return;
    if( !m[idx] )
        m[idx] = {}
    if( !m[idx][height])
        m[idx][height] = [];
    m[idx][height].push(node.val);
    solve(node.left, idx-1, height+1);
    solve(node.right, idx+1, height+1);
}