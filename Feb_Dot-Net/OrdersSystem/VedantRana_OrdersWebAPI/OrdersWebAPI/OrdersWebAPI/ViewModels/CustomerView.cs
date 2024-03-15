using System.ComponentModel.DataAnnotations;

namespace OrdersWebAPI.ViewModels
{
	public class CustomerView
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
