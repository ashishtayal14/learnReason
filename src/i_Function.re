/* Cheat sheet for the function syntaxes: */

/* --DECLARATION-- */
/* anonymous function. Listed for completeness only */

(x) => (y) => 1;
/* sugar for the above */
(x, y) => 1;
/* assign to a name */
let add = (x, y) => 1;

/* labeled */
let add = (~first as x, ~second as y) => x + y;

add(~second=5)(~first=2);

/* with punning sugar */
let add = (~first, ~second) => first + second;

/* labeled with default value */
let add = (~first as x=1, ~second as y=2) => x + y;
/* with punning */
let add = (~first=1, ~second=2) => first + second;
add(~second=3);

/* optional */
let add = (~first as x=?, ~second as y=?) => {
    switch (x) {
    | None => Js.log("Nothing");
    | Some(x) => Js.log(x);
    };
};

add(~first=1,~second=1);

/* with punning */
let add = (~first=?, ~second=?) => {
    switch (first) {
    | None => Js.log("Nothing");
    | x => Js.log(x);
    };
};

/* OR */

let add = (~first:option(int), ~second=?) => {
    switch (first) {
    | None => Js.log("Nothing");
    | x => Js.log(x);
    };
};


/* With Type Annotation */

/* anonymous function */
(x: int) => (y: int): int => 1;
/* sugar for the above */
(x: int, y: int): int => 1;
/* assign to a name */
let add = (x: int, y: int): int => 1;

/* labeled */
let add = (~first as x: int, ~second as y: int) : int => x + y;
/* with punning sugar */
let add = (~first: int, ~second: int) : int => first + second;

/* labeled with default value */
let add = (~first as x: int=1, ~second as y: int=2) : int => x + y;
/* with punning sugar */
let add = (~first: int=1, ~second: int=2) : int => first + second;

/* optional */
let add = (~first as x: option(int)=?, ~second as y: option(int)=?) : int => {
    switch (x) {
    | None => Js.log("Nothing");
    | x => Js.log(x);
    };
    1;
}
/* with punning sugar */
/* note that the caller would pass an `int`, not `option int` */
/* Inside the function, `first` and `second` are `option int`. */
let add = (~first: option(int)=?, ~second: option(int)=?) : int => {
    switch (first) {
    | None => Js.log("Nothing");
    | Some(x) => Js.log(x);
    };
    1;
};

add(~first=1,~second=2);
    /* OR */
add(~first=?Some(1),~second=?Some(2));


/* If we pass the arguments with only "=" then reason internaly converts it to option('a) type
   But when we pass using "=?" then it doesn't internaly convert it. So in that case we need to pass type option('a) explicitly ie
   Some('a) or None
*/

/* --APPLICATION-- */

/* anonymous application. Listed for completeness only */
/* add(x)(y);
/* sugar for the above */
add(x, y);

/* labeled */
add(~first=1, ~second=2);
/* with punning sugar */
add(~first, ~second);

/* application with default value. Same as normal application */
add(~first=1, ~second=2);

/* explicit optional application */
add(~first=?Some(1), ~second=?Some(2));
/* with punning */
add(~first?, ~second?);


/* With Type Annotation */

/* anonymous application */
add(x: int)(y: int);

/* labeled */
add(~first=1: int, ~second=2: int);
/* with punning sugar */
add(~first: int, ~second: int);

/* application with default value. Same as normal application */
add(~first=1: int, ~second=2: int);

/* explicit optional application */
add(~first=?Some(1): option(int), ~second=?Some(2): option(int));
/* with punning sugar */
add(~first: option(int)?, ~second: option(int)?); */

/* --Optionaly Labelled Arguments-- */

/* Labeled function arguments can be made optional during declaration. You can then omit them when calling the function. */

/* radius can be omitted */
let drawCircle = (~color, ~radius=?, ()) => {
  switch (radius) {
  | None => ()
  | Some(r_) => r_
  }
};

/* When given in this syntax, radius is wrapped in the standard library's option type, defaulting to None. If provided, it'll be wrapped with a Some. So radius's type value is either None or Some(int) here.

NOTE: None | Some(foo) is a data structure type called variant, described earlier. This particular variant type is provided by the standard library. It's called option. Its definition: type option('a) = None | Some('a).

NOTE the unit () at the end of drawCircle. Without it, since radius and color are both labeled, can be curried, and can be applied out-of-order, it's unclear what the following means: */

let color = "red";
let whatIsThis = drawCircle(~color);

/* Is whatIsThis a curried drawCircle function, waiting for the optional radius to be applied? Or did it finish applying? To address this confusion, append a positional (aka non-labeled) argument to drawCircle (conventionally ()), and OCaml will, as a rule of thumb, presume the optional labeled argument is omitted when the positional argument is provided. */

let curriedFunction = drawCircle(~color);
let actualResultWithoutProvidingRadius = drawCircle(~color, ());


/* --No Argumants-- */

/* receive & destructure the unit argument */
let logSomething = () => {
    print_endline("hello");
    print_endline("world")
  };
  
/* call the function with the value of type unit */
logSomething();
/*In Reason, every function takes an argument; here we'd conventionally pass it the value (), called "unit".*/

/* --Explicitly Passed Optional-- */

/* Sometimes, you might want to forward a value to a function without knowing whether the value is None or Some(a). Naively, you'd do: */

let drawCircle = (~color,~radius: option(string)=?,()) => {
    switch radius {
    | Some(radius) => color ++ radius;
    | None => color;
    };
}

let getResult = (payloadRadius) =>{
    let result =
    switch (payloadRadius) {
        | None => drawCircle(~color="green", ())
        | Some(r) => drawCircle(~color="red", ~radius=r, ())
    };
}

/* This quickly gets tedious. We provide a shortcut: */

let getResult = (payloadRadius) => {
    let result = drawCircle(~color="blue", ~radius=?payloadRadius, ());
}

/* This means "I understand radius is optional, and that when I pass it a value it needs to be an int, but I don't know whether the value I'm passing is None or Some(val), so I'll pass you the whole option wrapper". */


/* --Recursive Functions-- */

/* By default, a value can't see a binding that points to it, but including the rec keyword in a let binding makes this possible. This allows functions to see and call themselves, giving us the power of recursion. */

let rec neverTerminate = () => neverTerminate();


/* --Mutually Recursive Functions-- */
/* 
Mutually recursive functions start like a single recursive function using the rec keyword, and then are chained together with and: 
*/

let rec callSecond = () => callFirst()
and callFirst = () => callSecond();
/* Note that there's no semicolon ending the first line and no let on the second line. */


/* --Standalone Type Signature-- */
/* first arg type, second arg type, return type */
type foo = int => int => int;
/* sugar for the above */
type foo1 = (int, int) => int;

/* labeled */
type foo2 = (~first: int, ~second: int) => int;

/* labeled with default value */
type foo3 = (~first: int=?, ~second: int=?) => int;


let newFunc : foo3 = (~first=?,~second=?) => {
    switch(first){
    | Some(x) => {Js.log(x);}
    | None => Js.log("Didnot get the first value");
    };
    1;
};

newFunc(~first=1,~second=2);