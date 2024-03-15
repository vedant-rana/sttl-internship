using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Interfaces
{
	public interface ICustomer
	{
		Task<List<CustomerView>> GetAllCustomers();
		Task<CustomerView> GetCustomerById(int id);

		Task<bool> DeleteCustomer(int id);

		bool AddCustomer(CustomerView pd);

		Task<bool> UpdateCustomer(int id, CustomerView pd);

		Task<List<OrderView>> usersAllOrders(int id);
	}
}
