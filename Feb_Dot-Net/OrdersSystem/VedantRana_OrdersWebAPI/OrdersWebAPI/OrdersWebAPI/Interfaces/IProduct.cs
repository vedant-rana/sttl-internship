using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Interfaces
{
	public interface IProduct
	{
		Task<List<ProductView>> GetAllProducts();
		Task<ProductView> GetProductById(int id);

		Task<bool> DeleteProduct(int id);

		bool AddProduct(ProductView pd);

		Task<bool> UpdateProduct(int id, ProductView pd);
	}
}
