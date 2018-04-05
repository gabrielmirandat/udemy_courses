using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Vidly.Models
{
    public class Min1Max20NumberStock : ValidationAttribute
    {
        protected override ValidationResult IsValid(object value, ValidationContext validationContext)
        {
            var movie = (Movie) validationContext.ObjectInstance;

            if (movie.NumberInStock >= Movie.MinStock 
                && movie.NumberInStock <= Movie.MaxStock )
                return ValidationResult. Success;
            else 
                return new ValidationResult("Number in stock must be between 1 and 20.");
        }
    }
}