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

        [Required(ErrorMessage = "Please enter movie's name.")]
        [StringLength(255)]
        public String Name { get; set; }

        [Required]
        [Display(Name = "Release Date")]
        public DateTime ReleaseDate { get; set; }

        public DateTime AddedDate { get; set; }

        [Display(Name = "Number In Stock")]
        [Min1Max20NumberStock]
        public int NumberInStock { get; set; }

        [Display(Name = "Genre Type")]
        public byte GenreId { get; set; }

        public Genre Genre { get; set; }

        public static readonly byte MinStock = 1;
        public static readonly byte MaxStock = 20;
    }

    // /movies/random
}