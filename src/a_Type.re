/* --ANNOTATIONS-- */

/* This let-binding doesn't contain any written type: */
let score = 10;


/* Reason knows that score is an int, judging by the value 10. This is called INFERENCE.

But types can also be explicitly written down by choice: */

let score: int = 10;

let myInt = 5;
let myInt: int = 5;
let myInt = (5: int) + (4: int);
let add = (x: int, y: int) : int => x + y;
let drawCircle = (~radius as r: int) : int => {
    r + 1;
};

/* Note: in the last line, (~radius as r: int) is a LABELED ARGUMENTS */


/* --ALIAS-- */

/* You can refer to a type by a different name. */
type scoreType = int;
let x: scoreType = 10;


/* --Infered Types-- */

type intCoordinates = (int, int, int);
let buddy: intCoordinates = (10, 20, 20);
            /* OR */
let buddy = (10, 20, 20); /* The type system infers that it's a (int, int, int). Nothing else needed to be written down. */

/* inferred as `list(string)` */
let greetings = ["hello", "world", "how are you"];
    /* OR */
let greetings : list(string) = ["hello", "world", "how are you"];

/* --Variant type-- */

type myResponseVariant =
  | Yes
  | No
  | PrettyMuch;

/* --Generics OR Constructor Type-- */

type coordinates('a) = ('a, 'a, 'a);

/* apply the coordinates "type function" and return the type (int, int, int) */
type intCoordinatesAlias = coordinates(int);

let buddy: intCoordinatesAlias = (10, 20, 20);

/* or, more commonly, write it inline */
let buddy: coordinates(float) = (10.5, 20.5, 20.5);

/* If types didn't accept parameters (ie, if we didn't have "type functions"), the standard library would need to define the types listOfString, listOfInt, listOfTuplesOfInt, etc. */

/* These types are generaly used to define records of different sub-types*/

/* PREDEFINED GENERIC TYPES
    list('a)
    array('a)
*/   

type result('a, 'b) =
  | Ok('a)
  | Error('b);

let aR = Ok("sadf");

type myPayload = {data: string};

type myPayloadResults('errorType) = list(result(myPayload, 'errorType));

let payloadResults: myPayloadResults(string) = [
  Ok({data: "hi"}),
  Ok({data: "bye"}),
  Error("Something wrong happened!")
];

/* 
    --Mutually Recursive Types--
    Just like functions, types can be mutually recursive through and: 

    type student = {taughtBy: teacher}
    and teacher = {students: list(student)};
*/

type gender = 
  | Male 
  | Female 

type department =
  | Physics
  | Chemistry
  | Maths
  | Economics
  | Biology

type student = {name: string,rollNo: int, gender: gender, taughtBy: teacher}
and teacher = {name: string,gender: gender,dep: department,students: list(student)};



/* let ashish : student = {name: "Ashish", rollNo: 12345, gender: Male, taughtBy:puja};
let puja : teacher = {name: "Puja", gender: Female, dep: Physics, students:[ashish]}; */



/* 
Note that there's no semicolon ending the first line and no type on the second line. 
A type system allowing type argument is basically allowing type-level functions. list(int) is really the list type function taking in the int type, and returning the final, concrete type you'd use in some places. You might have noticed that in other languages, this is more or less called "generics". For example, ArrayList<Integer> in Java.

*/

/* The standard library exposes two important variants you'll come to hear a lot. */


type option('a) = None | Some('a);
type list('a) = Empty | Head('a, list('a));

let greetings : list(string) = Head("hello",Head("world", Head("how are you", Empty)));


/* --Abstract Type-- */

type student1;

/* Type student doesn't have an actual content; that's called an abstract type. It's a convenient way of specifying the relationship between external calls without knowing what the shape of the data is under the hood. */
