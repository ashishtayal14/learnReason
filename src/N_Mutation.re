/* Let-bindings are immutable, but you can wrap it with a ref, which is like a box whose content can change: */

let foo = ref(5);

/* You can get the actual value of a ref through the postfix ^ operator: */

let five = foo^; /* 5 */
/* Assign a new value to foo like so: */

foo := 6;
/* Note that the previous binding five stays 5, since it got the underlying item on the ref box, not the ref itself. */

/* Just kidding! ref isn't actually a special feature! It's just an ordinary syntax sugar for a predefined mutable record type called ref in the standard library (search "References" in that page). Here's the desugared version: */

let foo = {contents: 5};
let five = foo.contents;
foo.contents = 6;

/* Before reaching for ref, know that you can achieve lightweight, local "mutations" through overriding let bindings: */

let foo = 10;
let foo = true ? foo + 5 : foo;
print_int(foo); /* either 15 or 10 */