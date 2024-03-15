using PatientsWebApi.DataAccess;
using PatientsWebApi.Models;

namespace PatientsWebApi.Interfaces
{
	public interface IPatient
	{
		Task<List<PatientData>> GetAllPatients();
		Task<Patient> GetPatientById(int id);

		Task<bool> DeletePatient(int id);

		bool AddPatient(PatientData pd);
		Task<bool> UpdatePatient(int id, PatientData pd);
	}
}
