using DataAccessLayer.Interfaces;
using DataAccessLayer.Models;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccessLayer.Repositories
{
	public class PatientRepository : IPatient
	{
		private readonly WebApiPatientDbContext context;

		public PatientRepository(WebApiPatientDbContext _context)
		{
			context = _context;
		}

		public async Task<List<Patient>> GetAllPatients()
		{
			List<Patient> patients = await context.Patients.ToListAsync();

			return patients;
		}


		public async Task<Patient> GetPatientById(int id)
		{
			Patient? p = await context.Patients.FindAsync(id);

			if (p != null)
			{
				return p;
			}
			return new Patient();
		}

		public bool AddPatient(Patient p)
		{
			if (p != null)
			{

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

		public async Task<bool> UpdatePatient(int id, Patient p)
		{
			if (id != p.PatientId)
			{
				return false;
			}
			context.Entry(p).State = EntityState.Modified;
			int res = await context.SaveChangesAsync();

			if (res > 0)
			{
				return true;
			}
			return false;
		}

		public async Task<bool> DeletePatient(int id)
		{
			Patient? p = await context.Patients.FindAsync(id);
			if (p != null)
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

	}
}
