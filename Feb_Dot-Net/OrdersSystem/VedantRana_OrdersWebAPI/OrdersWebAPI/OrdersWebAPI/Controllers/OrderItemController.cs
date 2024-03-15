using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Controllers
{
    [Route("api/orderItem")]
    [ApiController]
    public class OrderItemController : ControllerBase
    {
        private readonly IOrderItem orderItem;

        public OrderItemController(IOrderItem orderItem)
        {
            this.orderItem = orderItem;
        }


        [HttpGet]
        [Route("all")]
        public Task<List<OrderItemView>> GetAllOrderItems()
        {
            return orderItem.GetAllOrderItems();
        }

        [HttpGet("{id}")]
        public Task<OrderItemView> GetOrderItemById(int id)
        {
            return orderItem.GetOrderItemById(id);
        }


        [HttpPost]
        public bool AddOrderItem(OrderItemView cv)
        {
            return orderItem.AddOrderItem(cv);
        }

        [HttpPut("{id}")]
        public Task<bool> UpdateOrderItem(int id, OrderItemView c)
        {
            return orderItem.UpdateOrderItem(id, c);
        }

        [HttpDelete("{id}")]
        public Task<bool> DeleteOrderItemById(int id)
        {
            return orderItem.DeleteOrderItem(id);
        }
    }
}
