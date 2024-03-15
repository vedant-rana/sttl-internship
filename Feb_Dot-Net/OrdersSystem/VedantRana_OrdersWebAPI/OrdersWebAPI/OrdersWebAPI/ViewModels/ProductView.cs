using System.ComponentModel.DataAnnotations;

namespace OrdersWebAPI.ViewModels
{
	public class ProductView
	{
		[Key]
		public int ProductId { get; set; }

		[Required]
		public string? Name { get; set; }

		[Required]
		public string? Description { get; set; }

		[Required]
		public decimal? Price { get; set; }

		[Required]
		public int? StockQuantity { get; set; }

		public bool? IsDeleted { get; set; }= false;
	}
}
