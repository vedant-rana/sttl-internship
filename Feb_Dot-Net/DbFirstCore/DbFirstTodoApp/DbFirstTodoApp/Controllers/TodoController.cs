using DbFirstTodoApp.Models;
using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace DbFirstTodoApp.Controllers
{
    public class TodoController : Controller
    {
        DbFirstTodoAppEntities db = new DbFirstTodoAppEntities();
        // GET: Todo
        public ActionResult Index()
        {
            var data = db.Todolists.ToList();
            return View(data);
        }

        public ActionResult Add()
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Add(Todolist t)
        {
            if (ModelState.IsValid)
            {
                db.Todolists.Add(t);
                int result = db.SaveChanges();

                if (result > 0)
                {
                    return RedirectToAction("Index");
                }
            }
            return View();
        }



        public ActionResult Completed(int id)
        {
            var row = db.Todolists.Where(model => model.Id == id).FirstOrDefault();
            return View(row);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]

        public ActionResult Completed(Todolist t)
        {
            if (ModelState.IsValid)
            {
                db.Entry(t).State = EntityState.Modified;
                int result = db.SaveChanges();

                if (result > 0)
                {
                    return RedirectToAction("Index");
                }
            }
            return View();
        }

        public ActionResult Delete(int id)
        {
            if (id > 0)
            {
                var row = db.Todolists.Where(model => model.Id == id).FirstOrDefault();
                if (row != null)
                {
                    db.Entry(row).State = EntityState.Deleted;
                    int result = db.SaveChanges();
                }

            }
            else
            {
                return HttpNotFound();
            }
            return RedirectToAction("Index");
        }

        public ActionResult PendingTasks()
        {
            var data = db.Todolists.ToList();
            return View(data);
        }

        public ActionResult CompletedTask()
        {
            var data = db.Todolists.ToList();
            return View(data);
        }
    }
}