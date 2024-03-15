using System;
using System.Collections.Generic;

namespace DataAccessLayer.Models;

public partial class Patient
{
    public int PatientId { get; set; }

    public string FirstName { get; set; } = null!;

    public string LastName { get; set; } = null!;

    public DateOnly BirthDate { get; set; }

    public string Gender { get; set; } = null!;

    public string ContactNumber { get; set; } = null!;

    public string? Address { get; set; }
}
