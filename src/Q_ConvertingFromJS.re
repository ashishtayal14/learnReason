/* original JS file you've copied over */
/* 

JS CODE

const school = require('school');

const defaultId = 10;

function queryResult(usePayload, payload) {
  if (usePayload) {
    return payload.student
  }
  return school.getStudentById(defaultId);
} 

REASON CODE

type student; /* abstract type, described later */

[@bs.module "school"] external getStudentById : 'whatever => student = "getStudentById";

type payloadType = {. "student": student};

let defaultId = 10;

let queryResult = (usePayload, payload: payloadType) =>
  if (usePayload) {
    payload##student
  } else {
    getStudentById(defaultId)
  };


*/

/* 
Here are some of the things you'd do at this step:

-Convert the function call syntax over.
-Convert the var/const over to let.
-Hide the requires.
-Make other such changes. For idioms that don't have a BuckleScript equivalent, use bs.raw (documentation). 

*/

Q_TestJs.log("Ashish");
Q_TestJs.logWithTimeStamp("Ashish");