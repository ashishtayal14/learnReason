/* --For loop-- */

let xStart = 1;
let xEnd = 3;

/* prints: 1 2 3 */
for (x in xStart to xEnd) {
  print_int(x);
  print_string(" ")
};

/* --While loop-- */

Random.self_init();

let break = ref(false);

while (! break^) {
  if (Random.int(10) === 3) {
    break := true
  } else {
    print_endline("hello")
  }
};