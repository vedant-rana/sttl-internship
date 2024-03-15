using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using PatientsWebApi.DataAccess;
using PatientsWebApi.Interfaces;
using PatientsWebApi.Models;

namespace PatientsWebApi.Controllers
{
	[Route("api/patients")]
	[ApiController]
	public class PatientsController : ControllerBase
	{
		private readonly IPatient patient;

		public PatientsController(IPatient patient) {
			this.patient = patient;
		}

		[Route("all")]
		[HttpGet]
		public Task<List<PatientData>> GetAll()
		{
			return patient.GetAllPatients();
		}

		[HttpGet("{id}")]
		public Task<Patient> GetById(int id)
		{
			return patient.GetPatientById(id);
		}


		[HttpPost]
		public bool CreatePatient(PatientData pd)
		{
			return patient.AddPatient(pd);
		}


		[HttpPut("{id}")]
		public Task<bool> EditPatient(int id, PatientData pd)
		{
			return patient.UpdatePatient(id, pd);
		}

		[Route("delete/{id}")]
		[HttpDelete]
		public async Task<bool> DeletePatientById(int id)
		{
			return await patient.DeletePatient(id);
		}
	}
}
