/*Tuples are :
immutable
ordered
fix-sized at creation time
heterogeneous (can contain different types of values)

Note: there's no tuple of size 1. You'd just use the value itself.

The combination of tuple + switch is very powerful and concise, and wipes out an entire category of bugs. Together, they cleanly list out all the possible combinations of values. A tuple of type (bool, bool) indeed has 2 * 2 = 4 possibilities, and the type system asks you to cover all 4. This lends itself well to code refactors; instead of informally adding a few if-else on arbitrary values here and there, you can directly pinpoint the exact switch branch you need to alter, no more and no less.
 */

let ageAndName: (int, string) = (24, "Lil' Reason");
/* a tuple type alias */
type coord3d = (float, float, float);
let my3dCoordinates: coord3d = (20.0, 30.5, 100.0);

let (x,y,z) = my3dCoordinates;

Js.log(x);

/* To return many values : */

let getCenterCoordinates = () => {
    let x = 10;
    let y = 20;
    (x, y)
};

Js.log(getCenterCoordinates());

/*to "pattern-match" */

let isInteger = switch (true, false) { 
    | (true, true) => true
    | (true, false) => true
    | (false, true) => true
    | (false, false) => false
    };

Js.log(isInteger);