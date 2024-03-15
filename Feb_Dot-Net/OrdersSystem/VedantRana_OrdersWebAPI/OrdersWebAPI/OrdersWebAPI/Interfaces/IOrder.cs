using OrdersWebAPI.ViewModels;

namespace OrdersWebAPI.Interfaces
{
    public interface IOrder
    {

        Task<List<OrderView>> GetAllOrders();
        Task<OrderView> GetOrderById(int id);

        Task<bool> DeleteOrder(int id);

        bool AddOrder(OrderView pd);

        Task<bool> UpdateOrder(int id, OrderView pd);

        List<OrderItemView> GetAllItemsForOrder(int id);
    }
}
