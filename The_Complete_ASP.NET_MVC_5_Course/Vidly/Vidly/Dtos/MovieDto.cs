using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;
using Vidly.Models;

namespace Vidly.Dtos
{
    public class MovieDto
    {
        public int Id { get; set; }

        [Required(ErrorMessage = "Please enter movie's name.")]
        [StringLength(255)]
        public String Name { get; set; }

        [Required]
        public DateTime ReleaseDate { get; set; }

        public DateTime AddedDate { get; set; }

        // [Min1Max20NumberStock]
        public int NumberInStock { get; set; }

        public GenreDto Genre { get; set; }

        public byte GenreId { get; set; }
    }
}