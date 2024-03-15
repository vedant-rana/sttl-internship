using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using OrdersFrontEnd.Models;
using System.Text;

namespace OrdersFrontEnd.Controllers
{
	public class CustomerController : Controller
	{

		Uri baseUrl = new Uri("https://localhost:7178/api");
		private readonly HttpClient _httpClient;

		public CustomerController()
		{
			_httpClient = new HttpClient();
			_httpClient.BaseAddress = baseUrl;
		}


		[HttpGet]
		public IActionResult Index()
		{
			List<Customer> allPatients = new List<Customer>();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/customers/all").Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				allPatients = JsonConvert.DeserializeObject<List<Customer>>(data);
			}
			return View(allPatients);
		}


		[HttpGet]
		public IActionResult AddCustomer()
		{
			return View();
		}

		[HttpPost]
		public async Task<IActionResult> AddCustomer(Customer newCustomer)
		{
			if (ModelState.IsValid)
			{
				var json = JsonConvert.SerializeObject(newCustomer);
				var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

				HttpResponseMessage response = await _httpClient.PostAsync(_httpClient.BaseAddress + "/customers", stringContent);

				if (response.IsSuccessStatusCode)
				{
					return RedirectToAction("Index");
				}
				else
				{
					return View(newCustomer);
				}
			}
			return View(newCustomer);
		}



		[HttpGet]
		public IActionResult CustomerDetails(int id)
		{
			return GetCustomerById(id);
		}

		[HttpGet]
		public IActionResult UpdateCustomer(int id)
		{
			return GetCustomerById(id);
		}

		[HttpPost]
		[ActionName("UpdateCustomer")]
		public async Task<IActionResult> UpdateCustomerDetails(int id, Customer cust)
		{
			if (ModelState.IsValid)
			{
				var json = JsonConvert.SerializeObject(cust);
				var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

				HttpResponseMessage response = await _httpClient.PutAsync(_httpClient.BaseAddress + "/customers/" + id, stringContent);

				if (response.IsSuccessStatusCode)
				{
					return RedirectToAction("Index");
				}
			}
			return View(cust);
		}


		[HttpGet]
		public async Task<IActionResult> DeleteCustomer(int id)
		{
			HttpResponseMessage response = await _httpClient.DeleteAsync($"{_httpClient.BaseAddress}/customers/{id}");


			if (response.IsSuccessStatusCode)
			{

				return RedirectToAction("Index");
			}
			else
			{
				return RedirectToAction("Index");
			}
		}

		[HttpGet]
		public IActionResult GetAllOrders(int id)
		{
			List<Order> orders = new List<Order>();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/customers/orders/"+id).Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				orders = JsonConvert.DeserializeObject<List<Order>>(data);
			}
			return View(orders);
		}


		private IActionResult GetCustomerById(int id)
		{
			Customer? customer = new Customer();
			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/customers/" + id).Result;

			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				customer = JsonConvert.DeserializeObject<Customer>(data);
				if (customer != null)
				{
					return View(customer);
				}
			}
			return NotFound();
		}
	}
}
