using Microsoft.EntityFrameworkCore;
using PatientsWebApi.Interfaces;
using PatientsWebApi.Models;
using PatientsWebApi.Repositories;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.

builder.Services.AddControllers();
// Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

var provider = builder.Services.BuildServiceProvider();
var config = provider.GetRequiredService<IConfiguration>();

builder.Services.AddDbContext<WebApiPatientDbContext>(item => item.UseSqlServer(config.GetConnectionString("conString")));

builder.Services.AddScoped<IPatient, PatientRepo>();

var app = builder.Build();

//middleware for Logging activities
//app.UseHttpLogging();


// Configure the HTTP request pipeline.
//if (app.Environment.IsDevelopment())
//{
	app.UseSwagger();
	app.UseSwaggerUI();
//}

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
