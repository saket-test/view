// var slugify = require("slugify");

// console.log("Hello World");

// let a = slugify("some string!@#$%");
// console.log(a);

// let b = slugify("some string", "_");
// console.log(b);


// import http from "http"     // If type: module in packages.json
const http = require('node:http');

const hostname = '127.0.0.1';
const port = 3000;

// -------------------req = request object || res = response object
const server = http.createServer((req, res) => {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/html');
    res.end('<h1>Hello World</h1>\n');
});
server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
});



// import {a, b, c, obj} from "./numbers.js" // Named Export
// import dict from "./numbers.js" // Default Export
// console.log(`a: ${a}\nb: ${b}\nc: ${c}`)
// console.log(dict)