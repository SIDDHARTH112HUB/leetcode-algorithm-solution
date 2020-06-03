//Link: https://leetcode.com/problems/satisfiability-of-equality-equations/ 
/**
 * @param {string[]} equations
 * @return {boolean}
 */
var m = {}
var find = function(c){
    if( m[c] == undefined )
        m[c] = c;
    else if( m[c] != c ) m[c] = find(m[c]);
    
    return m[c];
}

var combine = (a, b)=>{
    a = find(a);
    b = find(b);
    m[a] = b;
}
var equationsPossible = function(equations) {
    m = {}
    equations.sort((a,b)=>{
        if( a[1] == '=')
            return -1;
        else if( b[1] == '=')
            return 1;
        return 0;
    })
    //console.log("begin")
    for( var e of equations ){
        //console.log(e)
        var a = e[0];
        var b = e[3];
        var s = e[1];
        if( s == '='){
            combine(a, b)
        }else{
            if( find(a) == find(b) && m[a] != undefined && m[b] != undefined )
                return false;
        }
    }
    return true;
}; 