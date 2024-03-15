using Microsoft.EntityFrameworkCore;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Repositories
{
	public class CustomerRepo : ICustomer
	{
		private readonly OrdersDbContext _context;

		public CustomerRepo(OrdersDbContext context)
		{
			_context = context;
		}

		public async Task<List<CustomerView>> GetAllCustomers()
		{

			List<Customer> allCustomers = await _context.Customers.Where(cust => cust.IsDeleted == false).ToListAsync();
			List<CustomerView> ans = allCustomers.Select(cust => ConvertToCustomerView(cust)).ToList();
			return ans;

		}


		public async Task<CustomerView> GetCustomerById(int id)
		{
			CustomerView cv = new CustomerView();
			Customer? p = await _context.Customers
							.Where(c => c.CustomerId == id && c.IsDeleted == false)
							.FirstOrDefaultAsync();


			if (p != null)
			{
				cv = ConvertToCustomerView(p);
			}
			return cv;
		}


		public bool AddCustomer(CustomerView cv)
		{
			if (cv != null)
			{
				Customer c = ConvertToCustomer(cv);
				_context.Customers.Add(c);
				int res = _context.SaveChanges();

				if (res > 0)
				{
					return true;
				}
				return false;
			}
			return false;
		}


		public async Task<bool> UpdateCustomer(int id, CustomerView cv)
		{
			if (id != cv.CustomerId)
			{
				return false;
			}

			Customer c = ConvertToCustomer(cv);
			_context.Entry(c).State = EntityState.Modified;

			int res = await _context.SaveChangesAsync();

			if (res > 0)
			{
				return true;
			}
			return false;
		}


		public async Task<bool> DeleteCustomer(int id)
		{
			Customer? c = await _context.Customers
							.Where(cust => cust.CustomerId == id && cust.IsDeleted == false)
							.FirstOrDefaultAsync();
			if (c != null)
			{
				c.IsDeleted = true;
				int res = _context.SaveChanges();
				if (res > 0)
				{
					return true;
				}
			}
			return false;
		}



		private CustomerView ConvertToCustomerView(Customer p)
		{
			CustomerView cv = new()
			{
				CustomerId = p.CustomerId,
				Name = p.Name,
				Email = p.Email,
				Address = p.Address,
				IsDeleted = p.IsDeleted
			};

			return cv;
		}

		private Customer ConvertToCustomer(CustomerView p)
		{
			Customer c = new()
			{
				CustomerId = p.CustomerId,
				Name = p.Name,
				Email = p.Email,
				Address = p.Address,
				IsDeleted = p.IsDeleted
			};

			return c;
		}

		public async Task<List<OrderView>> usersAllOrders(int id)
		{
			List<Order> usersOrders = await _context.Orders.Where(ord => ord.CustomerId == id && ord.IsDeleted == false).ToListAsync();
			List<OrderView> orders = usersOrders.Select(p => new OrderView()
			{
				OrderId = p.OrderId,
				CustomerId = p.CustomerId,
				OrderDate = p.OrderDate,
				TotalAmount = p.TotalAmount,
				Status = p.Status,
				IsDeleted = p.IsDeleted,
			}).ToList();
			return orders;
		}
	}
}
