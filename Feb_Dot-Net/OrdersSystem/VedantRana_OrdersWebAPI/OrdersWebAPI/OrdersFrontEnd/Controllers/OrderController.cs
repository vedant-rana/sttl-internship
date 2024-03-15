using Microsoft.AspNetCore.Http.Features;
using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using OrdersFrontEnd.Models;
using System.Collections.Generic;
using System.Text;

namespace OrdersFrontEnd.Controllers
{
	public class OrderController : Controller
	{
		Uri baseUrl = new Uri("https://localhost:7178/api");
		private readonly HttpClient _httpClient;

		public OrderController()
        {
			_httpClient = new HttpClient();
			_httpClient.BaseAddress = baseUrl;
		}

		private void PopulateCustomersDropdown()
		{
			List<Customer> allCustomers = new List<Customer>();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/customers/all").Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				allCustomers = JsonConvert.DeserializeObject<List<Customer>>(data);

				List<OrderCustomerModel> custs = new();
				foreach (Customer customer in allCustomers)
				{
					OrderCustomerModel o = new OrderCustomerModel()
					{
						CustId = customer.CustomerId,
						CustName = customer.Name
					};
					custs.Add(o);
				}

				ViewBag.customerList = custs;
			}
		}

		private IActionResult GetOrderById(int id)
		{
			Order? order = new Order();
			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/orders/" + id).Result;

			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				order = JsonConvert.DeserializeObject<Order>(data);
				if (order != null)
				{
					return View(order);
				}
			}
			return NotFound();
		}

		[HttpGet]
		public IActionResult Index()
		{
			List<Order> allOrders = new List<Order>();
			PopulateCustomersDropdown();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/orders/all").Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				allOrders = JsonConvert.DeserializeObject<List<Order>>(data);
			}
			return View(allOrders);
		}


		[HttpGet]
		public IActionResult AddOrder()
		{
			PopulateCustomersDropdown();
			return View();
		}

		[HttpPost]
		public async Task<IActionResult> AddOrder(Order newOrder)
		{
			if (ModelState.IsValid)
			{
				//PopulateCustomersDropdown();
				var json = JsonConvert.SerializeObject(newOrder);
				var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

				HttpResponseMessage response = await _httpClient.PostAsync(_httpClient.BaseAddress + "/orders", stringContent);

				if (response.IsSuccessStatusCode)
				{
					return RedirectToAction("Index");
				}
				else
				{
					return View(newOrder);
				}
			}
			return View(newOrder);
		}



		[HttpGet]
		public IActionResult OrderDetails(int id)
		{
			List<OrderItem> items = new List<OrderItem>();
			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/orders/orderItems/" + id).Result;

			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				items = JsonConvert.DeserializeObject<List<OrderItem>>(data);
				ViewBag.allItemsForOrder = items;
			}
			return GetOrderById(id);
		}


		[HttpGet]
		public IActionResult UpdateOrder(int id)
		{
			PopulateCustomersDropdown() ;
			return GetOrderById(id);
		}

		[HttpPost]
		[ActionName("UpdateOrder")]
		public async Task<IActionResult> UpdateOrderDetails(int id, Order ord)
		{
			if (ModelState.IsValid)
			{
				var json = JsonConvert.SerializeObject(ord);
				var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

				HttpResponseMessage response = await _httpClient.PutAsync(_httpClient.BaseAddress + "/orders/" + id, stringContent);

				if (response.IsSuccessStatusCode)
				{
					return RedirectToAction("Index");
				}
			}
			return View(ord);
		}


		[HttpGet]
		public async Task<IActionResult> DeleteOrder(int id)
		{
			HttpResponseMessage response = await _httpClient.DeleteAsync($"{_httpClient.BaseAddress}/orders/{id}");


			if (response.IsSuccessStatusCode)
			{

				return RedirectToAction("Index");
			}
			else
			{
				return RedirectToAction("Index");
			}
		}
	}
}
