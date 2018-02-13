using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Vidly.Models;
using Vidly.ViewModels;

namespace Vidly.Movies
{
    public class MoviesController : Controller
    {

        private ApplicationDbContext _context;

        public MoviesController()
        {
            _context = new ApplicationDbContext();
        }

        protected override void Dispose(bool disposing)
        {
            _context.Dispose();
        }

        // GET: Movies/Random
        public ActionResult Index()
        {
            // var movie = new Movie() {Name = "Shrek!"};
            // return View(movie);
            // return Content("Hello World!");
            // return HttpNotFound();
            // return new EmptyResult();
            // return RedirectToAction("Index", "Home",new {page=1,sortBy="name"});

            var movies = _context.Movies.Include(m => m.Genre).ToList();

            return View(movies);

        }

        // GET: Movies/Details/id
        public ActionResult Details(int id)
        {
            var movie = _context.Movies.Include(c => c.Genre).SingleOrDefault(m => m.Id == id);

            if (movie == null)
                return HttpNotFound();

            return View(movie);
        }

        // GET: Movies/Edit/id or Movies/Edit?id={id}
        public ActionResult Edit(int id)
        {
            return Content("id=" + id);
        }

        // GET: Movies/Index?pageIndex={pageIndex}&stringSortBy={stringSortBy}
        public ActionResult Index2(int? pageIndex, string sortBy)
        {
            if (!pageIndex.HasValue)
                pageIndex = 1;
            if (String.IsNullOrWhiteSpace(sortBy))
                sortBy = "Name";

            return Content(String.Format("pageIndex={0}&sortBy={1}", pageIndex, sortBy));
        }

        // GET: Movies/released/year/month
        [Route("movies/released/{year}/{month:regex(\\d{2}):range(1,12)}")]
        public ActionResult ByReleaseYear(int year, int month)
        {
            return Content("ByReleaseYear: " + year + "/" + month);
        }
    }
}