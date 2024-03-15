--Scaler value funtions

--1. Inventory table : 
--RETURN CATEGORY NAME
CREATE FUNCTION dbo.getCategoryName(@CategoryId INT)
RETURNS NVARCHAR(255)
AS
BEGIN
	DECLARE @CategoryName NVARCHAR(255);

	SELECT @CategoryName = Category_Name
	FROM Category
	WHERE CategoryID=@CategoryId;

	RETURN @CategoryName;
END;

SELECT dbo.getCategoryName(2);


--GET CUSTOMER DOB:
CREATE FUNCTION dbo.getBirthDate(@CustomerID INT)
RETURNS DATE
AS
BEGIN
	DECLARE @DOB DATE;

	SELECT @DOB = DateOfBirth
	FROM Customer
	WHERE CustomerID=@CustomerID;

	RETURN @DOB;
END;

SELECT dbo.getBirthDate(2);




--2. Library DB:
-- category active status
CREATE FUNCTION dbo.getCategoryStatus(@CategoryId INT)
RETURNS BIT
AS
BEGIN
	DECLARE @isActive BIT;

	SELECT @isActive = IsActive
	FROM Category
	WHERE CategoryID = @CategoryId;

	RETURN @isActive;
END;

SELECT dbo.getCategoryStatus(2);


--get bestseller of author
CREATE FUNCTION dbo.getBestSeller(@authorName NVARCHAR(50))
RETURNS NVARCHAR(255)
AS
BEGIN
	DECLARE @bestSeller NVARCHAR(255);

	SELECT @bestSeller = BestSeller
	FROM Author
	WHERE FirstName = @authorName;

	RETURN @bestSeller;
END;

SELECT dbo.getBestSeller('John');



--3. Social Media DB:-
--get Total Users

CREATE FUNCTION dbo.getTotalUsers()
RETURNS INT
AS 
BEGIN
	DECLARE @totalCount INT;

	SELECT @totalCount = COUNT(UserID) FROM Users;

	RETURN @totalCount;
end;

SELECT dbo.getTotalUsers();

--GET LIKES AND COMMENTS
CREATE FUNCTION dbo.GetLikesAndCommentsCount(@PostID INT)
RETURNS NVARCHAR(MAX)
AS
BEGIN
    DECLARE @Result NVARCHAR(MAX);

    SELECT @Result = 'Likes: ' + CAST(Likes AS NVARCHAR(10)) + ', Comments: ' + CAST(Comments AS NVARCHAR(10))
    FROM Posts
    WHERE PostID = @PostID;


    RETURN @Result;
END;

SELECT
    dbo.GetLikesAndCommentsCount(4) AS LikesAndCommentsCount;