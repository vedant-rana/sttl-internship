CREATE DATABASE TempEmployee;

USE TempEmployee;


CREATE TABLE employees (
  employee_id INT PRIMARY KEY,
  first_name VARCHAR(50),
  last_name VARCHAR(50),
  department VARCHAR(50),
  salary DECIMAL(10, 2)
);


INSERT INTO employees (employee_id, first_name, last_name, department, salary)
VALUES
  (1, 'John', 'Doe', 'HR', 50000.00),
  (2, 'Jane', 'Smith', 'IT', 60000.00),
  (3, 'Bob', 'Johnson', 'Sales', 55000.00),
  (4, 'Alice', 'Williams', 'Finance', 65000.00);


CREATE TABLE contractors (
  contractor_id INT PRIMARY KEY,
  first_name VARCHAR(50),
  last_name VARCHAR(50),
  department VARCHAR(50),
  hourly_rate DECIMAL(8, 2)
);

INSERT INTO contractors (contractor_id, first_name, last_name, department, hourly_rate)
VALUES
  (1, 'Mike', 'Davis', 'IT', 35.00),
  (2, 'Sara', 'Miller', 'HR', 40.00),
  (3, 'Chris', 'White', 'Marketing', 38.00),
  (4, 'Emily', 'Clark', 'IT', 37.50);


SELECT * FROM employees;
SELECT * FROM contractors;

--===========================================================================================
/*  Union Query For Employee DB tables */

SELECT employee_id, first_name, last_name, department, salary
FROM employees
UNION
SELECT contractor_id, first_name, last_name, department, NULL AS salary
FROM contractors;


/*  UnionAll Query For Employee DB tables */
SELECT employee_id, first_name, last_name, department, salary
FROM employees
UNION ALL
SELECT contractor_id, first_name, last_name, department, NULL AS salary
FROM contractors;


