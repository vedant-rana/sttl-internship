/* 4 joins in All DBS */

--DB1: Inventory DB
--1. inner join
SELECT
    P.ProductID,
    P.ProductName,
    P.Price,
    P.Stock,
    T.TransactionID,
    T.TransactionDate,
    T.QuantityChange
FROM
    Product AS P
INNER JOIN
    Transactions AS T ON P.ProductID = T.ProductID;


--2. left join
SELECT 
	C.CategoryID,
	C.Category_Name,
	P.ProductName,
	P.Price
FROM 
	Category AS C
LEFT JOIN
	Product AS P ON C.CategoryID = P.CatogoryID;

--3. right join
SELECT 
	C.CategoryID,
	C.Category_Name,
	P.ProductName,
	P.Price
FROM 
	Category AS C
RIGHT JOIN
	Product AS P ON C.CategoryID = P.CatogoryID;

--4. full join
SELECT
    P.ProductID,
    P.ProductName,
    P.Price,
    P.Stock,
    T.TransactionID,
    T.TransactionDate,
    T.QuantityChange
FROM
    Product AS P
FULL OUTER JOIN
    Transactions AS T ON P.ProductID = T.ProductID;




--DB2: Library DB
--1. inner join
SELECT
    C.CategoryID,
    C.IsActive,
    B.BookID,
    B.Title,
    B.ISBN,
    B.AvailableCopies
FROM
    Category AS C
INNER JOIN
    Book AS B ON C.CategoryID = B.CategoryID;


--2. left join
SELECT
    M.MemberID,
    M.FirstName,
    M.TotalBorrowedBook,
    T.TransactionID,
    T.BookID,
    T.CheckoutDate,
    T.ReturnDate,
    T.IsApproved
FROM
    Member AS M
LEFT JOIN
    Transactions AS T ON M.MemberID = T.MemberID;

--3. right join
SELECT
    M.MemberID,
    M.FirstName,
    M.TotalBorrowedBook,
    T.TransactionID,
    T.BookID,
    T.CheckoutDate,
    T.ReturnDate,
    T.IsApproved
FROM
    Transactions AS T
RIGHT JOIN
     Member AS M ON M.MemberID = T.MemberID;

--4. full join
SELECT
    M.MemberID,
    M.FirstName,
    M.TotalBorrowedBook,
    T.TransactionID,
    T.BookID,
    T.CheckoutDate,
    T.ReturnDate,
    T.IsApproved
FROM
    Member AS M
FULL OUTER JOIN
    Transactions AS T ON M.MemberID = T.MemberID;




--DB3: Social DB
--1. inner join
	
SELECT *
FROM Posts
INNER JOIN Comments ON Posts.PostID = Comments.PostID;


--2. left join
SELECT *
FROM Posts
LEFT JOIN Comments ON Posts.PostID = Comments.PostID;


--3. right join
SELECT *
FROM Posts
RIGHT JOIN Comments ON Posts.PostID = Comments.PostID;


--4. full join
SELECT *
FROM Posts
FULL OUTER JOIN Comments ON Posts.PostID = Comments.PostID;



