using BusinessLogicLayer.Interfaces;
using DataAccessLayer.Models;
using DataAccessLayer.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BusinessLogicLayer.Services
{
	public class PatientServices : IPatientServices
	{
		private readonly IPatient patient;

		public PatientServices(IPatient patient)
        {
			this.patient = patient;
		}

		public Task<List<Patient>> GetAllPatients()
		{
			return patient.GetAllPatients();
		}

		public Task<Patient> GetPatientById(int id)
		{
			return patient.GetPatientById(id);
		}

		public bool AddPatient(Patient pd)
		{
			return patient.AddPatient(pd);
		}

		public Task<bool> UpdatePatient(int id, Patient pd)
		{
			return patient.UpdatePatient(id, pd);	
		}

		public Task<bool> DeletePatient(int id)
		{
			return patient.DeletePatient(id);
		}
	}
}
