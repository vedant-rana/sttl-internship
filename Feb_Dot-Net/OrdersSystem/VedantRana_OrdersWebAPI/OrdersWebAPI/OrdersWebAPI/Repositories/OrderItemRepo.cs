using Microsoft.EntityFrameworkCore;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Repositories
{
    public class OrderItemRepo : IOrderItem
    {
        private readonly OrdersDbContext _context;

        public OrderItemRepo(OrdersDbContext context)
        {
            _context = context;
        }



        public async Task<List<OrderItemView>> GetAllOrderItems()
        {
            List<OrderItem> allOItems = await _context.OrderItems.Where(oi => oi.IsDeleted == false).ToListAsync();
            List<OrderItemView> ans = allOItems.Select(oi => ConvertToOrderItemView(oi)).ToList();
            return ans;
        }

        public async Task<OrderItemView> GetOrderItemById(int id)
        {
            OrderItemView cv = new OrderItemView();
            OrderItem? p = await _context.OrderItems
                            .Where(c => c.OrderItemId == id && c.IsDeleted == false)
                            .FirstOrDefaultAsync();


            if (p != null)
            {
                cv = ConvertToOrderItemView(p);
            }
            return cv;
        }

        public bool AddOrderItem(OrderItemView cv)
        {
            if (cv != null)
            {
                OrderItem c = ConvertToOrderItem(cv);
                _context.OrderItems.Add(c);
                int res = _context.SaveChanges();

                if (res > 0)
                {
                    return true;
                }
                return false;
            }
            return false;
        }

        public async Task<bool> DeleteOrderItem(int id)
        {
            OrderItem? c = await _context.OrderItems
                            .Where(oi => oi.OrderItemId == id && oi.IsDeleted == false)
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

        public async Task<bool> UpdateOrderItem(int id, OrderItemView cv)
        {
            if (id != cv.OrderItemId)
            {
                return false;
            }

            OrderItem c = ConvertToOrderItem(cv);
            _context.Entry(c).State = EntityState.Modified;

            int res = await _context.SaveChangesAsync();

            if (res > 0)
            {
                return true;
            }
            return false;
        }



        private OrderItemView ConvertToOrderItemView(OrderItem p)
        {
            OrderItemView cv = new()
            {
                OrderItemId = p.OrderItemId,
                OrderId = p.OrderId,
                ProductId = p.ProductId,
                Quantity = p.Quantity,
                UnitPrice = p.UnitPrice,
                IsDeleted = p.IsDeleted
            };

            return cv;
        }

        private OrderItem ConvertToOrderItem(OrderItemView p)
        {
            OrderItem c = new()
            {
                OrderItemId = p.OrderItemId,
                OrderId = p.OrderId,
                ProductId = p.ProductId,
                Quantity = p.Quantity,
                UnitPrice = p.UnitPrice,
                IsDeleted = p.IsDeleted
            };

            return c;
        }

    }
}
