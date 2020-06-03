//Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/ 
/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function(sentence, searchWord) {
    var ans = -1;
    sentence.split(" ").find((word, idx) => {
        let res = word.startsWith(searchWord);
        if(res && ans == -1)
            ans = idx + 1;
        return res;
    });
    return ans;
};