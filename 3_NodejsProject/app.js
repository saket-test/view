const express = require("express");
// const { default: mongoose } = require("mongoose");
const mongoose = require("mongoose");
const morgan = require("morgan");
// const Blog = require("./models/blog");
const blogRoutes = require("./routes/blogRoutes");


// --------- Express App
const app = express();

// --------- Connect to mongoDB
const dbURI = "mongodb+srv://<username>:<password>@cluster0.t5lhtvc.mongodb.net/nodeJS_test?retryWrites=true&w=majority";
mongoose.connect(dbURI).then((result) =>console.log("Connected to db")).catch((err) => console.log(err))
// {useNewUrlParser: true, useUnifiedTopolgy: true}


// ----------- Register view engine
app.set("view engine", "ejs");
// app.set("views", "folder_name")  ------ To change folder name

// ----------- Listen for requests
app.listen(3000);
console.log("Server running at http://127.0.0.1:3000/")

// ----------- Middleware and static files
app.use(morgan("tiny"));
app.use(morgan("dev"));

/* takes the URL encoded data coming, and passes it to an object that can be used on the request object (Used when using POST method) 
qs library: third-party library | extends the functionality of the built-in querystring module.
It provides additional features, including support for nested objects and arrays in the URL-encoded data.
{extended: true} => the qs library is used for parsing.
*/
app.use(express.urlencoded({extended: true}));

app.use(express.static("public"));

// //  ---------- mongoose and mongo sandbox routes
// app.get("/add-blog", (req, res) =>{
//     const blog = new Blog({
//         title: "New blog 2",
//         snippet: "About the blog",
//         body: "body of the blog",
//     });
//     blog.save().then((result) => {
//         res.send(result)
//     }).catch((err) => {
//         console.log(err)
//     });
// })

// app.get("/all-blogs", (req, res) => {
//     Blog.find()
//         .then((result) => {
//             res.send(result)
//             })
//         .catch((err) =>{
//             console.group(err)
//         })
// })

// app.get("/single-blog", (req,res) => {
//     Blog.findById("65a8e9ed29add96589062063")
//         .then((result) => {
//             res.send(result)
//         })
//         .catch((err) =>{
//             console.group(err)
//         })
// })

app.get("/", (req, res) => {
    // res.sendFile( "./views/index.html", {root: __dirname});
    res.redirect("/blogs")
})

app.get("/about", (req, res) => {
    // res.sendFile( "./views/about.html", {root: __dirname});
    res.render('about', { title: 'About' });
})


// ----------- Redirects
app.get("/", (req, res) => {
    res.redirect("/about");
})


//  bogRoutes
app.use("/blogs", blogRoutes);


// ----------- 404 page
app.use((req, res) => {
    res.status(404).render('404', { title: '404' });
})