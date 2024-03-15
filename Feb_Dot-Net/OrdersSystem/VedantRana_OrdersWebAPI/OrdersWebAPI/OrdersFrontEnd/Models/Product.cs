using System.ComponentModel.DataAnnotations;

namespace OrdersFrontEnd.Models
{
	public class Product
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

		public bool? IsDeleted { get; set; } = false;
	}
}
