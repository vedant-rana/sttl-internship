using System.ComponentModel.DataAnnotations;

namespace OrdersFrontEnd.Models
{
    public class Customer
    {
        [Key]
        public int CustomerId { get; set; }

        [Required]
        public string? Name { get; set; }

        [Required]
        public string? Email { get; set; }

        [Required]
        public string? Address { get; set; }

        public bool? IsDeleted { get; set; } = false;
    }
}
