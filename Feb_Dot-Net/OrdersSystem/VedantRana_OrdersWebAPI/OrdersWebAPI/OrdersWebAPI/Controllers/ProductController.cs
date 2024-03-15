using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Controllers
{
    [Route("api/products")]
    [ApiController]
    public class ProductController : ControllerBase
    {
        private readonly IProduct product;

        public ProductController(IProduct product)
        {
            this.product = product;
        }


        [HttpGet]
        [Route("all")]
        public Task<List<ProductView>> GetAllProducts()
        {
            return product.GetAllProducts();
        }

        [HttpGet("{id}")]
        public Task<ProductView> GetProductById(int id)
        {
            return product.GetProductById(id);
        }


        [HttpPost]
        public bool AddProduct(ProductView cv)
        {
            return product.AddProduct(cv);
        }

        [HttpPut("{id}")]
        public Task<bool> UpdateProduct(int id, ProductView c)
        {
            return product.UpdateProduct(id, c);
        }

        [HttpDelete("{id}")]
        public Task<bool> DeleteProductById(int id)
        {
            return product.DeleteProduct(id);
        }
    }
}
