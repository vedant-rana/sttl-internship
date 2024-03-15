/* Stored Procedures */
--============================================================================================

--DB 1: Inventory Module DB

-- 1. Select 
CREATE PROCEDURE getAllProducts
AS 
BEGIN
	SELECT * FROM Product;
END;

EXEC getAllProducts;

--2. Add
CREATE PROCEDURE addCustomer
	@id INT,
	@fname NVARCHAR(50),
	@lname NVARCHAR(50),
	@dob DATE,
	@Address NVARCHAR(255),
    @PhoneNumber VARCHAR(15)
AS 
BEGIN
	INSERT INTO Customer(CustomerID, FirstName, LastName, DateOfBirth, Address, PhoneNumber)
	VALUES (@id, @fname, @lname, @dob, @Address, @PhoneNumber);
END;

EXEC addCustomer
	@id = 20,
	@fname = 'jane',
	@lname = 'doe',
	@dob = '1990-01-01',
	@Address = '123 main st.',
    @PhoneNumber ='555-1234';

SELECT * FROM Customer;

--3. Update
CREATE PROCEDURE updateNumber
	@id INT,
	@number VARCHAR(15)
AS
BEGIN
	UPDATE Customer
	SET
		PhoneNumber = @number
	WHERE 
		CustomerID = @id;
END;

EXEC updateNumber
	@id = 20,
	@number = '1234567890'

SELECT * FROM Customer;

--4. Delete
CREATE PROCEDURE DeleteCustomer
    @CustomerID INT
AS
BEGIN
    DELETE FROM Customer
    WHERE CustomerID = @CustomerID;
END;

EXEC DeleteCustomer
@CustomerID = 20;

SELECT * FROM Customer;


---5. All
-- Create a procedure that performs various operations based on a parameter

CREATE PROCEDURE ManageCustomerOperations
    @OperationType VARCHAR(10),
    @CustomerID INT = NULL,
    @FirstName NVARCHAR(50) = NULL,
    @LastName NVARCHAR(50) = NULL,
    @DateOfBirth DATE = NULL,
    @Address NVARCHAR(255) = NULL,
    @PhoneNumber VARCHAR(15) = NULL
AS
BEGIN
    IF @OperationType = 'Select'
    BEGIN
        -- Select all products
        SELECT * FROM Product;
    END
    ELSE IF @OperationType = 'Add'
    BEGIN
        -- Add a new customer
        INSERT INTO Customer (CustomerID, FirstName, LastName, DateOfBirth, Address, PhoneNumber)
        VALUES (@CustomerID, @FirstName, @LastName, @DateOfBirth, @Address, @PhoneNumber);
    END
    ELSE IF @OperationType = 'Update'
    BEGIN
        -- Update customer's phone number
        UPDATE Customer
        SET PhoneNumber = @PhoneNumber
        WHERE CustomerID = @CustomerID;
    END
    ELSE IF @OperationType = 'Delete'
    BEGIN
        -- Delete customer
        DELETE FROM Customer
        WHERE CustomerID = @CustomerID;
    END
    ELSE
    BEGIN
        PRINT 'Invalid operation type';
    END
END;



EXEC ManageCustomerOperations @OperationType = 'Select';

EXEC ManageCustomerOperations 
    @OperationType = 'Add',
    @CustomerID = 20,
    @FirstName = 'Jane',
    @LastName = 'Doe',
    @DateOfBirth = '1990-01-01',
    @Address = '123 Main St.',
    @PhoneNumber = '555-1234';

SELECT * FROM Customer;

EXEC ManageCustomerOperations @OperationType = 'addNew';


--============================================================================================
--DB 2: Library DB

-- 1. Select 
CREATE PROCEDURE getAllCategories
AS
BEGIN
	SELECT * FROM Category;
END;

EXEC getAllCategories;


--2. Add
CREATE PROCEDURE AddCategory
	@id INT,
	@CategoryName NVARCHAR(50),
    @Description NVARCHAR(255),
    @IsActive BIT,
    @CreatedDate DATETIME
AS
BEGIN
	INSERT INTO Category(CategoryID, CategoryName, Description, IsActive, CreatedDate)
	VALUES (@id, @CategoryName, @Description, @IsActive, @CreatedDate);
END;

EXEC AddCategory
	@id = 20,
	@CategoryName ='sci-fi',
    @Description ='new sci-fi',
    @IsActive=0,
    @CreatedDate ='2024-01-23T10:00:00';

EXEC getAllCategories;



--3. Update
CREATE PROCEDURE updateStatus
	@id INT,
	@status BIT
AS
BEGIN
	UPDATE Category
	SET
		IsActive = @status
	WHERE 
		CategoryID = @id;
