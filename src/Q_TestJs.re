/* in a dedicated School.re file */
/* 
type student;

[@bs.module "School"] external getStudentById : int => student = "getStudentById";
[@bs.module "School"] external getAllStudents : unit => array(student) = "getAllStudents"; 
*/


[@bs.module "./Q_TestJs"] external log : string => bool = "log";
[@bs.module "./Q_TestJs"] external logWithTimeStamp : string => bool = "logWithTimeStamp";