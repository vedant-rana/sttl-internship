/* Triggers in DB */
--======================================================================================================================
-- DB1: Inventory DB
--======================================================================================================================

-- BEFORE INSERT Trigger
CREATE TRIGGER BeforeInsertProduct
ON Product
FOR INSERT
AS
BEGIN
    PRINT 'Before Insert Trigger on Product';
END;

-- DROP TRIGGER BeforeInsertProduct;

INSERT INTO Product (ProductID, ProductName, Product_Desc, Price, Stock, CatogoryID)
VALUES(22, 'Tea', 'fresh tea', 20.00, 50, 3);

-- SELECT * FROM Product;
--======================================================================================================================


-- AFTER INSERT Trigger
CREATE TRIGGER AfterInsertProduct
ON Product
AFTER INSERT
AS
BEGIN
    PRINT 'After Insert Trigger on Product';
END;

-- DROP TRIGGER AfterInsertProduct;

INSERT INTO Product (ProductID, ProductName, Product_Desc, Price, Stock, CatogoryID)
VALUES(21, 'Tea', 'fresh tea', 20.00, 50, 3);

-- SELECT * FROM Product;

--======================================================================================================================
-- BEFORE UPDATE Trigger
CREATE TRIGGER BeforeUpdateProduct
ON Product
FOR UPDATE
AS
BEGIN
    PRINT 'Before Update Trigger on Product';
END;

-- DROP TRIGGER BeforeUpdateProduct;
UPDATE Product 
	SET Product_Desc = 'TATA Tea'
WHERE 
	ProductID = 22;

-- SELECT * FROM Product;
--======================================================================================================================

-- AFTER UPDATE Trigger
CREATE TRIGGER AfterUpdateProduct
ON Product
AFTER UPDATE
AS
BEGIN
    PRINT 'After Update Trigger on Product';
END;


-- DROP TRIGGER AfterUpdateProduct;
UPDATE Product 
	SET Product_Desc = 'TATA Tea'
WHERE 
	ProductID = 21;

-- SELECT * FROM Product;
--======================================================================================================================


-- BEFORE DELETE Trigger
CREATE TRIGGER BeforeDeleteProduct
ON Product
FOR DELETE
AS
BEGIN
    PRINT 'Before Delete Trigger on Product';
END;

-- DROP TRIGGER BeforeDeleteProduct;

DELETE FROM Product 
WHERE ProductID  = 22;

-- SELECT * FROM Product;
--======================================================================================================================


-- AFTER DELETE Trigger
CREATE TRIGGER AfterDeleteProduct
ON Product
AFTER DELETE
AS
BEGIN
    PRINT 'After Delete Trigger on Product';
END;


-- DROP TRIGGER BeforeDeleteProduct;

DELETE FROM Product 
WHERE ProductID  = 21;

-- SELECT * FROM Product;


--======================================================================================================================
--======================================================================================================================
--DB2: Library DB
--======================================================================================================================

-- BEFORE INSERT Trigger
CREATE TRIGGER BeforeInsertBook
ON Book
FOR INSERT
AS
BEGIN
    PRINT 'Before Insert Trigger on Book';
END;

-- DROP TRIGGER BeforeInsertBook;

INSERT INTO Book (BookID, Title, Author, PublicationYear, ISBN, AvailableCopies, CategoryId)
VALUES (121, 'The Sci-fi', 'John Doe', 2020, '1234567890', 10, 1);

-- SELECT * FROM Book;
--======================================================================================================================


-- AFTER INSERT Trigger
CREATE TRIGGER AfterInsertBook
ON Book
AFTER INSERT
AS
BEGIN
    PRINT 'After Insert Trigger on Book';
END;

-- DROP TRIGGER AfterInsertBook;

INSERT INTO Book (BookID, Title, Author, PublicationYear, ISBN, AvailableCopies, CategoryId)
VALUES (120, 'The Sci-fi', 'John Doe', 2020, '1234567890', 10, 1);

-- SELECT * FROM Book;

--======================================================================================================================
-- BEFORE UPDATE Trigger
CREATE TRIGGER BeforeUpdateBook
ON Book
FOR UPDATE
AS
BEGIN
    PRINT 'Before Update Trigger on Book';
END;

-- DROP TRIGGER BeforeUpdateBook;
UPDATE Book 
	SET Author = 'Jane doe'
WHERE 
	BookID = 121;

-- SELECT * FROM Book;
--======================================================================================================================

-- AFTER UPDATE Trigger
CREATE TRIGGER AfterUpdateBook
ON Book
AFTER UPDATE
AS
BEGIN
    PRINT 'After Update Trigger on Book';
END;


-- DROP TRIGGER AfterUpdateBook;
UPDATE Book 
	SET Author = 'Jane doe'
WHERE 
	BookID = 120;

-- SELECT * FROM Book;
--======================================================================================================================


-- BEFORE DELETE Trigger
CREATE TRIGGER BeforeDeleteBook
ON Book
FOR DELETE
AS
BEGIN
    PRINT 'Before Delete Trigger on Book';
END;

-- DROP TRIGGER BeforeDeleteBook;

DELETE FROM Book 
WHERE BookID  = 121;

-- SELECT * FROM Book;
--======================================================================================================================


-- AFTER DELETE Trigger
CREATE TRIGGER AfterDeleteBook
ON Book
AFTER DELETE
AS
BEGIN
    PRINT 'After Delete Trigger on Book';
END;

-- DROP TRIGGER AfterDeleteBook;

DELETE FROM Book 
WHERE BookID  = 120;

-- SELECT * FROM Book;


--======================================================================================================================
--======================================================================================================================
--DB3: Social Media DB
--======================================================================================================================


-- BEFORE INSERT Trigger
CREATE TRIGGER BeforeInsertPosts
ON Posts
FOR INSERT
AS
BEGIN
    PRINT 'Before Insert Trigger on Posts';
END;

-- DROP TRIGGER BeforeInsertPosts;
INSERT INTO Posts (PostID, UserID, Content, PostDate, Likes, Comments)
VALUES
(21, 1, 'Hello World!', '2022-01-01 12:05:00', 15, 5);

-- SELECT * FROM Posts;
--======================================================================================================================


-- AFTER INSERT Trigger
CREATE TRIGGER AfterInsertPosts
ON Posts
AFTER INSERT
AS
BEGIN
    PRINT 'After Insert Trigger on Posts';
END;

-- DROP TRIGGER AfterInsertPosts;
INSERT INTO Posts (PostID, UserID, Content, PostDate, Likes, Comments)
VALUES(22, 1, 'Hello World!', '2022-01-01 12:05:00', 15, 5);

-- SELECT * FROM Posts;

--======================================================================================================================
-- BEFORE UPDATE Trigger
CREATE TRIGGER BeforeUpdatePosts
ON Posts
FOR UPDATE
AS
BEGIN
    PRINT 'Before Update Trigger on Posts';
END;

-- DROP TRIGGER BeforeUpdatePosts;
UPDATE Posts 
	SET Content = 'Jane doe'
WHERE 
	PostID = 21;

-- SELECT * FROM Posts;
--======================================================================================================================

-- AFTER UPDATE Trigger
CREATE TRIGGER AfterUpdatePosts
ON Posts
AFTER UPDATE
AS
BEGIN
    PRINT 'After Update Trigger on Posts';
END;


-- DROP TRIGGER AfterUpdatePosts;
UPDATE Posts 
	SET Content = 'Jane doe'
WHERE 
	PostID = 22;

-- SELECT * FROM Posts;
--======================================================================================================================


-- BEFORE DELETE Trigger
CREATE TRIGGER BeforeDeletePosts
ON Posts
FOR DELETE
AS
BEGIN
    PRINT 'Before Delete Trigger on Posts';
END;

-- DROP TRIGGER BeforeDeletePosts;

DELETE FROM Posts 
WHERE PostID  = 21;

-- SELECT * FROM Posts;
--======================================================================================================================


-- AFTER DELETE Trigger
CREATE TRIGGER AfterDeletePosts
ON Posts
AFTER DELETE
AS
BEGIN
    PRINT 'After Delete Trigger on Posts';
END;

-- DROP TRIGGER AfterDeletePosts;

DELETE FROM Posts 
WHERE PostID  = 22;

-- SELECT * FROM Posts;


