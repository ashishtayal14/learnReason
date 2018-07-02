 /* Destructuring also allows type annotations. */

let someInts = (10, 20);
let (ten, twenty) = someInts;

type person = {name: string, age: int};
let somePerson = {name: "Guy", age: 30};
let {name, age} = somePerson;
let {name: n, age: a} = somePerson;


/* 
    let (ten: int, twenty: int) = someInts;
    let {name: (n: string), age: (a: int)} = somePerson; 
*/

/* Destructuring a function's labeled arguments is also possible. */

let someFunction = (~person as {name}) => {
  /* you can use `name` here */
};

let otherFunction = (~person as {name} as thePerson) => {
  /* you can use both `name` and the whole record as `thePerson` here */
};