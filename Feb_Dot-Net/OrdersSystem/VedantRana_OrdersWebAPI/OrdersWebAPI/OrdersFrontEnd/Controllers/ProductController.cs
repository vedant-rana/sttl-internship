using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using OrdersFrontEnd.Models;
using System.Text;

namespace OrdersFrontEnd.Controllers
{
	public class ProductController : Controller
	{

		Uri baseUrl = new Uri("https://localhost:7178/api");
		private readonly HttpClient _httpClient;

		public ProductController()
        {
			_httpClient = new HttpClient();
			_httpClient.BaseAddress = baseUrl;
		}

        public IActionResult Index()
		{
			List<Product> allProducts = new List<Product>();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/products/all").Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				allProducts = JsonConvert.DeserializeObject<List<Product>>(data);
			}
			return View(allProducts);
		}


		[HttpGet]
		public IActionResult AddProduct()
		{
			return View();
		}

		[HttpPost]
		public async Task<IActionResult> AddProduct(Product newProduct)
		{
			if (ModelState.IsValid)
			{
				var json = JsonConvert.SerializeObject(newProduct);
				var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

				HttpResponseMessage response = await _httpClient.PostAsync(_httpClient.BaseAddress + "/products", stringContent);

				if (response.IsSuccessStatusCode)
				{
					return RedirectToAction("Index");
				}
				else
				{
					return View(newProduct);
				}
			}
			return View(newProduct);
		}


		[HttpGet]
		public IActionResult ProductDetails(int id)
		{
			return GetProductById(id);
		}

		[HttpGet]
		public IActionResult UpdateProduct(int id)
		{
			return GetProductById(id);
		}

		[HttpPost]
		[ActionName("UpdateProduct")]
		public async Task<IActionResult> UpdateProductDetails(int id, Product cust)
		{
			if (ModelState.IsValid)
			{
				var json = JsonConvert.SerializeObject(cust);
				var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

				HttpResponseMessage response = await _httpClient.PutAsync(_httpClient.BaseAddress + "/products/" + id, stringContent);

				if (response.IsSuccessStatusCode)
				{
					return RedirectToAction("Index");
				}
			}
			return View(cust);
		}


		[HttpGet]
		public async Task<IActionResult> DeleteProduct(int id)
		{
			HttpResponseMessage response = await _httpClient.DeleteAsync($"{_httpClient.BaseAddress}/products/{id}");


			if (response.IsSuccessStatusCode)
			{

				return RedirectToAction("Index");
			}
			else
			{
				return RedirectToAction("Index");
			}
		}


		private IActionResult GetProductById(int id)
		{
			Product? product = new Product();
			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/products/" + id).Result;

			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				product = JsonConvert.DeserializeObject<Product>(data);
				if (product != null)
				{
					return View(product);
				}
			}
			return NotFound();
		}

	}
}
