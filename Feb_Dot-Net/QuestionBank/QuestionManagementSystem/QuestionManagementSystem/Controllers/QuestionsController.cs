using QuestionManagementSystem.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Web;
using System.Web.Mvc;

namespace QuestionManagementSystem.Controllers
{

    [Authorize(Roles = "admin, teacher")]
    public class QuestionsController : Controller
    {
        QuestionSystemEntities db = new QuestionSystemEntities();
        // GET: Questions
        public ActionResult Index()
        {
            var data = db.Questions.ToList();
            return View(data);
        }


        public ActionResult CreateQuestions(int id1)
        {
            ViewBag.id1 = id1;
            return View();
        }


        [HttpPost]
        public ActionResult CreateQuestions(Question que)
        {
            db.Questions.Add(que);
            db.SaveChanges();
            return RedirectToAction("Index", "QuestionsPapers");
        }

        public ActionResult EditQuestionPaper(int id)
        {
            // Specify the paperId you want to retrieve questions for
            int paperId = id; // Replace with the actual paperId
            ViewBag.paperId = id;
            // Retrieve questions from the database based on paperId
            var questionsForPaper = db.Questions.Where(q => q.paperId == paperId).ToList();
            return View(questionsForPaper);
        }

        public ActionResult EditQuestions(int id)
        {
            Question que = db.Questions.Where(x => x.queId == id).SingleOrDefault();
            return View(que);
        }


        [HttpPost]
        public ActionResult EditQuestions(int id,Question que)
        {
            Question q = db.Questions.Where(x => x.queId == id).SingleOrDefault();
            q.question1 = que.question1;
            q.opt1 = que.opt1;
            q.opt2 = que.opt2;
            q.opt3 = que.opt3;
            q.opt4 = que.opt4;
            q.answer = que.answer;
            db.SaveChanges();
            return RedirectToAction("EditQuestionPaper", "Questions", new { id = q.paperId });
            
        }
        
        public ActionResult DeleteQuestion(int id)
        {
            Question q = db.Questions.Where(x => x.queId == id).SingleOrDefault();
            ViewBag.paperId = q.paperId;
            return View(q);
        }
        [HttpPost]
        public ActionResult DeleteQuestion(int id, Question que)
        {
            Question q = db.Questions.Where(x => x.queId == id).SingleOrDefault();
            db.Questions.Remove(db.Questions.Where(x => x.queId == id).SingleOrDefault());
            db.SaveChanges();
            return RedirectToAction("Index", "QuestionsPapers");
        }
    }
}





//@model QuestionManagementSystem.Models.Question
//@{
//    ViewBag.Title = "CreateQuestions";
//    Layout = "~/Views/Shared/_Layout.cshtml";
//}

//< h2 > Create Questions </ h2 >

//@{
//    int noOfQuestions = Convert.ToInt32(ViewBag.num);
//}


//for (int i = 0; i < noOfQuestions; i++)
//{

//}




