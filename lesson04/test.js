const addon = require('./build/Release/addon');

let obj = addon('hello world')

console.log(obj.msg);