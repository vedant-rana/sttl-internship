using Microsoft.AspNetCore.Mvc;
using Newtonsoft.Json;
using System.Text;
using ThreeLayerUI.Models;

namespace ThreeLayerUI.Controllers
{
	public class PatientController : Controller
	{
		Uri baseUrl = new Uri("https://localhost:7092/api");
		private readonly HttpClient _httpClient;


		public PatientController()
		{
			_httpClient = new HttpClient();
			_httpClient.BaseAddress = baseUrl;
		}

		[HttpGet]
		public IActionResult Index()
		{
			List<PatientViewModel> allPatients = new List<PatientViewModel>();

			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/patients").Result;


			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				allPatients = JsonConvert.DeserializeObject<List<PatientViewModel>>(data);
			}
			return View(allPatients);
		}


		[HttpGet]
		public IActionResult AddPatient()
		{
			return View();
		}

		[HttpPost]
		public async Task<IActionResult> AddPatient(PatientViewModel newPatient)
		{
			var json = JsonConvert.SerializeObject(newPatient);
			var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

			HttpResponseMessage response = await _httpClient.PostAsync(_httpClient.BaseAddress + "/patients", stringContent);

			if (response.IsSuccessStatusCode)
			{
				return RedirectToAction("Index");
			}
			else
			{
				return View(newPatient);
			}
		}

		[HttpGet]
		public IActionResult PatientDetails(int id)
		{
			PatientViewModel? patient = new PatientViewModel();
			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/patients/" + id).Result;

			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				patient = JsonConvert.DeserializeObject<PatientViewModel>(data);
				if (patient != null)
				{
					return View(patient);
				}
			}
			return NotFound();
		}

		[HttpGet]
		public IActionResult UpdatePatient(int id)
		{
			PatientViewModel? patient = new PatientViewModel();
			HttpResponseMessage response = _httpClient.GetAsync(_httpClient.BaseAddress + "/patients/" + id).Result;

			if (response.IsSuccessStatusCode)
			{
				string data = response.Content.ReadAsStringAsync().Result;
				patient = JsonConvert.DeserializeObject<PatientViewModel>(data);
				if (patient != null)
				{
					return View(patient);
				}
			}
			return NotFound();
		}

		[HttpPost]
		[ActionName("UpdatePatient")]
		public async Task<IActionResult> UpdatePatientDetails(int id, PatientViewModel patient)
		{
			var json = JsonConvert.SerializeObject(patient);
			var stringContent = new StringContent(json, Encoding.UTF8, "application/json");

			HttpResponseMessage response = await _httpClient.PutAsync(_httpClient.BaseAddress + "/patients/" + id, stringContent);

			if (response.IsSuccessStatusCode)
			{
				return RedirectToAction("Index");
			}
			return View(patient);
		}


		[HttpGet]
		public async Task<IActionResult> DeletePatient(int id)
		{
			HttpResponseMessage response = await _httpClient.DeleteAsync($"{_httpClient.BaseAddress}/patients/delete/{id}");


			if (response.IsSuccessStatusCode)
			{

				return RedirectToAction("Index");
			}
			else
			{
				return RedirectToAction("Index");
			}
		}
	}
}
