using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Controllers
{
	[Route("api/customers")]
	[ApiController]
	public class CustomerController : ControllerBase
	{
		private readonly ICustomer customer;

		public CustomerController(ICustomer customer)
        {
			this.customer = customer;
		}

		[HttpGet]
		[Route("all")]
		public  Task<List<CustomerView>> GetAllCustomers() 
		{
			return customer.GetAllCustomers();
		}
		
		[HttpGet]
		[Route("orders/{id}")]
		public  Task<List<OrderView>> GetAllUsersOrders(int id) 
		{
			return customer.usersAllOrders(id);
		}

		[HttpGet("{id}")]
		public Task<CustomerView> GetCustomerById(int id) {
			return customer.GetCustomerById(id);
		}


		[HttpPost]
		public bool AddCustomer(CustomerView cv)
		{
			return customer.AddCustomer(cv);
		}

		[HttpPut("{id}")]
		public Task<bool> UpdateCustomer(int id, CustomerView c) { 
			return customer.UpdateCustomer(id, c);
		}

		[HttpDelete("{id}")]
		public Task<bool> DeleteCustomerById(int id)
		{
			return customer.DeleteCustomer(id);
		}
    }
}
