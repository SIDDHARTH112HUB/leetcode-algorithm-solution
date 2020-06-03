//Link: https://leetcode.com/problems/rearrange-words-in-a-sentence/ 
/**
 * @param {string} text
 * @return {string}
 */
var arrangeWords = function(text) {
    if(text.length == 0) return text;
    var arr = text.split(" ").map((v, i) => [v, i]);
    arr.sort((a, b)=> {
       if(a[0].length != b[0].length) return a[0].length - b[0].length;
       return a[1] - b[1];
    });
    
    var ans = arr.map(v => v[0].toLowerCase()).join(" ");
    ans = ans[0].toUpperCase() + ans.substr(1);
    return ans;
};