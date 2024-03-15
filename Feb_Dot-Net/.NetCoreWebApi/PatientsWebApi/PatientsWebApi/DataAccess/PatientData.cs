using System.ComponentModel.DataAnnotations;

namespace PatientsWebApi.DataAccess
{
	public class PatientData
	{
		[Key]
		public int Id { get; set; }

		[Required]
		public string FirstName { get; set; } = null!;

		[Required]
		public string LastName { get; set; } = null!;

		[Required]
		public DateOnly BirthDate { get; set; }

		[Required]
		public string Gender { get; set; } = null!;

		[Required]
		public string ContactNumber { get; set; } = null!;

		[Required]
		public string? Address { get; set; }
	}
}
