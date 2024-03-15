using Microsoft.EntityFrameworkCore;
using PatientsWebApi.DataAccess;
using PatientsWebApi.Interfaces;
using PatientsWebApi.Models;

namespace PatientsWebApi.Repositories
{
	public class PatientRepo : IPatient
	{
		private readonly WebApiPatientDbContext context;

		public PatientRepo(WebApiPatientDbContext _context)
		{
			context = _context;
		}



		private PatientData ConvertToPatientData(Patient p)
		{
			PatientData patientdata = new()
			{
				Id = p.PatientId,
				FirstName = p.FirstName,
				LastName = p.LastName,
				BirthDate = p.BirthDate,
				Gender = p.Gender,
				ContactNumber = p.ContactNumber,
				Address = p.Address
			};

			return patientdata;
		}

		private Patient ConvertToPatient(PatientData p)
		{
			Patient patient = new()
			{
				PatientId = p.Id,
				FirstName = p.FirstName,
				LastName = p.LastName,
				BirthDate = p.BirthDate,
				Gender = p.Gender,
				ContactNumber = p.ContactNumber,
				Address = p.Address
			};

			return patient;
		}



		public async Task<List<PatientData>> GetAllPatients()
		{
			List<Patient> patients = await context.Patients.ToListAsync();

			List<PatientData> allPatients = patients.Select(p => ConvertToPatientData(p)).ToList();

			return allPatients;
		}

		public async Task<Patient> GetPatientById(int id)
		{
			Patient? p = await context.Patients.FindAsync(id);
			if(p == null)
			{
				return new Patient();
			}
			return p;
		}

		public async Task<bool> DeletePatient(int id)
		{
			Patient? p = await context.Patients.FindAsync(id);
			if(p != null)
			{
				context.Patients.Remove(p);
				int res = context.SaveChanges();
				if (res > 0)
				{
					return true;
				}
			}
			return false;
		}

		public bool AddPatient(PatientData pd)
		{
			if (pd != null)
			{
				Patient p = ConvertToPatient(pd);
				context.Patients.Add(p);
				int res = context.SaveChanges();

				if (res > 0)
				{
					return true;
				}
				return false;
			}
			return false;
		}

		public async Task<bool> UpdatePatient(int id, PatientData pd)
		{
			if (id != pd.Id)
			{
				return false;
			}
			Patient p = ConvertToPatient(pd);
			context.Entry(p).State = EntityState.Modified;
			int res = await context.SaveChangesAsync();

			if (res > 0)
			{
				return true;
			}
			return false;
		}
	}
}
