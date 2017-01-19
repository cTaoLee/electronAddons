// test.js
const addon = require('./build/Release/addon');

let fn = addon();

console.log(fn());

