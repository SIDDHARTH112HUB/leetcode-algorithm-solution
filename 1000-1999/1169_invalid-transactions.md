[1169.invalid-transactions](https://leetcode.com/problems/invalid-transactions/)  

A transaction is _possibly invalid_ if:

*   the amount exceeds $1000, or;
*   if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.

Each transaction string `transactions[i]` consists of comma separated values representing the name, time (in minutes), amount, and city of the transaction.

Given a list of `transactions`, return a list of transactions that are possibly invalid.  You may return the answer in any order.

**Example 1:**

**Input:** transactions = \["alice,20,800,mtv","alice,50,100,beijing"\]
**Output:** \["alice,20,800,mtv","alice,50,100,beijing"\]
**Explanation:** The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.

**Example 2:**

**Input:** transactions = \["alice,20,800,mtv","alice,50,1200,mtv"\]
**Output:** \["alice,50,1200,mtv"\]

**Example 3:**

**Input:** transactions = \["alice,20,800,mtv","bob,50,1200,mtv"\]
**Output:** \["bob,50,1200,mtv"\]

**Constraints:**

*   `transactions.length <= 1000`
*   Each `transactions[i]` takes the form `"{name},{time},{amount},{city}"`
*   Each `{name}` and `{city}` consist of lowercase English letters, and have lengths between `1` and `10`.
*   Each `{time}` consist of digits, and represent an integer between `0` and `1000`.
*   Each `{amount}` consist of digits, and represent an integer between `0` and `2000`.  



**Solution:**  

```javascript
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
```
      