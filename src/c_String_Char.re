let greetings = "Hello " ++ "world!";


/* --QUOATED STRING-- */
/*It's like JavaScript's backtick string interpolation*/

let greetingAndOneSlash = {|Hello
    World
    \
    Hehe...
|};
let name = "Ashish";
let sentense = {j|My name is $name|j};
let world = {js|世界|js}; /* Supports Unicode characters */
let helloWorld = {j|你好，$name|j}; /* Supports Unicode and interpolation variables */
Js.log(sentense);
Js.log(helloWorld);

/* --CHAR-- */
let theChar = 'a';
Js.log(theChar);

let isVowel = (theChar) =>
  switch (theChar) {
  | 'a'| 'e'| 'i'| 'o'| 'u'| 'y' => true
  | _ => false
  };

Js.log(isVowel(theChar));

/*You have an expressive type system now! In an untyped language, you'd often overload the meaning of string by using it as:

1 a unique id: var BLUE_COLOR = "blue"
2 an identifier into a data structure: var BLUE = "blue"; var RED = "red"; var colors = [BLUE, RED]
3 the name of an object field: person["age"] = 24
4 an enum: if (audio.canPlayType() === 'probably') {...} (ಠ_ಠ)
5 other crazy patterns you'll soon find horrible, after getting used to Reason's alternatives.
*/
/*The more you overload the poor string type, the less the type system (or a teammate) can help you! Reason provides concise, fast and maintainable types & data structures alternatives to the use-cases above (e.g. variants, in a later section).*/
