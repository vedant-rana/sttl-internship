USE [master]
GO
/****** Object:  Database [QuestionSystem]    Script Date: 20-02-2024 20:33:36 ******/
CREATE DATABASE [QuestionSystem]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'QuestionSystem', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\QuestionSystem.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'QuestionSystem_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.MSSQLSERVER\MSSQL\DATA\QuestionSystem_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [QuestionSystem] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [QuestionSystem].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [QuestionSystem] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [QuestionSystem] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [QuestionSystem] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [QuestionSystem] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [QuestionSystem] SET ARITHABORT OFF 
GO
ALTER DATABASE [QuestionSystem] SET AUTO_CLOSE ON 
GO
ALTER DATABASE [QuestionSystem] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [QuestionSystem] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [QuestionSystem] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [QuestionSystem] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [QuestionSystem] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [QuestionSystem] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [QuestionSystem] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [QuestionSystem] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [QuestionSystem] SET  ENABLE_BROKER 
GO
ALTER DATABASE [QuestionSystem] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [QuestionSystem] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [QuestionSystem] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [QuestionSystem] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [QuestionSystem] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [QuestionSystem] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [QuestionSystem] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [QuestionSystem] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [QuestionSystem] SET  MULTI_USER 
GO
ALTER DATABASE [QuestionSystem] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [QuestionSystem] SET DB_CHAINING OFF 
GO
ALTER DATABASE [QuestionSystem] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [QuestionSystem] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [QuestionSystem] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [QuestionSystem] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [QuestionSystem] SET QUERY_STORE = OFF
GO
USE [QuestionSystem]
GO
/****** Object:  Table [dbo].[Approval]    Script Date: 20-02-2024 20:33:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Approval](
	[approveId] [int] IDENTITY(1,1) NOT NULL,
	[paperId] [int] NULL,
	[userId] [int] NULL,
	[is_approved] [bit] NOT NULL,
	[approvedAt] [datetime] NULL,
PRIMARY KEY CLUSTERED 
(
	[approveId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Questions]    Script Date: 20-02-2024 20:33:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Questions](
	[queId] [int] IDENTITY(1,1) NOT NULL,
	[question] [nvarchar](max) NOT NULL,
	[opt1] [nvarchar](50) NOT NULL,
	[opt2] [nvarchar](50) NOT NULL,
	[opt3] [nvarchar](50) NOT NULL,
	[opt4] [nvarchar](50) NOT NULL,
	[answer] [nvarchar](50) NOT NULL,
	[paperId] [int] NULL,
PRIMARY KEY CLUSTERED 
(
	[queId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[QuestionsPaper]    Script Date: 20-02-2024 20:33:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[QuestionsPaper](
	[paperId] [int] IDENTITY(1,1) NOT NULL,
	[title] [varchar](255) NOT NULL,
	[description] [nvarchar](max) NOT NULL,
	[noOfQuestions] [int] NOT NULL,
	[status] [varchar](20) NOT NULL,
	[creation_date] [datetime] NULL,
	[CreatedBy] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[paperId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ScoreCard]    Script Date: 20-02-2024 20:33:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ScoreCard](
	[ansId] [int] IDENTITY(1,1) NOT NULL,
	[userId] [int] NULL,
	[paperId] [int] NULL,
	[score] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[ansId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Users]    Script Date: 20-02-2024 20:33:37 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Users](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[name] [nvarchar](30) NOT NULL,
	[email] [nvarchar](30) NOT NULL,
	[password] [nvarchar](max) NOT NULL,
	[role] [varchar](20) NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Questions] ON 

INSERT [dbo].[Questions] ([queId], [question], [opt1], [opt2], [opt3], [opt4], [answer], [paperId]) VALUES (11, N'what is tree ?', N'1', N'2', N'3', N'4', N'1', 13)
INSERT [dbo].[Questions] ([queId], [question], [opt1], [opt2], [opt3], [opt4], [answer], [paperId]) VALUES (12, N'what is graph ?', N'1', N'2', N'3', N'4', N'2', 13)
INSERT [dbo].[Questions] ([queId], [question], [opt1], [opt2], [opt3], [opt4], [answer], [paperId]) VALUES (13, N'what is Array?', N'1', N'2', N'3', N'4', N'2', 13)
INSERT [dbo].[Questions] ([queId], [question], [opt1], [opt2], [opt3], [opt4], [answer], [paperId]) VALUES (15, N'what is tree ?', N'1', N'2', N'3', N'4', N'2', 16)
INSERT [dbo].[Questions] ([queId], [question], [opt1], [opt2], [opt3], [opt4], [answer], [paperId]) VALUES (16, N'what is graph ?', N'1', N'2', N'3', N'4', N'3', 16)
SET IDENTITY_INSERT [dbo].[Questions] OFF
GO
SET IDENTITY_INSERT [dbo].[QuestionsPaper] ON 

INSERT [dbo].[QuestionsPaper] ([paperId], [title], [description], [noOfQuestions], [status], [creation_date], [CreatedBy]) VALUES (13, N'p1 by t1', N'prepared by t1', 5, N'approved', CAST(N'2024-02-20T15:06:06.000' AS DateTime), 8)
INSERT [dbo].[QuestionsPaper] ([paperId], [title], [description], [noOfQuestions], [status], [creation_date], [CreatedBy]) VALUES (15, N'new Paper', N'maths', 3, N'pending', CAST(N'2024-02-20T19:47:52.000' AS DateTime), 7)
INSERT [dbo].[QuestionsPaper] ([paperId], [title], [description], [noOfQuestions], [status], [creation_date], [CreatedBy]) VALUES (16, N'new', N'asdnva', 2, N'pending', CAST(N'2024-02-20T20:06:57.633' AS DateTime), 8)
SET IDENTITY_INSERT [dbo].[QuestionsPaper] OFF
GO
SET IDENTITY_INSERT [dbo].[ScoreCard] ON 

INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (1, 6, 13, 0)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (2, 6, 13, 0)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (3, 6, 13, 0)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (4, 6, 13, -138)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (5, 6, 13, 0)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (6, 6, 13, 0)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (7, 6, 13, 0)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (8, 6, 13, 0)
INSERT [dbo].[ScoreCard] ([ansId], [userId], [paperId], [score]) VALUES (9, 6, 13, 0)
SET IDENTITY_INSERT [dbo].[ScoreCard] OFF
GO
SET IDENTITY_INSERT [dbo].[Users] ON 

INSERT [dbo].[Users] ([id], [name], [email], [password], [role]) VALUES (2, N'abc', N'abc@gmail.com', N'123456789', N'student')
INSERT [dbo].[Users] ([id], [name], [email], [password], [role]) VALUES (6, N'User1', N'user1@gmail.com', N'1234', N'student')
INSERT [dbo].[Users] ([id], [name], [email], [password], [role]) VALUES (7, N'vedant', N'vedant@gmail.com', N'1234', N'admin')
INSERT [dbo].[Users] ([id], [name], [email], [password], [role]) VALUES (8, N'teacher1', N'teacher1@gmail.com', N'1234', N'teacher')
INSERT [dbo].[Users] ([id], [name], [email], [password], [role]) VALUES (9, N'teacher2', N'teacher2@gmail.com', N'1234', N'teacher')
INSERT [dbo].[Users] ([id], [name], [email], [password], [role]) VALUES (10, N'Shreyash', N'shrey@gmail.com', N'12345', N'teacher')
SET IDENTITY_INSERT [dbo].[Users] OFF
GO
ALTER TABLE [dbo].[Approval] ADD  DEFAULT ((0)) FOR [is_approved]
GO
ALTER TABLE [dbo].[Approval] ADD  DEFAULT (getdate()) FOR [approvedAt]
GO
ALTER TABLE [dbo].[QuestionsPaper] ADD  DEFAULT ('pending') FOR [status]
GO
ALTER TABLE [dbo].[QuestionsPaper] ADD  DEFAULT (getdate()) FOR [creation_date]
GO
ALTER TABLE [dbo].[Users] ADD  DEFAULT ('student') FOR [role]
GO
ALTER TABLE [dbo].[Approval]  WITH CHECK ADD FOREIGN KEY([paperId])
REFERENCES [dbo].[QuestionsPaper] ([paperId])
GO
ALTER TABLE [dbo].[Approval]  WITH CHECK ADD FOREIGN KEY([userId])
REFERENCES [dbo].[Users] ([id])
GO
ALTER TABLE [dbo].[Approval]  WITH CHECK ADD  CONSTRAINT [FK_Approval_QuestionsPaper] FOREIGN KEY([paperId])
REFERENCES [dbo].[QuestionsPaper] ([paperId])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Approval] CHECK CONSTRAINT [FK_Approval_QuestionsPaper]
GO
ALTER TABLE [dbo].[Questions]  WITH CHECK ADD FOREIGN KEY([paperId])
REFERENCES [dbo].[QuestionsPaper] ([paperId])
GO
ALTER TABLE [dbo].[Questions]  WITH CHECK ADD  CONSTRAINT [FK_Questions_QuestionsPaper] FOREIGN KEY([paperId])
REFERENCES [dbo].[QuestionsPaper] ([paperId])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Questions] CHECK CONSTRAINT [FK_Questions_QuestionsPaper]
GO
ALTER TABLE [dbo].[QuestionsPaper]  WITH CHECK ADD FOREIGN KEY([CreatedBy])
REFERENCES [dbo].[Users] ([id])
GO
ALTER TABLE [dbo].[ScoreCard]  WITH CHECK ADD FOREIGN KEY([paperId])
REFERENCES [dbo].[QuestionsPaper] ([paperId])
GO
ALTER TABLE [dbo].[ScoreCard]  WITH CHECK ADD FOREIGN KEY([userId])
REFERENCES [dbo].[Users] ([id])
GO
ALTER TABLE [dbo].[QuestionsPaper]  WITH CHECK ADD CHECK  (([noOfQuestions]<=(10)))
GO
ALTER TABLE [dbo].[QuestionsPaper]  WITH CHECK ADD  CONSTRAINT [CK_Status] CHECK  (([status]='rejected' OR [status]='pending' OR [status]='approved'))
GO
ALTER TABLE [dbo].[QuestionsPaper] CHECK CONSTRAINT [CK_Status]
GO
ALTER TABLE [dbo].[Users]  WITH CHECK ADD  CONSTRAINT [CK_Role] CHECK  (([role]='teacher' OR [role]='admin' OR [role]='student'))
GO
ALTER TABLE [dbo].[Users] CHECK CONSTRAINT [CK_Role]
GO
USE [master]
GO
ALTER DATABASE [QuestionSystem] SET  READ_WRITE 
GO
