using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace OrdersWebAPI.Models;

public partial class Customer
{
    public int CustomerId { get; set; }

    public string? Name { get; set; }

	[EmailAddress(ErrorMessage = "Invalid Email Address")]
	public string? Email { get; set; }

    public string? Address { get; set; }

    public bool? IsDeleted { get; set; }

    public virtual ICollection<Order> Orders { get; set; } = new List<Order>();
}
