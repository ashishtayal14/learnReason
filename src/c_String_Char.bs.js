// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';


var name = "Ashish";

var sentense = "My name is " + (String(name) + "");

console.log(sentense);

console.log(/* "a" */97);

function isVowel(theChar) {
  var switcher = theChar - 97 | 0;
  if (switcher > 24 || switcher < 0) {
    return false;
  } else {
    switch (switcher) {
      case 1 : 
      case 2 : 
      case 3 : 
      case 5 : 
      case 6 : 
      case 7 : 
      case 9 : 
      case 10 : 
      case 11 : 
      case 12 : 
      case 13 : 
      case 15 : 
      case 16 : 
      case 17 : 
      case 18 : 
      case 19 : 
      case 21 : 
      case 22 : 
      case 23 : 
          return false;
      case 0 : 
      case 4 : 
      case 8 : 
      case 14 : 
      case 20 : 
      case 24 : 
          return true;
      
    }
  }
}

console.log(isVowel(/* "a" */97));

var greetings = "Hello world!";

var greetingAndOneSlash = "Hello\r\n    World\r\n    \\\r\n    Hehe...\r\n";

var theChar = /* "a" */97;

exports.greetings = greetings;
exports.greetingAndOneSlash = greetingAndOneSlash;
exports.name = name;
exports.sentense = sentense;
exports.theChar = theChar;
exports.isVowel = isVowel;
/* sentense Not a pure module */