/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let tr=true;
    let res;
    return function(...args){
        if(tr)
        {
            tr=false;
            res=fn.apply(this,args);
            return res;
        }
        return undefined;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
