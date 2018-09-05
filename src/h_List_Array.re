
/* --LIST-- */

/* 
    -Homogeneous
    -Immutable
    -Fast at prepending items
*/

/* List API in reason */

let myList: list(int) = [1, 2, 3];
let anotherList = [0, ...myList];

/* --ARRAY-- */

/* 
    -Homogeneous
    -Mutable
    -Fast at random access & updates
    -Fix-sized on native (flexibly sized on JavaScript) 
*/

/* 
    Array API in reason
    Js.Array for Js compilation
*/

let myArray: array(string) = [|"hello", "world", "how are you"|];

let firstItem = myArray[0]; /* "hello" */

myArray[0] = "hey";

let secondItem = Array.get(myArray,0);
Array.set(myArray,1,"all");
let arrayLength = Js.Array.length(myArray);
Js.log(secondItem);
Js.log(arrayLength);

