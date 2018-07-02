

/* The dot at the beginning indicates that this is a "closed" object type, which means that an object based on this type must have exactly this shape. */

type tesla = {.
  drive: int => int
};

let obj: tesla = {
  val hasEnvy = ref(false);
  pub drive = (speed) => {
    this#enableEnvy(true);
    speed
  };
  pri enableEnvy = (envy) => hasEnvy := envy
};



/* Two dots, also called an elision, indicate that this is an "open" object type, and therefore can also contain other values and methods. An open object is also polymorphic and therefore requires a parameter. */


type tesla1('a) = {
  ..
  drive: int => int
} as 'a;

let obj: tesla1({. drive: int => int, doYouWant: unit => bool}) = {
  val hasEnvy = ref(false);
  pub drive = (speed) => {
    this#enableEnvy(true);
    speed
  };
  pub doYouWant = () => hasEnvy^;
  pri enableEnvy = (envy) => hasEnvy := envy
};

obj#doYouWant();