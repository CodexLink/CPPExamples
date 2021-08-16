//require('../Subfolder/logger'); — Different File Path Instance

// ! Always Store Required Classes in CONST
// ! Only if Module Runnable for One Time
// const externLogger = require('./logger');
// console.log(externLogger);
// externLogger.log('This is a test!', 'Information');

// var http = require('http');
// const currentDate = require('./date');

// ! Pre-HTTP Module
//http.createServer(function (req, res) {
//  res.writeHead(200, {'Content-Type': 'text/html'});
//  res.end('Today is ' + currentDate.showDate() + ', Hello World!');
//}).listen(8080);

// ! FS Module

// ! Event Emitter — Very Similar on ESP8266WebServer Functionality
//const EE = require('events');
//const emitter = new EE();
//
//// Listener Registration with Arrow Function in ES6
//emitter.on('messageLogged', (e_args) => {
//    console.log('Listener Called.');
//    console.log('Emitter Arguments: ', e_args)
//})
//
//// !                         Arguments on Emitter Listener, Can Accept Anything
//emitter.emit('messageLogged', {id: 1, url: 'http://'}); // Making Event Happened. | Raise Event

// Raise: Logging (Data: message), Exercise

// ! Extending EventEmitter with Logger.js
//const EE = require('events');
//const emitter = new EE();

//const Logger = require('./logger'); // ! IMPORTANT, This is a BluePrint now.
//const ActualLogger = new Logger(); // ! Actual Object.
//
//ActualLogger.on('messageLogged', (e_args) => {
//    console.log('messageLogged: Listener Called.');
//    console.log('Emitter Arguments: ', e_args)
//});
//
//ActualLogger.log('message', 1); // Event Emitter Will NOT WORK
// Cause: Two Conflicting Event Emitter
// Solution: Create a Class on Logger.js


// ! HTTP Module
const http = require('http');

const ServerObj = http.createServer((req, res) => {
    if (req.url === '/') {
        res.end('Hello World!');
    }

    if (req.url === '/api/obtain_courses') {
        res.end(JSON.stringify([1, 1, 2, 3, 4, 5, 6, 7, 8]));
    }
});

ServerObj.on('connection', (socket) => {
    console.log('New Connection Instantiated.');
});


ServerObj.listen(8000);

console.log('Listening on Port 8000 | Press Terminal Breaking Commands to Stop.')