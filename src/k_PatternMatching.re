type payload =
  | BadResult(int)
  | GoodResult(string)
  | NoResult;
/* While using the switch expression on it, you can "destructure" it: */

let data = GoodResult("Product shipped!");

let message =
  switch (data) {
  | GoodResult(theMessage) => "Success! " ++ theMessage
  | BadResult(errorCode) => "Something's wrong. The error code is: " ++ string_of_int(errorCode)
  };



/* --When clauses-- */
/* When you really need to use arbitrary logic with an otherwise clean pattern match, you can slip in some when clauses, which are basically if sugar: */

let message =
  switch (data) {
  | GoodResult(theMessage) => print_endline("No such item found!")
  /* | BadResult(errorCode) when isServerError(errorCode) => print_endline("No such item found!") */
  | BadResult(errorCode) => print_endline("No such item found!") /* otherwise */
  | NoResult => print_endline("No such item found!")
  };

/* --Match on Exceptions-- */
/* If the function throws an exception (covered later), you can also match on that, in addition to the function's normally returned values. */

/* switch (List.find((i) => i === theItem, myItems)) {
| item => print_endline(item)
| exception Not_found => print_endline("No such item found!")
}; */

/* --Nested Patterns-- */
/* Nested | work as intended: */


/* switch (student) {
| {name: "Jane" | "Joe"} => print_endline("")
| {name: "Bob", Job: Programmer({fullTime: Yes | Maybe})} => print_endline("")
}; */


/* --Patterns Everywhere-- */
/* You can put a pattern anywhere you'd put a normal "variable declaration": */

type leftOrRight =
  | Left(int)
  | Right(int);

let i = Left(1);

/* magic! */
let Left(v) | Right(v) = i;