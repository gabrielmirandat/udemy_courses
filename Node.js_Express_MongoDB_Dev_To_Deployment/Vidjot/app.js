// to organize app as mvc and facilitate api rest
const express = require('express');

// to use html views inside nodejs
const exphbs = require('express-handlebars');

// to use mongo inside nodejs
// COMMANDS - mongod, mongo, show dbs, use vidjot-dev, show collections, db.ideas.find()
const mongoose = require('mongoose');

// to pass form variables in a post from html to function
// access as req.body, req.params, ...
const bodyParser = require('body-parser');

// to use put and delete
// needs to use ?_method=
// needs to use a hidden input like
// <input type="hidden" name="_method" value="DELETE">
const methodOverride = require('method-override');

// used for authentication
const session = require('express-session')

// used to display a flash message before 
// redirecting to another page
const flash = require('connect-flash');

const app = express();

// How middleware works
/* app.use(function(req, res, next){
  console.log(Date.now());
  req.name = 'Brad Traversy';
  next();
}); */

// map global promise - get rid of warning
// connect to mongoose database
// load idea model
mongoose.Promise = global.Promise;
mongoose.connect('mongodb://localhost/vidjot-dev', {
  useMongoClient: true
})
.then(() => console.log("MongoDB Connected..."))
.catch(err => console.log(err));
require('./models/Idea');
const Idea = mongoose.model('ideas');

// MIDDLEWARES

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

// express-session middleware
app.use(session({
  secret: 'secret',
  resave: true,
  saveUninitialized: true
}))

// flash middleware
app.use(flash());

// method-override middleware
app.use(methodOverride('_method'));

// GLOBAL VARIABLES (middleware for flash)
app.use(function(req, res, next){
  res.locals.success_msg = req.flash('success_msg');
  res.locals.error_msg = req.flash('error_msg');
  res.locals.error = req.flash('error');
  next();
})

// GETS

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
  // console.log(req.query);
  // console.log(req.params);
  // render page index
  res.send('about');
})

// index idea
// send the ideas from database
app.get('/ideas', (req, res) => {
  Idea.find({})
    .sort({date:'desc'})
    .then(ideas => {
      // console.log(ideas)
      res.render('ideas/index', {
        ideas:ideas
      });
    });
})

// add idea
app.get('/ideas/add', (req, res) => {
  // render page index
  res.render('ideas/add');
})

// edit idea
app.get('/ideas/edit/:id', (req, res) => {
  // render page edit
  Idea.findOne({
    _id: req.params.id
  })
  .then(idea => {
    res.render('ideas/edit', {
      idea:idea
    })
  })
})

// POSTS, PUTS, DELETES

// create idea
app.post('/ideas', (req, res) => {
  // console.log(req.body);
  
  let errors = [];

  if(!req.body.title){
    errors.push({text:'Please fill title'});
  }

  if(!req.body.details){
    errors.push({text:'Please fill details'});
  }

  if(errors.length)
  {
    res.render('ideas/add', {
      errors: errors,
      title: req.body.title,
      details: req.body.details
    });
  }else{
    const newUser = {
      title: req.body.title,
      details: req.body.details
    }
    new Idea(newUser)
      .save()
      .then(idea => {
        req.flash('success_msg', 'Video idea added');
        res.redirect('/ideas');
      })
  }
});

// edit idea
app.put('/ideas/:id', (req, res) => {
  Idea.findOne({
    _id: req.params.id
  })
  .then(idea => {
    // new values
    idea.title = req.body.title;
    idea.details = req.body.details;

    idea.save()
    .then(idea => {
      req.flash('success_msg', 'Video idea edited');
      res.redirect('/ideas');
    })
  });
});

// remove idea
app.delete('/ideas/:id', (req, res) => {
  Idea.remove({
    _id: req.params.id
  })
  .then(() => {
    req.flash('success_msg', 'Video idea removed');
    res.redirect('/ideas');
  })
})


const port = 5000;
app.listen(port, () => {
  console.log(`Server started on port ${port}`);
});