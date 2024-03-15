using System.ComponentModel.DataAnnotations;

namespace OrdersWebAPI.ViewModels
{
	public class OrderItemView
	{
		[Key]
		public int OrderItemId { get; set; }

		[Required]
		public int? OrderId { get; set; }

		[Required]
		public int? ProductId { get; set; }

		[Required]
		public int? Quantity { get; set; }

		[Required]
		public decimal? UnitPrice { get; set; }

		public bool? IsDeleted { get; set; } = false;
	}
}
