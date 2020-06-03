//Link: https://leetcode.com/problems/complex-number-multiplication/ 
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var complexNumberMultiply = function(a, b) {
    const e1 = a.split("+");
    const e2 = b.split("+");
    const n1 = parseInt(e1[0]);
    const i1 = parseInt(e1[1]);
    const n2 = parseInt(e2[0]);
    const i2 = parseInt(e2[1]);
    return (n1 * n2 -i1 * i2) + "+" + (n1 * i2 + n2 * i1)+"i";
};