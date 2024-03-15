using EmployeeForm.ArmyClasses;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EmployeeForm
{
    public partial class Form1 : Form
    {
        int selectedGridRow = -1;

        
        
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BindNationality();
            BindStates();
            BindData();
        }

        private void BindData()
        {
            dataGrid.DataSource = ArmyOfficer.getArmyData();
        }
        
        
        private void BindStates()
        {
            DataTable states = ArmyOfficer.GetStateData();
            stateList.DataSource = states;
            stateList.DisplayMember = "StateName";
            stateList.ValueMember = "StateName";
            DataTable districts = ArmyOfficer.GetDistricts("--Select--");
            districtList.DataSource = districts;
            districtList.DisplayMember = "CityName";
            districtList.ValueMember = "CityName";
        }


        private void BindNationality()
        {
            List<ComboBoxItems> comboItem = new List<ComboBoxItems>();
            comboItem.Add(new ComboBoxItems("--Select--", "default"));
            comboItem.Add(new ComboBoxItems("Indian", "Indian"));
            comboItem.Add(new ComboBoxItems("Foreigner", "Foreigner"));

            nationalityTxt.DataSource = comboItem;
            nationalityTxt.DisplayMember = "Text";
            nationalityTxt.ValueMember = "Value";
        }


        private ArmyOfficer setDataToObject()
        {
            ArmyOfficer officer = new ArmyOfficer();


            officer.Name = nameTxt.Text;
            officer.Phone = phoneTxt.Text;
            officer.Email = emailTxt.Text;
            officer.Dob = dobPicker.Text;
            officer.Height = Convert.ToInt32(heightTxt.Value);
            officer.Weight = Convert.ToInt32(weightTxt.Value);


            if (maleRadio.Checked)
            {
                officer.Gender = "male";
            }
            else if (femaleRadio.Checked)
            {
                officer.Gender = "female";
            }
            else
            {
                officer.Gender = "others";
            }

            string languages = "";
            foreach (object lan in languageTxt.CheckedItems)
            {
                languages += lan.ToString();
                languages += " ";
            }
            officer.Languages = languages;

            officer.Nationality = nationalityTxt.Text;
            officer.Address = adressTxt.Text;
            officer.District = districtList.Text;
            officer.State = stateList.Text;

            return officer;
        }

        private void clearBtn_Click(object sender, EventArgs e)
        {
            clearFields();
        }

        private void submitBtn_Click(object sender, EventArgs e)
        {
            if (ValidateFields())
            {
                ArmyOfficer officer = setDataToObject();

                string op = "insert";
                bool isInserted = ArmyOfficer.alterArmy(officer, op);

                BindData();
                if (isInserted)
                {
                    MessageBox.Show("Data Added Successfully");
                }
                else
                {
                    MessageBox.Show("Some Error Occured");
                }
            }

        }


        private void updateBtn_Click(object sender, EventArgs e)
        {

            if (ValidateFields())
            {
                ArmyOfficer officer = setDataToObject();
                officer.OfficerID = selectedGridRow;
                string op = "update";
                bool isInserted = ArmyOfficer.alterArmy(officer, op);
                BindData();


                if (isInserted)
                {
                    MessageBox.Show("Data Updated Successfully");
                }
                else
                {
                    MessageBox.Show("Some Error Occured");
                }
                selectedGridRow = -1;
                clearFields();
            }
            

        }

        private void deleteBtn_Click(object sender, EventArgs e)
        {
            ArmyOfficer officer = new ArmyOfficer();
            if(selectedGridRow == -1)
            {
                MessageBox.Show("Please Select Row to Delete");
                return;
            }
            officer.OfficerID = selectedGridRow;
            bool isDeleted = ArmyOfficer.deleteArmyData(officer);
            if (isDeleted)
            {
                MessageBox.Show("Row Deleted Successfully");
                BindData();
            }
            else
            {
                MessageBox.Show("Row Deletion failed");
            }
            selectedGridRow = -1;
            clearFields();
        }

        private void clearFields()
        {
            nameTxt.Text = "";
            phoneTxt.Text = "";
            emailTxt.Text = "";
            dobPicker.Value = DateTime.Now;

            heightTxt.Value = 0;
            weightTxt.Value = 0;

            maleRadio.Checked = false;
            femaleRadio.Checked = false;
            othersRadio.Checked = false;

            for (int i = 0; i < languageTxt.Items.Count; i++)
            {
                languageTxt.SetItemChecked(i, false);
            }

            nationalityTxt.SelectedIndex = 0;
            adressTxt.Text = "";
            stateList.SelectedIndex = 0;
            districtList.SelectedIndex = 0;
        }

        private void dataGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            int rowIndex = e.RowIndex;
            selectedGridRow = Convert.ToInt32(dataGrid.Rows[rowIndex].Cells[0].Value);


            if (rowIndex == -1)
            {
                return;
            }

            nameTxt.Text = dataGrid.Rows[rowIndex].Cells[1].Value.ToString();
            phoneTxt.Text = dataGrid.Rows[rowIndex].Cells[2].Value.ToString();
            emailTxt.Text = dataGrid.Rows[rowIndex].Cells[3].Value.ToString();
            dobPicker.Text = dataGrid.Rows[rowIndex].Cells[4].Value.ToString();
            heightTxt.Text = dataGrid.Rows[rowIndex].Cells[5].Value.ToString();
            weightTxt.Text = dataGrid.Rows[rowIndex].Cells[6].Value.ToString();


            string gender  = dataGrid.Rows[rowIndex].Cells[7].Value.ToString();
            if (gender == "male")
            {
                maleRadio.Checked = true;
            }else if(gender == "female")
            {
                femaleRadio.Checked = true;
            }
            else
            {
                othersRadio.Checked = true;
            }
            

            string languages = dataGrid.Rows[rowIndex].Cells[8].Value.ToString();
            string[] langArr = languages.Split(' ');

            for (int i = 0; i < languageTxt.Items.Count; i++)
            {
                if (langArr.Contains(languageTxt.Items[i].ToString()))
                {
                    languageTxt.SetItemChecked(i, true);
                }
            }

            nationalityTxt.Text = dataGrid.Rows[rowIndex].Cells[9].Value.ToString();
            adressTxt.Text = dataGrid.Rows[rowIndex].Cells[10].Value.ToString();
            stateList.Text = dataGrid.Rows[rowIndex].Cells[12].Value.ToString();
            districtList.Text = dataGrid.Rows[rowIndex].Cells[12].Value.ToString();
            
        }

        private void stateList_SelectedIndexChanged(object sender, EventArgs e)
        {
            string state =Convert.ToString( stateList.SelectedValue);

            DataTable table = ArmyOfficer.GetDistricts(state);
            districtList.DataSource = table;
            districtList.DisplayMember = "CityName";
            districtList.ValueMember = "CityName";
        }

        private bool ValidateFields()
        {
            bool isValid = true;

            if (string.IsNullOrWhiteSpace(nameTxt.Text))
            {
                isValid = false;
                MessageBox.Show("Please enter a name.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (string.IsNullOrWhiteSpace(phoneTxt.Text))
            {
                isValid = false;
                MessageBox.Show("Please enter a phone number.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (string.IsNullOrWhiteSpace(emailTxt.Text))
            {
                isValid = false;
                MessageBox.Show("Please enter an email.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (!IsValidEmail(emailTxt.Text))
            {
                isValid = false;
                MessageBox.Show("Please enter a valid email address.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (dobPicker.Value < DateTime.Now)
            {
                isValid = false;
                MessageBox.Show("Please enter a valid date of birth.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if(heightTxt.Value <= 0 || heightTxt.Value>100) { 
                isValid = false;
                MessageBox.Show("Enter Valid Height", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if(weightTxt.Value <= 0 || weightTxt.Value>100) { 
                isValid = false;
                MessageBox.Show("Enter Valid Weight", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if(!maleRadio.Checked || !femaleRadio.Checked || !othersRadio.Checked)
            {
                isValid = false;
                MessageBox.Show("Select Gender", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (nationalityTxt.Text == "--Select--")
            {
                isValid = false;
                MessageBox.Show("Select Valid Nationality", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (string.IsNullOrWhiteSpace(adressTxt.Text))
            {
                isValid = false;
                MessageBox.Show("Please enter Address", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (stateList.Text == "--Select--")
            {
                isValid = false;
                MessageBox.Show("Select Valid State", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (districtList.Text == "--Select--")
            {
                isValid = false;
                MessageBox.Show("Select Valid District", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            return isValid;
        }

        //private bool IsValidEmail(string email)
        //{
        //    return email.Contains("@");
        //}

        private bool IsValidEmail(string email)
        {

            string pattern = @"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$";


            return Regex.IsMatch(email, pattern);
        }
    }

}
