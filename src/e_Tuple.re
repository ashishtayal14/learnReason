/*Tuples are :
    -Immutable
    -Ordered
    -Fix-sized at creation time
    -Heterogeneous (can contain different types of values)

Note: There's no tuple of size 1. You'd just use the value itself.

The combination of tuple + switch is very powerful and concise, and wipes out an entire category of bugs. Together, they cleanly list out all the possible combinations of values. A tuple of type (bool, bool) indeed has 2 * 2 = 4 possibilities, and the type system asks you to cover all 4. This lends itself well to code refactors; instead of informally adding a few if-else on arbitrary values here and there, you can directly pinpoint the exact switch branch you need to alter, no more and no less.
 */

let tupleWithInferedTypes = (23123.32,"Lalit",'M');
let ageAndName: (int, string) = (24, "Lil' Reason");
/* a tuple type alias */
type coord3d = (float, float, float);
let my3dCoordinates: coord3d = (20.0, 30.5, 100.0);

let (x,y,z) = my3dCoordinates;
let (a,_,_) = my3dCoordinates;

Js.log(a);
Js.log(x);

/* To return many values : */

let getCenterCoordinates = () => {
    let x = 10;
    let y = 20;
    (x, y)
};

Js.log(getCenterCoordinates());

/*To "pattern-match" */

let isInteger = switch (true, false) { 
    | (true, true) => true
    | (true, false) => true
    | (false, true) => true
    | (false, false) => false
};

let isList = switch(["sdfsdf"]){
| ["sdfsdf"] => true
| _ => false
};

Js.log(isInteger);

/* Try to keep the usage of tuple local. For data structures that are long-living and passed around often, prefer a record, which has named fields. */