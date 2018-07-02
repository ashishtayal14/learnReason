module.exports.log = content => {console.log(content); return true}; 
module.exports.logWithTimeStamp = content => {console.log(`${new Date(Date.now())} : ${content}`); return true};