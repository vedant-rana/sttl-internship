using QuestionManagementSystem.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Security;

namespace QuestionManagementSystem.Controllers
{
    public class AuthenticationController : Controller
    {
        QuestionSystemEntities db = new QuestionSystemEntities();

        // GET: Authentication
        public ActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Index(LoginViewModel credentials, string returnUrl)
        {
            if(ModelState.IsValid)
            {
            var user = db.Users.Where(u=>u.email == credentials.Email && u.password==credentials.Password).FirstOrDefault();
                if(user != null)
                {
                    FormsAuthentication.SetAuthCookie(user.email, false);
                    Session["user"] = user;

                    if(returnUrl != null)
                    {
                        return Redirect(returnUrl);
                    }else if(user.role == "admin")
                    {
                        return RedirectToAction("Index", "Admin");
                    }else if(user.role == "teacher")
                    {
                        return RedirectToAction("Index", "Teacher");

                    }
                    else
                    {
                        return RedirectToAction("Index", "Student");
                    }
                }
            }
            return View();
        }

        public ActionResult Logout()
        {
            FormsAuthentication.SignOut();
            Session["name"] =null;
            Session["role"] = null;
            Session["email"] = null;
            return RedirectToAction("Index", "Authentication");
        }
    }
}