type Fn = (...params: number[]) => number




function memoize(fn: Fn): Fn {
let dp:{[key:string]:number} = {};
    return function(...args) {
        let key = args.join(",");
        // console.log(key);
        if(key in dp){
            return dp[key];
        } 
        return dp[key]=fn(...args);
        // console.log(ans);
        // return dp[key]=ans;
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