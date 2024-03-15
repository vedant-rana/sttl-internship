using System.ComponentModel.DataAnnotations;

namespace OrdersFrontEnd.Models
{
	public class Order
	{
		[Key]
		public int OrderId { get; set; }

		[Required]
		public int? CustomerId { get; set; }

		public DateOnly? OrderDate { get; set; } = DateOnly.FromDateTime(DateTime.Now);

		public decimal? TotalAmount { get; set; } = 0;

		public string? Status { get; set; } = "Processing";

		public bool? IsDeleted { get; set; } = false;
	}
}
