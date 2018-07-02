/*Records are like JavaScript objects but are

    -Lighter
    -Immutable by default
    -Fixed in field names and types
    -Very fast
    -A bit more rigidly typed 

*/

/* type person = {
    age: int,
    name: string
};

let me = {
    age: 5,
    name: "Big Reason"
};

let name = me.name; */

/* example.re */


/* Prefered type */
let me: School.person = {age: 20, name: "Big Reason"};
/* or */
let me = School.{age: 20, name: "Big Reason"};
/* or */
let me = {School.age: 20, name: "Big Reason"};

/*
New records can be created from old records with the ... spread operator. The original record isn't mutated. 
Note: spread cannot add new fields, as a record's shape is fixed by its type.
*/

let meNextYear = {...me, age: me.age + 1};

Js.log(me.age);
Js.log(meNextYear.age);

/*Mutable Update
Record fields can optionally be mutable. This allows you to update those fields in-place with the = operator. */

let baby : School.human = {fname: "Baby Reason", age: 5};
baby.age = baby.age + 1; /* alter `baby`. Happy birthday! */

Js.log(baby.age);

/*Syntax shorthand
To reduce redundancy, we provide punning for a record's types and values. Punning refers to the syntax shorthand you can use when the name of a field matches the name of its value/type: 
Note that there's no punning for a single record field! {foo} doesn't do what you expect (it's a block that returns the value foo).
*/

type horsePower = {power: int, metric: bool};

let metric = true;
let someHorsePower = {power: 10, metric};
/* same as the value {power: 10, metric: metric}; */

type car = {name: string, horsePower};
/* same as the type {name: string, horsePower: horsePower}; */


/* Record types are fund by field names */

/* With records, you cannot say "I'd like this function to take any record type, as long as they have the field age". The following works, but not as expected: */

type person = {age: int, name: string};
type monster = {age: int, hasTentacles: bool};

let getAge = (entity) => entity.age;

/* The last line's function will infer that the parameter entity must be of type monster. The following code's last line fails: */

let kraken = {age: 9999, hasTentacles: true};
let me = {age: 5, name: "Baby Reason"};

getAge(kraken);
/* getAge(me); Uncomment and see the error */


