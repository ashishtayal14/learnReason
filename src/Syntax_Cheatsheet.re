/* Let binding */

let x =5; /* Let is block scope and immutable */
let y =ref(5);  /* Syntax used to make a let value not const and so that we can change it later on */
    y := y^ + 1;
Js.log( "-------------Let binding-----------");
Js.log(y);

/* String and char */

let fname = "Ashish";
let lname = "Tayal";
let gender = 'M';
let fullname = fname ++ lname;
Js.log( "------------String and char--------");
Js.log(fullname);
Js.log(gender);

/* Boolean */

type person = {mutable name : string, gender : char, designation : string, age : int, salary : float};
let ashish : person = {name : "Ashish", gender : 'M', designation : "Senior Consultant", age : 27, salary : 1500000.00 };
let copyAshish = ashish;
copyAshish.name = "Ashish Tayal";
let newAshish : person = {name : "Ashish Tayal", gender : 'M', designation : "Senior Consultant", age : 27, salary : 1500000.00 };
Js.log( "-------------Boolean---------------");
Js.log(ashish === copyAshish);
Js.log(ashish === newAshish);
Js.log(ashish == newAshish); 
Js.log(ashish == copyAshish);
Js.log(Js.String.includes("Ashish",ashish.name));

/* Number */

let floatNum1: float = 10.1;
let floatNum2 = 10.2;
let intNum1 = 10;
let intNum2 = 10;
Js.log( "-------------Number-----------------");
Js.log(floatNum1 +. floatNum2);
Js.log(intNum1 + intNum2);
Js.log(intNum1 mod intNum2);

/* Array, Tuple and List*/

let myArr = [|1,2,3|]; /* Mutable, Homogenious */
myArr[2] = 5;
let myTuple = ("Ashish",27,'M'); /* Immutable, Hetrogenious */
let myList = [1,2,3]; /*Immutable, Homogeniours*/
Js.log("---------Array,Tuple,List-----------");
Js.log(myArr);
Js.log(myTuple);
Js.log(myList);

/* Object and Record */

type car = {name : string, color : string, price : float, brand : string}; /* Record Type */
let swift = {name : "Swift", color : "White", price : 600000.0, brand : "Maruti"}; /* Immutable if the type is explicitly not set to mutable */
let newSwift = {...swift, color : "Grey"};
Js.log("-------------Record------------------");
Js.log(swift === newSwift);
Js.log(swift);


/* Null and Undefined */

let nullValue = None;
Js.log("-------------Null-------------------");
Js.log(nullValue);


/* Functions */

let printName = (personRecord : person) => {
    Js.log(personRecord.name);
    "print complete";
};
Js.log("-------------Function---------------");
Js.log(printName(ashish));

/* Currying */

let getFullName = ( firstName : string, middleName : string, lastName : string) => {
    {j|$firstName $middleName $lastName|j}
};
Js.log("-------------Currying---------------");
Js.log(getFullName("Ashish")("Kumar")("Tayal"));
Js.log(getFullName("Ashish","Kumar","Tayal"));

/* Switch */

let getMessage = (messageKey : int) => {
    switch (messageKey) {
    | 1 => "Reason's pretty cool"
    | 2 => "good night"
    | 3 => "hello"
    | 4 => "hi"
    | 5 => "heya"
    | 6 => "hey"
    | _ => "no message"
    }
}

let message = getMessage(2);
let reply =
  switch (message) {
  | "Reason's pretty cool" => "Yep"
  | "good night" => "See ya!"
  | "hello" | "hi" | "heya" | "hey" => "hello to you too!"
  | _ => "Nice to meet you!"
  };

Js.log("-------------Switch-----------------");
Js.log(reply);
Js.log(getMessage(1));

/* Destructuring */

let {name,age} = ashish;
Js.log("-------------Destructuring----------");
Js.log(name);
Js.log(age);
let {name : n,age: a} = ashish;
Js.log(n);
Js.log(a);
let [|first,second,third|] = myArr; /* This code gives warning */
Js.log(first);
Js.log(second);
Js.log(third);
let first = switch (myArr) {
    | [||] => 1
    | [|a,b,c|] => a+b+c
    | _ => 0
};
Js.log(first);

/* Loops */

Js.log("-------------Loops-----------------");
for(i in 1 to 5){
    Js.log(i);
};

for(i in 5 downto 1){
    Js.log(i);
};

/* Exception */

Js.log("-------------Exceptions-------------");
exception SomeError(string);

try (raise(SomeError("Custom Error"))){
    | SomeError(err) => Js.log(err);
};

let result =
  try (raise(Not_found)) {
  | Not_found => Js.log("Not Found") ;/* Default value if getItem throws */
};

/* Blocks */
Js.log("----------------Blocks--------------");
let res = {
    let x = 5;
    let y = 10;
    x+y;
};
Js.log(res);







