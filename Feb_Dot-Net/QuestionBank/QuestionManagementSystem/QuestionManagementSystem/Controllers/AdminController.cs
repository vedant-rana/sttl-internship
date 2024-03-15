using QuestionManagementSystem.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;

namespace QuestionManagementSystem.Controllers
{
    [Authorize(Roles = "admin")]

    public class AdminController : Controller
    {
        QuestionSystemEntities db = new QuestionSystemEntities();

        public List<User> GetAllUsers()
        {
            return db.Users.ToList();
		}
        // GET: Admin
        public ActionResult Index()
        {
			ViewBag.UserType = null;
			var data = GetAllUsers();
            return View(data);
        }
        public ActionResult TeachersList()
        {
            var data = GetAllUsers();
            ViewBag.UserType = "teacher";

			return View(data);
        }
        public ActionResult StudentsList()
        {
            var data = GetAllUsers();
			ViewBag.UserType = "student";
			return View(data);
        }
        public ActionResult CreateUser()
        {
            return View();
        }
        [HttpPost]
        public ActionResult CreateUser(User usr)
        {
            if(ModelState.IsValid)
            {
                db.Users.Add(usr);
                int result = db.SaveChanges();
                if(result>0)
                {
                    return RedirectToAction("Index","Admin");
                }
            }
            return View();
        }
       
        public ActionResult EditUser(int id)
        {
            User usr = db.Users.Where(x => x.id == id).SingleOrDefault();
            return View(usr);
        }
        [HttpPost]
        public ActionResult EditUser(int id,User usr)
        {
            User ur = db.Users.Where(x => x.id == id).SingleOrDefault();
            ur.name = usr.name;
            ur.email = usr.email;
            ur.password = usr.password; 
            ur.role = usr.role;
            db.SaveChanges();
            return RedirectToAction("Index","Admin");
        }
        public ActionResult DeleteUser(int id)
        {
            User sr = db.Users.Where(x => x.id == id).SingleOrDefault();
            return View(sr);
        }
        [HttpPost]
        public ActionResult DeleteUser(int id,User usr)
        {
            db.Users.Remove(db.Users.Where(x => x.id == id).SingleOrDefault());
            db.SaveChanges();
            return RedirectToAction("Index","Admin");
        }
        public ActionResult ReviewPending()
        {
            var data = db.QuestionsPapers.Where(x => x.status == "pending").ToList();
            return View(data);
        }
        public ActionResult ReviewPaper(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            QuestionsPaper questionsPaper = db.QuestionsPapers.Find(id);
            if (questionsPaper == null)
            {
                return HttpNotFound();
            }
            ViewBag.pprId = id;
            return View(questionsPaper);

        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult ReviewPaper([Bind(Include = "paperId,title,description,noOfQuestions,status,CreatedBy")] QuestionsPaper questionsPaper)
        {
            if (ModelState.IsValid)
            {
                db.Entry(questionsPaper).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(questionsPaper);
        }

        public ActionResult ReviewQuestions(int? id)
        {
            var data = db.Questions.Where(x => x.paperId == id).ToList();
            return View(data);
        }
        
    }
}