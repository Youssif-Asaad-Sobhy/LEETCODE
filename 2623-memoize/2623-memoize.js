/**
 * @param {Function} fn
 */
function memoize(fn) {
    let memo={};
    return function(...args) {
        if(!memo.hasOwnProperty(args))return memo[args]=fn(...args);
        else return memo[args];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */