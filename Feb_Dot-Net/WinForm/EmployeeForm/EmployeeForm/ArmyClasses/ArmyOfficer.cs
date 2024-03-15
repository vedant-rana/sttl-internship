using System;
using System.Collections;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EmployeeForm.ArmyClasses
{
    class ArmyOfficer
    {
        public int OfficerID { get; set; }
        public string Name { get; set; }
        public string Phone { get; set; }
        public string Email { get; set; }
        public string Dob { get; set; }
        public int Height { get; set; }
        public int Weight { get; set; }
        public string Gender { get; set; }
        public string Languages { get; set; }
        public string Nationality { get; set; }
        public string Address { get; set; }
        public string District { get; set; }
        public string State { get; set; }

        static string ArmyConnectionString = ConfigurationManager.ConnectionStrings["EmployeeForm.Properties.Settings.ArmyDBConnectionString"].ConnectionString;

        public static DataTable GetStateData()
        {
            SqlConnection conn = new SqlConnection(ArmyConnectionString);
            DataTable table = new DataTable();
            try
            {
                string getDataQuery = "Select distinct StateName from stateCity";
                SqlCommand cmd = new SqlCommand(getDataQuery, conn);
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                conn.Open();
                adapter.Fill(table);
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return table;
        }


        public static DataTable GetDistricts(string state) {
            SqlConnection conn = new SqlConnection(ArmyConnectionString);
            DataTable table = new DataTable();
            try
            {
                string getDataQuery = "Select CityName from stateCity where StateName=@state";
                SqlCommand cmd = new SqlCommand(getDataQuery, conn);
                cmd.Parameters.AddWithValue("@state", state);

                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                conn.Open();
                adapter.Fill(table);
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return table;
        }

        public static DataTable getArmyData()
        {
            SqlConnection conn = new SqlConnection(ArmyConnectionString);
            DataTable table = new DataTable();
            try
            {
                string getDataQuery = "SELECT * FROM ArmyOfficerRegistration WHERE IsDeleted=0";
                SqlCommand cmd = new SqlCommand(getDataQuery, conn);
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                conn.Open();
                adapter.Fill(table);
            }
            catch (Exception ex)
            {

            }
            finally
            {
                conn.Close();
            }
            return table;
        }

        public static bool alterArmy(ArmyOfficer officer, string op)
        {
            bool isInserted = false;

            SqlConnection conn = new SqlConnection(ArmyConnectionString);
            try
            {

                string query = "";
                if (op == "update")
                {
                    query = "UPDATE ArmyOfficerRegistration SET Name=@name, Phone=@phone, Email = @email, Dob=@dob, Height=@height, Weight=@weight, Gender=@gender, Languages=@language,Nationality= @nationality, Address=@address, District=@district, State=@state WHERE OfficerID=@ID";
                }
                else
                {
                    query = "INSERT INTO ArmyOfficerRegistration (Name, Phone, Email, Dob, Height, Weight, Gender, Languages, Nationality, Address, District, State)VALUES(@Name, @phone, @email, @dob, @height, @weight, @gender, @language, @nationality, @address, @district, @state)";
                }


                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@Name", officer.Name);
                cmd.Parameters.AddWithValue("@phone", officer.Phone);
                cmd.Parameters.AddWithValue("@email", officer.Email);
                cmd.Parameters.AddWithValue("@dob", officer.Dob);
                cmd.Parameters.AddWithValue("@height", officer.Height);
                cmd.Parameters.AddWithValue("@weight", officer.Weight);
                cmd.Parameters.AddWithValue("@gender", officer.Gender);
                cmd.Parameters.AddWithValue("@language", officer.Languages);
                cmd.Parameters.AddWithValue("@nationality", officer.Nationality);
                cmd.Parameters.AddWithValue("@address", officer.Address);
                cmd.Parameters.AddWithValue("@district", officer.District);
                cmd.Parameters.AddWithValue("@state", officer.State);


                if (op == "update")
                {
                    cmd.Parameters.AddWithValue("@ID", officer.OfficerID);
                }

                conn.Open();
                int rows = cmd.ExecuteNonQuery();
                if (rows > 0)
                {
                    isInserted = true;
                }
                else
                {
                    isInserted = false;
                }
            }
            catch (Exception ex)
            {


            }
            finally
            {
                conn.Close();
            }
            return isInserted;
        }

        public static bool deleteArmyData(ArmyOfficer officer)
        {

            bool isDeleted = false;

            SqlConnection conn = new SqlConnection(ArmyConnectionString);
            try
            {
                string deleteQuery = "UPDATE ArmyOfficerRegistration SET IsDeleted = 1 WHERE OfficerID = @ID";
                SqlCommand cmd = new SqlCommand(deleteQuery, conn);

                cmd.Parameters.AddWithValue("@ID", officer.OfficerID);

                conn.Open();
                int rows = cmd.ExecuteNonQuery();
                if (rows > 0)
                {
                    isDeleted = true;
                }
                else
                {
                    isDeleted = false;
                }
            }
            catch (Exception ex)
            {


            }
            finally
            {
                conn.Close();
            }
            return isDeleted;
        }

    }
}
