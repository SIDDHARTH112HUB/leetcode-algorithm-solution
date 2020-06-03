//Link: https://leetcode.com/problems/occurrences-after-bigram/ 
/**
 * @param {string} text
 * @param {string} first
 * @param {string} second
 * @return {string[]}
 */
var findOcurrences = function(text, first, second) {
    var arr = text.split(" ");
    var ans = []
    for(var i = 0; i < arr.length -2; i++) {
        if(arr[i] == first && arr[i+1] == second)
            ans.push(arr[i+2]);
    }
    return ans;
};