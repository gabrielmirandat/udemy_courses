// to organize app as mvc and facilitate api rest
const express = require('express');

// to use html views inside nodejs
const exphbs = require('express-handlebars');

// to use mongo inside nodejs
const mongoose = require('mongoose');

// to pass form variables in a post from html to function
// access as req.body, req.params, ...
const bodyParser = require('body-parser');

const app = express();

// How middleware works
/* app.use(function(req, res, next){
  console.log(Date.now());
  req.name = 'Brad Traversy';
  next();
}); */

// map global promise - get rid of warning
mongoose.Promise = global.Promise;
// connect to mongoose database
mongoose.connect('mongodb://localhost/vidjot-dev', {
  useMongoClient: true
})
.then(() => console.log("MongoDB Connected..."))
.catch(err => console.log(err));
// load idea model
require('./models/Idea');
const Idea = mongoose.model('ideas');


// handlebars middleware
// to use the view direct with node
// remove if with angular
app.engine('handlebars', exphbs({
  defaultLayout: 'main'
}));
app.set('view engine', 'handlebars');

// body-parser middlewares
// and parser for application.json
app.use(bodyParser.urlencoded({extended: false}))
app.use(bodyParser.json());

// index route
app.get('/', (req, res) => {
  // send a string to browser when GET '/'
  // res.send("INDEX");
  const title = "Welcom1";
  // render page index
  res.render('index', {
    title:title
  });
})

// about route
app.get('/about', (req, res) => {
  console.log(req.query);
  console.log(req.params);
  // render page index
  res.render('about');
})

// add idea route
app.get('/ideas/add', (req, res) => {
  // render page index
  res.render('ideas/add');
})

// process form
app.post('/ideas', (req, res) => {
  console.log(req.body);
  res.send('ok');
})


const port = 5000;
app.listen(port, () => {
  console.log(`Server started on port ${port}`);
});