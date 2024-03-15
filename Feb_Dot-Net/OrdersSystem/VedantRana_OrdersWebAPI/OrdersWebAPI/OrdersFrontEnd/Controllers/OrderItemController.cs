using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using OrdersFrontEnd.Models;
using System.Security.Cryptography;
using System.Text;

namespace OrdersFrontEnd.Controllers
{
	public class OrderItemController : Controller
	{
		Uri baseUrl = new Uri("https://localhost:7178/api");
		private readonly HttpClient _httpClient;


        public OrderItemController()
        {
			_httpClient = new HttpClient();
			_httpClient.BaseAddress = baseUrl;
		}

		private async void UpdatePriceOfOrder(int? id, decimal? unitPrice)
		{
			Order order = new Order();
			HttpResponseMessage response =  _httpClient.GetAsync(_httpClient.BaseAddress + "/orders/" + id).Result;

			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				order = JsonConvert.DeserializeObject<Order>(data);
				if (order != null)
				{
					order.TotalAmount += unitPrice;
					var json = JsonConvert.SerializeObject(order);
					var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

					await _httpClient.PutAsync(_httpClient.BaseAddress + "/orders/" + id, stringContent);
				}
			}
		}

		private async void UpdateProductQuantity(int? id, int? quantity)
		{
			Product product = new Product();
			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/products/" + id).Result;
			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				product = JsonConvert.DeserializeObject<Product>(data);
				if (product != null)
				{
					product.StockQuantity -= quantity;
					var json = JsonConvert.SerializeObject(product);
					var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

					await _httpClient.PutAsync(_httpClient.BaseAddress + "/products/" + id, stringContent);
				}
			}
		}

		private void SetAllProductsToViewBag()
		{
			List<Product> allProducts = new List<Product>();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/products/all").Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				allProducts = JsonConvert.DeserializeObject<List<Product>>(data);
			}
			ViewBag.productsList = allProducts;

		}

        public IActionResult Index()
		{
			List<OrderItem> allItems = new List<OrderItem>();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/orderItem/all").Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				allItems = JsonConvert.DeserializeObject<List<OrderItem>>(data);
			}
			return View(allItems);
		}


		[HttpGet]
		public IActionResult AddOrderItem(int id)
		{
			SetAllProductsToViewBag();
			ViewBag.ordersId = id;
			return View();
		}

		[HttpPost]
		public async Task<IActionResult> AddOrderItem(OrderItem newOrderItem)
		{
			if (ModelState.IsValid)
			{
				UpdatePriceOfOrder(newOrderItem.OrderId, newOrderItem.UnitPrice);
				UpdateProductQuantity(newOrderItem.ProductId, newOrderItem.Quantity);
				var json = JsonConvert.SerializeObject(newOrderItem);
				var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

				HttpResponseMessage response = await _httpClient.PostAsync(_httpClient.BaseAddress + "/orderItem", stringContent);

				if (response.IsSuccessStatusCode)
				{
					return RedirectToAction("Index");
				}
				else
				{
					return View(newOrderItem);
				}
			}
			return View(newOrderItem);
		}


        [HttpGet]
        public IActionResult OrderItemDetails(int id)
        {
            return GetOrderItemById(id);
        }


        [HttpGet]
        public async Task<IActionResult> DeleteOrderItem(int id)
        {
            HttpResponseMessage response = await _httpClient.DeleteAsync($"{_httpClient.BaseAddress}/orderItem/{id}");


            if (response.IsSuccessStatusCode)
            {

                return RedirectToAction("Index");
            }
            else
            {
                return RedirectToAction("Index");
            }
        }


        private IActionResult GetOrderItemById(int id)
        {
            OrderItem? item = new OrderItem();
            HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/orderItem/" + id).Result;

            if (response.IsSuccessStatusCode)
            {
                string data = response.Content.ReadAsStringAsync().Result;
                item = JsonConvert.DeserializeObject<OrderItem>(data);
                if (item != null)
                {
                    return View(item);
                }
            }
            return NotFound();
        }
    }
}
