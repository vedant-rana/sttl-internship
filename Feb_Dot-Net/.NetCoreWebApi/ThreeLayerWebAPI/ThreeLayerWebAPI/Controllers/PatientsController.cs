using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using BusinessLogicLayer.Interfaces;
using DataAccessLayer.Models;
using DataAccessLayer.Interfaces;


namespace ThreeLayerWebAPI.Controllers
{
	[Route("api/patients")]
	[ApiController]
	public class PatientsController : ControllerBase
	{
		private readonly IPatientServices service;

		public PatientsController(IPatientServices service)
        {
			this.service = service;
		}

		[HttpGet]
		public async Task<List<Patient>> GetAllPatients()
		{
			return await service.GetAllPatients();
		}


		[HttpGet("{id}")]
		public Task<Patient> GetById(int id)
		{
			return service.GetPatientById(id);
		}



		[HttpPost]
		public bool CreatePatient(Patient pd)
		{
			return service.AddPatient(pd);
		}


		[HttpPut("{id}")]
		public Task<bool> EditPatient(int id, Patient pd)
		{
			return service.UpdatePatient(id, pd);
		}


		[Route("delete/{id}")]
		[HttpDelete]
		public async Task<bool> DeletePatientById(int id)
		{
			return await service.DeletePatient(id);
		}
	}
}
