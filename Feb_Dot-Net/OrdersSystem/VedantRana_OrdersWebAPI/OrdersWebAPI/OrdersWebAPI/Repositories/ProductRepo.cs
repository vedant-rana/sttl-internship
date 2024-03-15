using Microsoft.EntityFrameworkCore;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Repositories
{
	public class ProductRepo : IProduct
	{
		private readonly OrdersDbContext _context;

        public ProductRepo(OrdersDbContext context)
        {
            _context = context;	
        }

        public async Task<List<ProductView>> GetAllProducts()
		{
			List<Product> allProducts = await _context.Products.Where(pro=>pro.IsDeleted == false).ToListAsync();

			List<ProductView> ans = allProducts.Select(p=>ConvertToProductView(p)).ToList();	 
			return ans;
		}

		public async Task<ProductView> GetProductById(int id)
		{
			ProductView pv = new ProductView();
			Product? p = await _context.Products.Where(p => p.ProductId == id && p.IsDeleted == false).FirstOrDefaultAsync();


			if (p != null)
			{
				pv = ConvertToProductView(p);
			}
			return pv;
		}


        public bool AddProduct(ProductView pv)
		{
			if (pv != null)
			{
				Product p = ConvertToProduct(pv);
				_context.Products.Add(p);
				int res = _context.SaveChanges();

				if (res > 0)
				{
					return true;
				}
				return false;
			}
			return false;
		}


		public async Task<bool> UpdateProduct(int id, ProductView pv)
		{
			if (id != pv.ProductId)
			{
				return false;
			}

			Product p = ConvertToProduct(pv);
			_context.Entry(p).State = EntityState.Modified;

			int res = await _context.SaveChangesAsync();

			if (res > 0)
			{
				return true;
			}
			return false;
		}

		public async Task<bool> DeleteProduct(int id)
		{
			Product? p = await _context.Products
							.Where(pro => pro.ProductId == id && pro.IsDeleted == false)
							.FirstOrDefaultAsync();
			if (p != null)
			{
				p.IsDeleted = true;
				int res = _context.SaveChanges();
				if (res > 0)
				{
					return true;
				}
			}
			return false;
		}


		private ProductView ConvertToProductView(Product p)
		{
			ProductView pv = new()
			{
				ProductId = p.ProductId,
				Name = p.Name,
				Description = p.Description,
				Price = p.Price,
				StockQuantity = p.StockQuantity,
				IsDeleted = p.IsDeleted
			};

			return pv;
		}

		private Product ConvertToProduct(ProductView pv)
		{
			Product p = new()
			{
				ProductId = pv.ProductId,
				Name = pv.Name,
				Description = pv.Description,
				Price = pv.Price,
				StockQuantity = pv.StockQuantity,
				IsDeleted = pv.IsDeleted
			};

			return p;
		}
	}
}
