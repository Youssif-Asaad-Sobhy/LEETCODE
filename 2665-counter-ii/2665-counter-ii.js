/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var original = init;

    // Increment function
    var increment = function() {
        return ++init;
    };

    // Decrement function
    var decrement = function() {
        return --init;
    };

    // Reset function
    var reset = function() {
        return init = original;
    };

    // Return an object with accessible properties
    return {
        increment: increment,
        decrement: decrement,
        reset: reset,
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */