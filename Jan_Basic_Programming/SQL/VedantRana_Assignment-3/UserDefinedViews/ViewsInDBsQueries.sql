--Views for all DBS:

-- 1. Inventory DB:
-- View from single DB:
CREATE VIEW ViewOfProduct AS
SELECT ProductID, ProductName, Price, Stock
FROM Product;

SELECT * FROM ViewOfProduct;

--View from Multiple tables
CREATE VIEW CompositeProduct AS
SELECT 
	P.ProductID,
	P.ProductName,
	P.Price,
	T.TransactionID,
	TransactionDate,
	QuantityChange
FROM Product P INNER JOIN Transactions T ON P.ProductID=T.ProductID;

SELECT * FROM CompositeProduct;




--2. LIBRARY SYSTEM DB:
--VIEW CREATED WITH SINGLE TABLE
CREATE VIEW ViewOfBook AS
SELECT 
	BookID ,
    Title ,
    ISBN ,
    AvailableCopies ,
	CategoryId 
FROM 
	Book;

SELECT * FROM ViewOfBook;

-- VIEW CREATED WITH MULTIPLE TABLE
CREATE VIEW CompositeOfBook AS
SELECT 
	B.BookID,
	B.Title,
	B.Author,
	C.CategoryName
FROM 
Book B JOIN Category C 
ON B.CategoryId=C.CategoryID;

SELECT * FROM CompositeOfBook;



--2. SOCIAL MEDIA DB:
--VIEW CREATED WITH SINGLE TABLE
CREATE VIEW CloneUsers AS
SELECT * FROM 
Users;

SELECT * FROM CloneUsers;


-- VIEW CREATED WITH MULTIPLE TABLE
CREATE VIEW CompositeOfFriends AS
SELECT 
	U.UserID,
	U.Username,
	F.UserID2,
	F.FriendshipDate
FROM 
	Users U LEFT JOIN Friends F ON U.UserID = F.UserID1;

	SELECT * FROM CompositeOfFriends;
