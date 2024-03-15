/* Non-Cluster Indexes */

--DB1: Inventory DB
--1 : Non-cluster index with 1 col
CREATE NONCLUSTERED INDEX IX_Customer_LastName
ON Customer (LastName);
sp_helpindex Customer;


--2 : Non-cluster index with 2 col
CREATE NONCLUSTERED INDEX IX_Supplier_Email_Country
ON Supplier (Email, Country);
sp_helpindex Supplier;



--DB2: Library DB
--1 : Non-cluster index with 1 col
CREATE NONCLUSTERED INDEX IX_Book_ISBN
ON Book (ISBN);
sp_helpindex Book;


--2 : Non-cluster index with 2 col
CREATE NONCLUSTERED INDEX IX_Transactions_Checkout_Return
ON Transactions (CheckoutDate, ReturnDate);
sp_helpindex Transactions;



--DB2: Social Media DB
--1 : Non-cluster index with 1 col
CREATE NONCLUSTERED INDEX IX_Comments_Date
ON Comments (CommentDate);
sp_helpindex Comments;

--2 : Non-cluster index with 2 col
CREATE NONCLUSTERED INDEX IX_Friends_U1_U2
ON Friends (UserID1, UserID2);
sp_helpindex Friends;


