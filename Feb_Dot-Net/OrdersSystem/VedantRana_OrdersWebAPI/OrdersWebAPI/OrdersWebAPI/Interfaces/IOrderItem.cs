using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Interfaces
{
    public interface IOrderItem
    {
        Task<List<OrderItemView>> GetAllOrderItems();
        Task<OrderItemView> GetOrderItemById(int id);

        Task<bool> DeleteOrderItem(int id);

        bool AddOrderItem(OrderItemView pd);

        Task<bool> UpdateOrderItem(int id, OrderItemView pd);
    }
}
