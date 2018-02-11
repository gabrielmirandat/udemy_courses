using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Vidly.Models;
using Vidly.ViewModels;

namespace Vidly.Controllers
{
    public class CustomersController : Controller
    {
        // GET: Customers
        public ActionResult Index()
        {
            var customers = new List<Customer>
            {
                new Customer {Id = 1, Name = "John Smith"},
                new Customer {Id = 2, Name = "Mary Willians"}
            };

            var viewModel = new RandomMovieViewModel
            {
                Movies = null,
                Customers = customers
            };

            return View(viewModel);
        }

        // GET: Customers/Details/id
        public ActionResult Details(int id)
        {
            String customerName = "";

            if (id == 1)
            {
                customerName = "John Smith";
            }
            else if (id == 2)
            {
                customerName = "Mary Willians";
            }

            return Content(customerName);
        }
    }
}