using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Vidly.Models
{
    public class Movie
    {
        public int Id { get; set; }
        public String Name { get; set; }
        public DateTime ReleaseDate { get; set; }
        public DateTime AddedDate { get; set; }
        public int NumberInStock { get; set; }

        [Display(Name = "Genre Type")]
        public byte GenreId { get; set; }

        public Genre Genre { get; set; }
    }

    // /movies/random
}