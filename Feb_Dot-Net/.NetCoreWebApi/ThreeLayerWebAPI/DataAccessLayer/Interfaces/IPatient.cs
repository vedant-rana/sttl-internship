﻿using DataAccessLayer.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccessLayer.Interfaces
{
	public interface IPatient
	{
		Task<List<Patient>> GetAllPatients();
		Task<Patient> GetPatientById(int id);

		Task<bool> DeletePatient(int id);

		bool AddPatient(Patient pd);

		Task<bool> UpdatePatient(int id, Patient pd);
	}
}