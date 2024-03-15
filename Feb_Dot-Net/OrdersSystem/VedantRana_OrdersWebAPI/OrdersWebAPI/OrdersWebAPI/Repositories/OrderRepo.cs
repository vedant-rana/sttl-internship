using Microsoft.EntityFrameworkCore;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Repositories
{
    public class OrderRepo : IOrder
    {
        private readonly OrdersDbContext _context;

        public OrderRepo(OrdersDbContext context)
        {
            _context = context;
        }

        public async Task<List<OrderView>> GetAllOrders()
        {
            List<Order> allOrders = await _context.Orders.Where(ord => ord.IsDeleted == false).ToListAsync();
            List<OrderView> ans = allOrders.Select(o => ConvertToOrderView(o)).ToList();
            return ans;
        }


        public async  Task<OrderView> GetOrderById(int id)
        {
            OrderView cv = new OrderView();
            Order? p = await _context.Orders
                            .Where(c => c.OrderId == id && c.IsDeleted == false)
                            .FirstOrDefaultAsync();


            if (p != null)
            {
                cv = ConvertToOrderView(p);
            }
            return cv;
        }

        public bool AddOrder(OrderView cv)
        {
            if (cv != null)
            {
                Order c = ConvertToOrder(cv);
                _context.Orders.Add(c);
                int res = _context.SaveChanges();

                if (res > 0)
                {
                    return true;
                }
                return false;
            }
            return false;
        }

        public async Task<bool> DeleteOrder(int id)
        {
            Order? c = await _context.Orders
                            .Where(ord => ord.OrderId == id && ord.IsDeleted == false)
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


        public async Task<bool> UpdateOrder(int id, OrderView cv)
        {
            if (id != cv.OrderId)
            {
                return false;
            }

            Order c = ConvertToOrder(cv);
            _context.Entry(c).State = EntityState.Modified;

            int res = await _context.SaveChangesAsync();

            if (res > 0)
            {
                return true;
            }
            return false;
        }

        private OrderView ConvertToOrderView(Order p)
        {
            OrderView cv = new()
            {
                OrderId = p.OrderId,
                CustomerId = p.CustomerId,
                OrderDate = p.OrderDate,
                TotalAmount = p.TotalAmount,
                Status = p.Status,
                IsDeleted = p.IsDeleted,
            };

            return cv;
        }

        private Order ConvertToOrder(OrderView p)
        {
            Order c = new()
            {
                OrderId = p.OrderId,
                CustomerId = p.CustomerId,
                OrderDate = p.OrderDate,
                TotalAmount = p.TotalAmount,
                Status = p.Status,
                IsDeleted = p.IsDeleted,
            };

            return c;
        }

		public List<OrderItemView> GetAllItemsForOrder(int id)
		{
			List<OrderItem> items = _context.OrderItems.Where(item=>item.OrderId == id && item.IsDeleted==false).ToList();
            List<OrderItemView> allItems = items.Select(p=>new OrderItemView
            {
				OrderItemId = p.OrderItemId,
				OrderId = p.OrderId,
				ProductId = p.ProductId,
				Quantity = p.Quantity,
				UnitPrice = p.UnitPrice,
				IsDeleted = p.IsDeleted
			}).ToList();
            return allItems;
		}
	}
}
