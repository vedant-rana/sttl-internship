using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Controllers
{
    [Route("api/orders")]
    [ApiController]
    public class OrderController : ControllerBase
    {
        private readonly IOrder order;

        public OrderController(IOrder order)
        {
            this.order = order;
        }


        [HttpGet]
        [Route("all")]
        public Task<List<OrderView>> GetAllOrders()
        {
            return order.GetAllOrders();
        }

        [HttpGet]
        [Route("orderItems/{id}")]
        public List<OrderItemView> GetItemsForOrder(int id)
        {
            return order.GetAllItemsForOrder(id);
        }

        [HttpGet("{id}")]
        public Task<OrderView> GetOrderById(int id)
        {
            return order.GetOrderById(id);
        }


        [HttpPost]
        public bool AddOrder(OrderView cv)
        {
            return order.AddOrder(cv);
        }

        [HttpPut("{id}")]
        public Task<bool> UpdateOrder(int id, OrderView c)
        {
            return order.UpdateOrder(id, c);
        }

        [HttpDelete("{id}")]
        public Task<bool> DeleteOrderById(int id)
        {
            return order.DeleteOrder(id);
        }
    }
}
