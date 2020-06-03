//Link: https://leetcode.com/problems/sum-of-even-numbers-after-queries/ 
/**
 * @param {number[]} A
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(A, queries) {
    var sum = 0;
    var ans = [];
    A.forEach(n=>sum+=(n%2==0?n:0));
    queries.forEach(q=>{
        var add = q[0];
        var i = q[1];
        if( A[i] % 2 == 0 )
            sum -= A[i];
        A[i] += add;
        if( A[i] % 2 == 0 )
            sum += A[i];
        ans.push(sum);
    })
    return ans;
};