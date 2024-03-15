using System.ComponentModel.DataAnnotations;

namespace OrdersWebAPI.ViewModels
{
	public class OrderView
	{
		[Key]
		public int OrderId { get; set; }

		[Required]
		public int? CustomerId { get; set; }

		public DateOnly? OrderDate { get; set; } = DateOnly.FromDateTime(DateTime.Now);

        [Required]
		public decimal? TotalAmount { get; set; }

		[Required]
		public string? Status { get; set; }

		public bool? IsDeleted { get; set; }=false;
	}
}
