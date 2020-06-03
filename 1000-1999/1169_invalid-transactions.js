//Link: https://leetcode.com/problems/invalid-transactions/ 
/**
 * @param {string[]} transactions
 * @return {string[]}
 */
var invalidTransactions = function(transactions) {
    var obj = {};
    const ans = {};
    transactions.forEach(tran => {
        const arr = tran.split(',');
        
        const name = arr[0], t = parseInt(arr[1]), amount = parseInt(arr[2]), city = arr[3];
        if(!obj[name]) obj[name] = [];
        var o = obj[name];
        var last = o[o.length - 1];
        o.forEach(last =>{
            if(last && Math.abs(last[1] - t) <= 60 && city != last[3] ){
                //o.pop();
                ans[last.join(",")] = 1;
                ans[tran] = 1;;
            }
        });
        if(amount > 1000){
            ans[tran] = 1;
        }
        obj[name].push(arr);
    });
    return Object.keys(ans);
};