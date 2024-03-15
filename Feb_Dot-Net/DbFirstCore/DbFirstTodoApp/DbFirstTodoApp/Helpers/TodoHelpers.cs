using DbFirstTodoApp.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace DbFirstTodoApp.Helpers
{
    public static class TodoHelpers
    {
        public static MvcHtmlString TableHelper(this HtmlHelper html, Todolist item)
        {
            var urlHelper = new UrlHelper(html.ViewContext.RequestContext);


            var tr = new TagBuilder("tr");
            tr.AddCssClass("item");

            if (item.IsCompleted)
            {
                tr.AddCssClass("completed");
            }


            var descTd = new TagBuilder("td");
            descTd.AddCssClass("task-description");
            descTd.SetInnerText(item.TaskDesc);

            var date = new TagBuilder("td");
            date.AddCssClass("task-description");
            date.SetInnerText(Convert.ToString(item.CreatedAt).Substring(0, 10));

            var completeTd = new TagBuilder("td");
            completeTd.AddCssClass("status");
            if (item.IsCompleted)
            {
                completeTd.InnerHtml = "Completed";
            }
            else
            {
                completeTd.InnerHtml = "Pending";
            }


            var updateTd = new TagBuilder("td");
            updateTd.AddCssClass("edit-action");
            var updateLink = new TagBuilder("a");
            updateLink.SetInnerText("Edit Task");
            updateLink.AddCssClass("btn btn-success");
            updateLink.Attributes.Add("href", urlHelper.Action("Completed", "ToDo", new { id = item.Id }));
            updateTd.InnerHtml = updateLink.ToString();


            var deleteTd = new TagBuilder("td");
            deleteTd.AddCssClass("delete-action");
            var deleteLink = new TagBuilder("a");
            deleteLink.SetInnerText("Delete");
            deleteLink.AddCssClass("btn btn-danger");
            deleteLink.Attributes.Add("onclick", "return confirm('Are you sure you want to delete?')");
            deleteLink.Attributes.Add("href", urlHelper.Action("Delete", "ToDo", new { id = item.Id }));
            deleteTd.InnerHtml = deleteLink.ToString();


            tr.InnerHtml = descTd.ToString() + completeTd.ToString() + updateTd.ToString() + deleteTd.ToString();

            return MvcHtmlString.Create(tr.ToString());
        }

        public static string CardHelper(Todolist item, string editLink, string deleteLink)
        {
            string date = Convert.ToString(item.CreatedAt).Substring(0, 10);

            string cards = $@"
               
                            <div class='card col-md-4 card-div m-2 p-0'  style='width: 30%;'>
                                <div class='card-header bg-primary text-white'>
                                    Task ID: {item.Id} ({date})
                                    <a href='{deleteLink}' class='close delete-button' style='font-size: 20px;'>Delete</a>
                                </div>
                                <div class='card-body'>
                                    <p class='card-text'>Task Description</p>
                                    <h3 class='card-title'>{item.TaskDesc}</h3>
                                    <p class='card-text'>Status: {(item.IsCompleted ? "<span class='text-success'>Completed</span>" : "<span class='text-danger'>Incomplete</span>")}</p>
                                    <a href='{editLink}' class='btn btn-outline-primary'>Edit</a>
                                    <a href='{deleteLink}' onclick='return confirmDelete();' class='btn btn-outline-danger'>Delete</a>
                                </div>
                            </div>


                    <script>
                        function confirmDelete() {{
                            return confirm('Are you sure you want to delete this task?');
                        }}
                    </script>";

            return cards;

        }
    }
}