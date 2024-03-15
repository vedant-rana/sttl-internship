using System.ComponentModel.DataAnnotations;
using System.ComponentModel;

namespace ThreeLayerUI.Models
{
	public class PatientViewModel
	{

		[Key]
		public int PatientId { get; set; }

		[Required]
		[DisplayName("First Name")]
		public string FirstName { get; set; } = null!;

		[Required]
		[DisplayName("Last Name")]
		public string LastName { get; set; } = null!;

		[Required]
		[DisplayName("Birth Date")]
		public DateOnly BirthDate { get; set; }

		[Required]
		[DisplayName("Gender")]
		public string Gender { get; set; } = null!;

		[Required]
		[DisplayName("Number")]
		public string ContactNumber { get; set; } = null!;

		[Required]
		[DisplayName("Address")]
		public string? Address { get; set; }
	}
}
