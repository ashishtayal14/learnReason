
/* ==: structural equal, compares data structures deeply: (1, 2) == (1, 2) is true. Convenient, but use with caution
===: referential equal, compares shallowly. (1, 2) === (1, 2) is false. let myTuple = (1, 2); myTuple === myTuple is true. */

let firstTupple = (1,2);
let secondTupple = (1,2);

let isDeepEquals = firstTupple == secondTupple;
let isShallowEquals = firstTupple === secondTupple;

Js.log(Js.Float.isFinite(1234.0));

/*
Integers
32-bits, truncated when necessary. Reason provides the usual operations on them: +, -, *, /, etc.

Floats
Float requires other operators: +., -., *., /., etc. Like 0.5 +. 0.6.

*/