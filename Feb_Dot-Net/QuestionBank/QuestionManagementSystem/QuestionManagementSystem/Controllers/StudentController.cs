using QuestionManagementSystem.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace QuestionManagementSystem.Controllers
{
    public class StudentController : Controller
    {
        QuestionSystemEntities db = new QuestionSystemEntities();
        // GET: Student
        public ActionResult Index()
        {
            var data = db.QuestionsPapers.Where(x => x.status == "approved").ToList();
            return View(data);
        }


        public ActionResult AttemptPaper(int id)
        {
            var que = db.QuestionsPapers.Where(x => x.paperId == id).SingleOrDefault();
            ViewBag.title = que.title;
            ViewBag.description = que.description;
            ViewBag.totalQuestions = que.noOfQuestions;
            Session["pId"] = id;
            var data = db.Questions.Where(x => x.paperId == id).ToList();
            return View(data);
        }

        public ActionResult Score(string score)
        {
            int pId = Convert.ToInt32(Session["pId"]);
            User u = (QuestionManagementSystem.Models.User)Session["user"];
            ViewBag.Score = Convert.ToInt32(score);
            var newAnswer = new ScoreCard
            {
                paperId = pId,
                userId = Convert.ToInt32(u.id),
                score = Convert.ToInt32(score)
            };
            db.ScoreCards.Add(newAnswer);
            db.SaveChanges();
            return View();
        }

    }
}