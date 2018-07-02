type myResponseVariant =
  | Yes
  | No
  | PrettyMuch;

type newResponseVariant = 
  | Yes
  | No
  | PrettyMuch

let areYouCrushingIt = Yes;

/* 
Yes, No and PrettyMuch aren't strings, nor references, nor some special data type. They're called "constructors" (or "tag"). The | bar separates each constructor.
Note: a variant's constructors need to be capitalized. 
*/

let message =
  switch (areYouCrushingIt) {
  | No => "No worries. Keep going!"
  | Yes => "Great!"
  | PrettyMuch => "Nice!"
  };

Js.log(message);

let pet: School.animal = Dog; /* preferred */
/* or */
let pet = School.Dog;

/* --Constructure Arguments-- */

/* A variant's constructors can hold extra data separated by comma. */

type account =
  | None
  | Instagram(string)
  | Facebook(string, int);

/* Here, Instagram holds a string, and Facebook holds a string and an int. Usage: */

let myAccount = Facebook("Josh", 26);
let friendAccount = Instagram("Jenny");

/* Notice how using a constructor is like calling a function? It's as if Facebook was a function that accepts two arguments. This isn't a coincidence; there's a reason why a constructor's data is called "constructor argument".

Using switch, you can pattern-match (again, described in a later section) a constructor's arguments: */

let greeting =
  switch (myAccount) {
  | None => "Hi!"
  | Facebook(name, age) => "Hi " ++ name ++ ", you're " ++ string_of_int(age) ++ "-year-old."
  | Instagram(name) => "Hello " ++ name ++ "!"
  };

Js.log(greeting);


/* --option variant-- */

/* The standard library exposes two important variants you'll come to hear a lot. */


/* type option('a) = None | Some('a); */

let printName = (name : option('a)) => {
  switch (name) {
  | None => Js.log("The name is undefined");
  | Some(name) => Js.log({j|The name is $name|j});
  };
}
let printName = (~name: option(string)=?) => {
  switch (name) {
  | None => Js.log("The name is undefined");
  | Some(name) => Js.log({j|The name is $name|j});
  };
}

let myName = "Ashish";

printName(~name=?Some(myName));
printName(~name=?None);

/* This is the convention used to simulate a "nullable" (aka undefined or null) value in other languages. Thanks to this convenience type definition, Reason can default every value to be non-nullable. An int will always be an int, never "int or null or undefined". If you do want to express a "nullable int", you'd use option(int), whose possible values are None or Some(int). switch forces you to handle both cases; therefore, a pure Reason program doesn't have null errors. */

/* --list variant-- */

type list('a) = Empty | Head('a, list('a));

/* Not the actual type definition. Just an illustration.

This says: "a list that holds a value of type a (whatever it is) is either empty, or holds that value plus another list".

Reason gave list a syntax sugar. [1, 2, 3] is conceptually equivalent to Head(1, Head(2, Head(3, Empty))). Once again, switch forces you to handle every case of this variant, including Empty (aka []). This eliminates another big category of access bugs. */

/* Be careful not to confuse a constructor carrying 2 arguments with a constructor carrying a single tuple argument: */

type account1 =
  | Facebook(string, int) /* 2 arguments */;
type account2 =
  | Instagram((string, int)) /* 1 argument - happens to be a 2-tuple */;


/* --Variants Must Have constructors-- */

/* If you come from an untyped language, you might be tempted to try type foo = int | string. This isn't possible in Reason; you'd have to give each branch a constructor: type foo = Int(int) | String(string). Though usually, needing this might be an anti-pattern. The Design Decisions section below explains more. */

/* --Interop with JavaScript-- */

/* This section assumes knowledge about BuckleScript's FFI. Skip this if you haven't felt the itch to use variants for wrapping JS functions yet.

Quite a few JS libraries use functions that can accept many types of arguments. In these cases, it's very tempting to model them as variants. For example, suppose there's a myLibrary.draw JS function that takes in either a number or a string. You might be tempted to bind it like so: */

/* reserved for internal usage */
[@bs.module "./myLibrary"] external draw : 'a => unit = "draw"; /* Replace myLibrary with "./myLibrary" in the .bs.js file for this */

type animal =
  | MyFloat(float)
  | MyString(string);

let normalDraw = (animal) =>
  switch (animal) {
  | MyFloat(f) => draw(f)
  | MyString(s) => draw(s)
  };

/* 
You could definitely do that, but there are better ways! For example, simply two externals that both compile to the same JS call: 
*/

[@bs.module "./myLibrary"] external drawFloat : float => unit = "draw";
[@bs.module "./myLibrary"] external drawString : string => unit = "draw";

let betterDraw = (animal) =>
  switch (animal) {
  | MyFloat(f) => drawFloat(f)
  | MyString(s) => drawString(s)
};

normalDraw(MyFloat(10.0));
betterDraw(MyFloat(10.0));

/* --Variant Types Are Found By Field Name-- */

/* Please refer to this record section. Variants are the same: a function can't accept an arbitrary constructor shared by two different variants. Again, such feature exists, it's called a polymorphic variant. We'll talk about this in the future =). */