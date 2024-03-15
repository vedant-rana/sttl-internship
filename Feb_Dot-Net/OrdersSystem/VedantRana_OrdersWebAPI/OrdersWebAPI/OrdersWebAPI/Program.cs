using Microsoft.EntityFrameworkCore;
using OrdersWebAPI.Interfaces;
using OrdersWebAPI.Models;
using OrdersWebAPI.Repositories;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();


var provider = builder.Services.BuildServiceProvider();
var config = provider.GetRequiredService<IConfiguration>();

builder.Services.AddDbContext<OrdersDbContext>(item => item.UseSqlServer(config.GetConnectionString("ordersString")));

builder.Services.AddScoped<ICustomer, CustomerRepo>();
builder.Services.AddScoped<IProduct, ProductRepo>();
builder.Services.AddScoped<IOrder, OrderRepo>();
builder.Services.AddScoped<IOrderItem, OrderItemRepo>();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
	app.UseSwagger();
	app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
