/* 

------------------------Promise-----------------------

Reason has built-in support for JavaScript promises through BuckleScript. The 3 functions you generally need are:

Js.Promise.resolve: 'a => Js.Promise.t('a)
Js.Promise.then_: ('a => Js.Promise.t('b), Js.Promise.t('a)) => Js.Promise.t('b)
Js.Promise.catch: (Js.Promise.error => Js.Promise.t('a), Js.Promise.t('a)) => Js.Promise.t('a)
Additionally, here's how to create a JS promise on the Reason side:

Js.Promise.make: ( ( ~resolve: (. 'a) => unit, ~reject: (. exn) => unit ) => unit ) => Js.Promise.t('a)
This type signature means that make takes a callback that takes 2 named arguments, resolve and reject. Both arguments are themselves uncurried callbacks (they have a dot). make returns the created promise.

 --Usage--

Using the pipe operator (see "Composition operators" in the Pervasives module): */

let myPromise = Js.Promise.make((~resolve, ~reject) => resolve(. 2)); 

myPromise
|> Js.Promise.then_(value => {
     Js.log(value);
     Js.Promise.resolve(value + 2);
   })
|> Js.Promise.then_(value => {
     Js.log(value);
     Js.Promise.resolve(value + 3);
   })
|> Js.Promise.catch(err => {
     Js.log2("Failure!!", err);
     Js.Promise.resolve(-2);
   });