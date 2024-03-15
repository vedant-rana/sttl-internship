USE [Inventory_Module]
GO
/****** Object:  Table [dbo].[Category]    Script Date: 24-01-2024 16:07:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Category](
	[CategoryID] [int] NOT NULL,
	[Category_Name] [nvarchar](255) NULL,
	[Category_Desc] [text] NULL,
	[CreatedAt] [datetime] NULL,
	[ModifiedAt] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[CategoryID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Customer]    Script Date: 24-01-2024 16:07:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Customer](
	[CustomerID] [int] NOT NULL,
	[FirstName] [nvarchar](50) NULL,
	[LastName] [nvarchar](50) NULL,
	[DateOfBirth] [date] NULL,
	[Address] [nvarchar](255) NULL,
	[PhoneNumber] [varchar](15) NULL,
PRIMARY KEY CLUSTERED 
(
	[CustomerID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Product]    Script Date: 24-01-2024 16:07:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Product](
	[ProductID] [int] NOT NULL,
	[ProductName] [nvarchar](255) NULL,
	[Product_Desc] [text] NULL,
	[Price] [decimal](10, 2) NULL,
	[Stock] [int] NULL,
	[CatogoryID] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[ProductID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Supplier]    Script Date: 24-01-2024 16:07:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Supplier](
	[SupplierID] [int] NOT NULL,
	[SupplierName] [nvarchar](255) NULL,
	[ContactPerson] [nvarchar](100) NULL,
	[PhoneNumber] [varchar](15) NULL,
	[Email] [nvarchar](255) NULL,
	[Country] [nvarchar](50) NULL,
PRIMARY KEY CLUSTERED 
(
	[SupplierID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Transactions]    Script Date: 24-01-2024 16:07:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Transactions](
	[TransactionID] [int] NOT NULL,
	[ProductID] [int] NULL,
	[TransactionType] [nvarchar](50) NULL,
	[TransactionDate] [date] NULL,
	[QuantityChange] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[TransactionID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[Category] ([CategoryID], [Category_Name], [Category_Desc], [CreatedAt], [ModifiedAt]) VALUES (1, N'Electronics', N'Electronic gadgets and devices', CAST(N'2024-01-22T14:32:17.023' AS DateTime), CAST(N'2024-01-22T14:32:17.023' AS DateTime))
INSERT [dbo].[Category] ([CategoryID], [Category_Name], [Category_Desc], [CreatedAt], [ModifiedAt]) VALUES (2, N'Books', N'Literary works and publications', CAST(N'2024-01-22T14:32:17.023' AS DateTime), CAST(N'2024-01-22T14:32:17.023' AS DateTime))
INSERT [dbo].[Category] ([CategoryID], [Category_Name], [Category_Desc], [CreatedAt], [ModifiedAt]) VALUES (3, N'Home Appliances', N'Household electronic devices', CAST(N'2024-01-22T14:32:17.023' AS DateTime), CAST(N'2024-01-22T14:32:17.023' AS DateTime))
GO
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (1, N'John', N'Doe', CAST(N'1990-01-15' AS Date), N'123 Main St', N'123-456-7890')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (2, N'Jane', N'Smith', CAST(N'1985-05-20' AS Date), N'456 Oak St', N'987-654-3210')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (3, N'Bob', N'Johnson', CAST(N'1992-08-10' AS Date), N'789 Pine St', N'111-222-3333')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (4, N'Alice', N'Williams', CAST(N'1988-03-05' AS Date), N'456 Elm St', N'555-333-7777')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (5, N'Charlie', N'Brown', CAST(N'1995-11-30' AS Date), N'789 Maple St', N'444-888-9999')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (6, N'Eva', N'Miller', CAST(N'1983-07-22' AS Date), N'123 Birch St', N'777-111-2222')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (7, N'David', N'Anderson', CAST(N'1999-02-18' AS Date), N'456 Cedar St', N'666-555-4444')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (8, N'Grace', N'Turner', CAST(N'1980-12-08' AS Date), N'789 Oak St', N'333-222-1111')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (9, N'Frank', N'Wilson', CAST(N'1994-09-14' AS Date), N'123 Pine St', N'999-444-6666')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (10, N'Sara', N'Baker', CAST(N'1987-06-25' AS Date), N'456 Maple St', N'888-777-5555')
INSERT [dbo].[Customer] ([CustomerID], [FirstName], [LastName], [DateOfBirth], [Address], [PhoneNumber]) VALUES (20, N'Jane', N'Doe', CAST(N'1990-01-01' AS Date), N'123 Main St.', N'555-1234')
GO
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (1, N'Laptop', N'High-performance laptop', CAST(1200.00 AS Decimal(10, 2)), 20, 1)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (2, N'Smartphone', N'Latest smartphone model', CAST(800.00 AS Decimal(10, 2)), 15, 1)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (3, N'LED TV', N'Large screen LED television', CAST(1500.00 AS Decimal(10, 2)), 10, 1)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (4, N'Novel', N'Bestselling fiction novel', CAST(20.00 AS Decimal(10, 2)), 50, 2)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (5, N'Coffee Maker', N'Automatic coffee brewing machine', CAST(100.00 AS Decimal(10, 2)), 12, 3)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (6, N'Tablet', N'Portable tablet device', CAST(500.00 AS Decimal(10, 2)), 18, 1)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (7, N'Cookbook', N'Collection of popular recipes', CAST(15.00 AS Decimal(10, 2)), 30, 2)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (8, N'Refrigerator', N'Large capacity refrigerator', CAST(1200.00 AS Decimal(10, 2)), 8, 3)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (9, N'Desk Lamp', N'Adjustable LED desk lamp', CAST(50.00 AS Decimal(10, 2)), 25, 1)
INSERT [dbo].[Product] ([ProductID], [ProductName], [Product_Desc], [Price], [Stock], [CatogoryID]) VALUES (10, N'Digital Camera', N'High-resolution digital camera', CAST(700.00 AS Decimal(10, 2)), 10, 1)
GO
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (1, N'TechCorp', N'Alice Johnson', N'555-123-4567', N'alice@techcorp.com', N'USA')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (2, N'GadgetWorld', N'Bob Smith', N'555-987-6543', N'bob@gadgetworld.com', N'Canada')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (3, N'ElectroTech', N'Charlie Brown', N'555-111-2222', N'charlie@electrotech.com', N'USA')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (4, N'GlobalTech', N'David Johnson', N'555-333-4444', N'david@globaltech.com', N'UK')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (5, N'MegaGizmos', N'Eva Miller', N'555-555-5555', N'eva@megagizmos.com', N'Germany')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (6, N'TechHub', N'Frank Wilson', N'555-666-7777', N'frank@techhub.com', N'USA')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (7, N'ElectroGadgets', N'Grace Turner', N'555-888-9999', N'grace@electrogadgets.com', N'Canada')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (8, N'SmartSupplies', N'Sara Baker', N'555-999-1111', N'sara@smartsupplies.com', N'Germany')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (9, N'GlobalElectronics', N'John Smith', N'555-777-8888', N'john@globalelectronics.com', N'UK')
INSERT [dbo].[Supplier] ([SupplierID], [SupplierName], [ContactPerson], [PhoneNumber], [Email], [Country]) VALUES (10, N'InnovateTech', N'Emma Wilson', N'555-222-3333', N'emma@innovatetech.com', N'USA')
GO
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (1, 1, N'Sale', CAST(N'2024-01-15' AS Date), -5)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (2, 2, N'Purchase', CAST(N'2024-01-20' AS Date), 10)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (3, 3, N'Sale', CAST(N'2024-01-25' AS Date), -3)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (4, 1, N'Purchase', CAST(N'2024-02-01' AS Date), 8)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (5, 2, N'Sale', CAST(N'2024-02-10' AS Date), -2)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (6, 3, N'Sale', CAST(N'2024-02-18' AS Date), -1)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (7, 4, N'Purchase', CAST(N'2024-03-05' AS Date), 5)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (8, 5, N'Sale', CAST(N'2024-03-12' AS Date), -4)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (9, 1, N'Sale', CAST(N'2024-03-20' AS Date), -2)
INSERT [dbo].[Transactions] ([TransactionID], [ProductID], [TransactionType], [TransactionDate], [QuantityChange]) VALUES (10, 2, N'Purchase', CAST(N'2024-04-02' AS Date), 7)
GO
ALTER TABLE [dbo].[Product]  WITH CHECK ADD FOREIGN KEY([CatogoryID])
REFERENCES [dbo].[Category] ([CategoryID])
GO
ALTER TABLE [dbo].[Transactions]  WITH CHECK ADD FOREIGN KEY([ProductID])
REFERENCES [dbo].[Product] ([ProductID])
GO
/****** Object:  Trigger [dbo].[AfterDeleteProduct]    Script Date: 24-01-2024 16:07:22 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- AFTER DELETE Trigger
CREATE TRIGGER [dbo].[AfterDeleteProduct]
ON [dbo].[Product]
AFTER DELETE
AS
BEGIN
    PRINT 'After Delete Trigger on Product';
END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [AfterDeleteProduct]
GO
/****** Object:  Trigger [dbo].[AfterInsertProduct]    Script Date: 24-01-2024 16:07:23 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[AfterInsertProduct]
ON [dbo].[Product]
AFTER INSERT
AS
BEGIN
    PRINT 'After Insert Trigger on Product';
END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [AfterInsertProduct]
GO
/****** Object:  Trigger [dbo].[AfterUpdateProduct]    Script Date: 24-01-2024 16:07:23 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

-- AFTER UPDATE Trigger
CREATE TRIGGER [dbo].[AfterUpdateProduct]
ON [dbo].[Product]
AFTER UPDATE
AS
BEGIN
    PRINT 'After Update Trigger on Product';
END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [AfterUpdateProduct]
GO
/****** Object:  Trigger [dbo].[BeforeDeleteProduct]    Script Date: 24-01-2024 16:07:23 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- BEFORE DELETE Trigger
CREATE TRIGGER [dbo].[BeforeDeleteProduct]
ON [dbo].[Product]
FOR DELETE
AS
BEGIN
    PRINT 'Before Delete Trigger on Product';
END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [BeforeDeleteProduct]
GO
/****** Object:  Trigger [dbo].[BeforeInsertProduct]    Script Date: 24-01-2024 16:07:23 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- BEFORE INSERT Trigger
CREATE TRIGGER [dbo].[BeforeInsertProduct]
ON [dbo].[Product]
FOR INSERT
AS
BEGIN
    PRINT 'Before Insert Trigger on Product';
END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [BeforeInsertProduct]
GO
/****** Object:  Trigger [dbo].[BeforeUpdateProduct]    Script Date: 24-01-2024 16:07:23 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TRIGGER [dbo].[BeforeUpdateProduct]
ON [dbo].[Product]
FOR UPDATE
AS
BEGIN
    PRINT 'Before Update Trigger on Product';
END;
GO
ALTER TABLE [dbo].[Product] ENABLE TRIGGER [BeforeUpdateProduct]
GO
