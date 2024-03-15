CREATE TABLE Patients (
    PatientID INT IDENTITY(1001,1) PRIMARY KEY,
    FirstName NVARCHAR(50) NOT NULL,
    LastName NVARCHAR(50) NOT NULL,
    BirthDate DATE NOT NULL,
    Gender NVARCHAR(10) NOT NULL, 
    ContactNumber NVARCHAR(15) NOT NULL,
    Address NVARCHAR(255)
);

INSERT INTO Patients (FirstName, LastName, BirthDate, Gender, ContactNumber, Address) VALUES
('John', 'Doe', '1980-01-01', 'Male', '555-0101', '123 Elm Street'),
('Jane', 'Smith', '1990-02-02', 'Female', '555-0202', '456 Maple Avenue'),
('James', 'Johnson', '1975-03-03', 'Male', '555-0303', '789 Oak Drive'),
('Emily', 'Brown', '1985-04-04', 'Female', '555-0404', '101 Pine Lane'),
('Michael', 'Davis', '1995-05-05', 'Male', '555-0505', '202 Birch Boulevard'),
('Emma', 'Miller', '1982-06-06', 'Female', '555-0606', '303 Cedar Circle'),
('William', 'Wilson', '1978-07-07', 'Male', '555-0707', '404 Dogwood Dale'),
('Olivia', 'Moore', '1992-08-08', 'Female', '555-0808', '505 Elmwood Estate'),
('Ethan', 'Taylor', '1983-09-09', 'Male', '555-0909', '606 Fir Forest'),
('Ava', 'Anderson', '1991-10-10', 'Female', '555-1010', '707 Grove Gardens');


select * from Patients