END;

EXEC updateStatus
	@id = 20,
	@status=1;

EXEC getAllCategories;



--4. Delete
CREATE PROCEDURE deleteCategory
    @id INT
AS
BEGIN
    DELETE FROM Category
    WHERE CategoryID = @id;
END;

EXEC deleteCategory
@id = 20;

EXEC getAllCategories;



---5. All
CREATE PROCEDURE manageCategory
	@optype VARCHAR(10),
	@id INT=NULL,
	@CategoryName NVARCHAR(50)=NULL,
    @Description NVARCHAR(255)=NULL,
    @IsActive BIT=NULL,
    @CreatedDate DATETIME = NULL
AS
BEGIN 
	IF @optype='select'
	BEGIN
		SELECT * FROM Category;
	END
	ELSE IF @optype='add'
	BEGIN
		INSERT INTO Category(CategoryID, CategoryName, Description, IsActive, CreatedDate)
		VALUES (@id, @CategoryName, @Description, @IsActive, @CreatedDate);
	END	
	ELSE IF @optype='update'
	BEGIN
		UPDATE Category
		SET
			IsActive = @IsActive
		WHERE 
			CategoryID = @id;
	END
	ELSE IF @optype = 'delete'
	BEGIN
		DELETE FROM Category
		WHERE CategoryID = @id;
	END
	ELSE 
	BEGIN
		PRINT 'invalid Operation';
	END
END;

EXEC manageCategory 
	@optype = 'select';

EXEC manageCategory
	@optype='add',
	@id = 20,
	@CategoryName ='sci-fi',
    @Description ='new sci-fi',
    @IsActive=0,
    @CreatedDate ='2024-01-23T10:00:00';


--============================================================================================
--DB 3: Social media DB

-- 1. Select 
CREATE PROCEDURE getAllPosts
AS
BEGIN
	SELECT * FROM Posts;
END;

EXEC getAllPosts;


--2. Add
CREATE PROCEDURE AddPost
    @PostID INT ,
    @UserID INT,
    @Content TEXT,
    @PostDate DATETIME,
    @Likes INT,
    @Comments INT

AS
BEGIN
	INSERT INTO Posts (PostID, UserID, Content, PostDate, Likes, Comments)
	VALUES(@PostID, @UserID, @Content,@PostDate, @Likes,@Comments);
END;

EXEC AddPost
	@PostID =15 ,
    @UserID =5,
    @Content ='new comment',
    @PostDate ='2022-01-10 17:30:00',
    @Likes=20,
    @Comments =10;

Select * from posts;


--3. Update
CREATE PROCEDURE updatePosts
	@id INT,
	@content TEXT
AS
BEGIN
	UPDATE Posts
	SET
		Content = @content
	WHERE 
		PostID = @id;
END;


EXEC updatePosts
	@id = 15,
	@content = 'updated Content'

EXEC getAllPosts;



--4. Delete
CREATE PROCEDURE deletePost
    @id INT
AS
BEGIN
    DELETE FROM Posts
    WHERE PostID = @id;
END;

EXEC deletePost
@id = 15;

EXEC getAllPosts;


---5. All
CREATE PROCEDURE ManagePostsOperations
    @OperationType VARCHAR(10),
    @PostID INT = NULL,
    @UserID INT = NULL,
    @Content TEXT = NULL,
    @PostDate DATETIME = NULL,
    @Likes INT = NULL,
    @Comments INT = NULL
AS
BEGIN
    IF @OperationType = 'Select'
    BEGIN
        -- Select all posts
        SELECT * FROM Posts;
    END
    ELSE IF @OperationType = 'Add'
    BEGIN
        -- Add a new post
        INSERT INTO Posts (PostID, UserID, Content, PostDate, Likes, Comments)
        VALUES (@PostID, @UserID, @Content, @PostDate, @Likes, @Comments);
    END
    ELSE IF @OperationType = 'Update'
    BEGIN
        -- Update post content
        UPDATE Posts
        SET Content = @Content
        WHERE PostID = @PostID;
    END
    ELSE IF @OperationType = 'Delete'
    BEGIN
        -- Delete post
        DELETE FROM Posts
        WHERE PostID = @PostID;
    END
    ELSE
    BEGIN
        PRINT 'Invalid operation type';
    END
END;


EXEC ManagePostsOperations @OperationType = 'Select';

EXEC ManagePostsOperations
    @OperationType = 'Add',
    @PostID = 15,
    @UserID = 5,
    @Content = 'new comment',
    @PostDate = '2022-01-10 17:30:00',
    @Likes = 20,
    @Comments = 10;


