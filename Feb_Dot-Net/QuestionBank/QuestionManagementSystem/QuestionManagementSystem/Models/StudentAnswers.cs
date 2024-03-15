using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace QuestionManagementSystem.Models
{
    public class StudentAnswers
    {
        public int queId { get; set; }
        public string question1 { get; set; }
        public string opt1 { get; set; }
        public string opt2 { get; set; }
        public string opt3 { get; set; }
        public string opt4 { get; set; }
        public string answer { get; set; }
        public Nullable<int> paperId { get; set; }

        // Add the selected option property
        public string SelectedOption { get; set; }
    }
}