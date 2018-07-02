/* Note: an if-else expression without the final else branch implicitly gives (). So this: */

let showMenu = true;
let displayMenu = () => {
    ()
};

if (showMenu) {
  displayMenu();
};
/* is basically the same as: */

if (showMenu) {
  displayMenu()
} else {
  ()
};

/* Here's another way too look at it. This is clearly wrong: */

/* 
    let result = if (showMenu) {
    1 + 2
    }; 
*/
/* It'll give a type error, saying basically that the implicit else branch has the type unit while the if branch has type int. Intuitively, this makes sense: what would result's value be, if showMenu was false?

We also have ternary sugar. */

let isMorning = false;
switch (isMorning) {
    | true => "Good morning!"
    | false => "Hello!"
};
    /* If you pass that through refmt, you'd get: */
    
isMorning ? "Good morning!" : "Hello!";