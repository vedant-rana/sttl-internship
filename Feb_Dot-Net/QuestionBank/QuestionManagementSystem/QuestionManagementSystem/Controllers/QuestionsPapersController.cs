using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using QuestionManagementSystem.Models;

namespace QuestionManagementSystem.Controllers
{

    public class QuestionsPapersController : Controller
    {
        private QuestionSystemEntities db = new QuestionSystemEntities();

        // GET: QuestionsPapers

        [Authorize(Roles = "admin, teacher")]
        public ActionResult Index()
        {
            User u = (QuestionManagementSystem.Models.User)Session["user"];
            if(u.role == "teacher")
            {
                var papers = db.QuestionsPapers.Where(paper=>paper.CreatedBy ==  u.id).ToList();
                return View(papers);
            }

            return View(db.QuestionsPapers.ToList());
        }

        // GET: QuestionsPapers/Details/5

        [Authorize(Roles = "admin, teacher")]
        public ActionResult Details(int? id)
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
            return View(questionsPaper);
        }

        // GET: QuestionsPapers/Create

        [Authorize(Roles = "admin, teacher")]
        public ActionResult Create()
        {
            return View();
        }

        // POST: QuestionsPapers/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]

        [Authorize(Roles = "admin, teacher")]
        public ActionResult Create([Bind(Include = "paperId,title,description,noOfQuestions,status,creation_date")] QuestionsPaper questionsPaper)
        {

            if (ModelState.IsValid)
            {
                User teacher = (QuestionManagementSystem.Models.User)Session["user"];
                questionsPaper.CreatedBy = teacher.id;
                db.QuestionsPapers.Add(questionsPaper);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(questionsPaper);
        }

        // GET: QuestionsPapers/Edit/5

        [Authorize(Roles = "admin, teacher")]
        public ActionResult Edit(int? id)
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
            return View(questionsPaper);
        }

        // POST: QuestionsPapers/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]

        [Authorize(Roles = "admin")]
        public ActionResult Edit([Bind(Include = "paperId,title,description,noOfQuestions,status,creation_date")] QuestionsPaper questionsPaper)
        {
            if (ModelState.IsValid)
            {
                db.Entry(questionsPaper).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(questionsPaper);
        }

        // GET: QuestionsPapers/Delete/5

        [Authorize(Roles = "admin, teacher")]
        public ActionResult Delete(int? id)
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
            return View(questionsPaper);
        }

        // POST: QuestionsPapers/Delete/5

        [Authorize(Roles = "admin, teacher")]
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            QuestionsPaper questionsPaper = db.QuestionsPapers.Find(id);
            db.QuestionsPapers.Remove(questionsPaper);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
