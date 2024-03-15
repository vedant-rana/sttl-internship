CREATE TABLE Customer (
    CustomerId INT IDENTITY(1001,1) PRIMARY KEY,
    Name VARCHAR(255),
    Email VARCHAR(255),
    Address TEXT,
    IsDeleted BIT DEFAULT 0
);


CREATE TABLE Product (
    ProductId INT IDENTITY(1001,1) PRIMARY KEY,
    Name VARCHAR(255),
    Description TEXT,
    Price DECIMAL(10, 2),
    StockQuantity INT,
    IsDeleted BIT DEFAULT 0
);


CREATE TABLE Orders (
    OrderId INT IDENTITY(1001,1) PRIMARY KEY,
    CustomerId INT,
    OrderDate DATE,
    TotalAmount DECIMAL(10, 2),
    Status VARCHAR(50),
    IsDeleted BIT DEFAULT 0,
    FOREIGN KEY (CustomerId) REFERENCES Customer(CustomerId)
);

CREATE TABLE OrderItem (
    OrderItemId INT IDENTITY(1001,1) PRIMARY KEY,
    OrderId INT,
    ProductId INT,
    Quantity INT,
    UnitPrice DECIMAL(10, 2),
    IsDeleted BIT DEFAULT 0,
    FOREIGN KEY (OrderId) REFERENCES Orders(OrderId),
    FOREIGN KEY (ProductId) REFERENCES Product(ProductId)
);

select * from Product;
select * from Customer;
select * from Orders;
select*  from OrderItem;

drop table Product;
drop table Customer;

INSERT INTO Customer (Name, Email, Address, IsDeleted) VALUES
('John Doe', 'johndoe@example.com', '123 Elm Street, Anytown', 0),
('Jane Smith', 'janesmith@example.com', '456 Oak Avenue, Somewhere', 0),
('Alice Johnson', 'alicej@example.com', '789 Pine Road, Anywhere', 0),
('Bob Brown', 'bobbrown@example.com', '101 Maple Lane, Everywhere', 0),
('Charlie Davis', 'charlied@example.com', '202 Birch Street, Nowhere', 0);


INSERT INTO Product (Name, Description, Price, StockQuantity, IsDeleted) VALUES
('Laptop', 'High-performance laptop', 1200.00, 50, 0),
('Smartphone', 'Latest model smartphone', 800.00, 100, 0),
('Tablet', '10-inch screen tablet', 600.00, 75, 0),
('Headphones', 'Noise-cancelling headphones', 150.00, 150, 0),
('Smartwatch', 'Smartwatch with heart rate monitor', 250.00, 200, 0);


INSERT INTO Orders (CustomerId, OrderDate, TotalAmount, Status, IsDeleted) VALUES
(1001, '2023-01-01', 2000.00, 'Completed', 0),
(1002, '2023-01-02', 1600.00, 'Shipped', 0),
(1003, '2023-01-03', 850.00, 'Processing', 0),
(1004, '2023-01-04', 300.00, 'Cancelled', 0),
(1005, '2023-01-05', 500.00, 'Completed', 0);


INSERT INTO OrderItem (OrderId, ProductId, Quantity, UnitPrice, IsDeleted) VALUES
(1001, 1001, 1, 1200.00, 0), -- Order 1001 includes 1 Laptop
(1002, 1002, 2, 800.00, 0), -- Order 1002 includes 2 Smartphones
(1003, 1003, 1, 600.00, 0), -- Order 1003 includes 1 Tablet
(1004, 1004, 1, 150.00, 0), -- Order 1004 includes 1 Headphones
(1005, 1005, 2, 250.00, 0); -- Order 1005 includes 2 Smartwatches
