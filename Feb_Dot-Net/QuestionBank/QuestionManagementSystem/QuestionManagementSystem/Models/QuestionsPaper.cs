//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace QuestionManagementSystem.Models
{
    using System;
    using System.Collections.Generic;
    
    public partial class QuestionsPaper
    {
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2214:DoNotCallOverridableMethodsInConstructors")]
        public QuestionsPaper()
        {
            this.Approvals = new HashSet<Approval>();
            this.Approvals1 = new HashSet<Approval>();
            this.Questions = new HashSet<Question>();
            this.Questions1 = new HashSet<Question>();
            this.ScoreCards = new HashSet<ScoreCard>();
            this.creation_date = DateTime.Now;
        }
    
        public int paperId { get; set; }
        public string title { get; set; }
        public string description { get; set; }
        public int noOfQuestions { get; set; }
        public string status { get; set; }
        public Nullable<System.DateTime> creation_date { get; set; }
        public int CreatedBy { get; set; }
    
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Approval> Approvals { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Approval> Approvals1 { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Question> Questions { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<Question> Questions1 { get; set; }
        public virtual User User { get; set; }
        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2227:CollectionPropertiesShouldBeReadOnly")]
        public virtual ICollection<ScoreCard> ScoreCards { get; set; }
    }
}