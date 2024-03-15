using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeForm.ArmyClasses
{
    class ComboBoxItems
    {
        public string Text { get; set; }
        public string Value { get; set; }

        public ComboBoxItems(string text, string value)
        {
            Text = text;
            Value = value;
        }

        public override string ToString()
        {
            return Text;
        }


    }
}
