
/*"Immutable" as in, "doesn't change". Once a binding refers to a value, it cannot refer to anything else (unless it explicitly contains a mutable value, discussed later). However, you may create a new binding of the same name which shadows the previous binding; from that point onward, the binding will refer to the newly assigned value.*/
/*  
    -Immutable
    -Block Scope
*/
let message = "hello";
print_endline(message); /* Prints "hello" */
let message = "bye";
print_endline(message); /* Prints "bye" */
let myInt = 5;
let myInt: int = 5;
let myInt = (5: int) + (4: int);
let add = (x: int, y: int) : int => x + y;
let drawCircle = (~radius as r: int) : int => {2*3*r*r };

type scoreType = int;
let x: scoreType = 10;