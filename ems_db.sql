-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 21, 2024 at 01:27 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ems_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `adminID` int(255) NOT NULL,
  `adminName` varchar(255) NOT NULL,
  `adminPhoneNumber` varchar(15) NOT NULL,
  `adminEmail` varchar(255) NOT NULL,
  `adminPassword` varchar(8) NOT NULL,
  `adminUsername` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`adminID`, `adminName`, `adminPhoneNumber`, `adminEmail`, `adminPassword`, `adminUsername`) VALUES
(1, 'Aznitah', '01160542815', 'nuraznitah257@gmail.com', '123', 'admin');

-- --------------------------------------------------------

--
-- Table structure for table `client`
--

CREATE TABLE `client` (
  `clientID` int(255) NOT NULL,
  `clientName` varchar(255) NOT NULL,
  `clientPhoneNumber` varchar(15) NOT NULL,
  `clientEmail` varchar(255) NOT NULL,
  `clientUsername` varchar(8) NOT NULL,
  `clientPassword` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `client`
--

INSERT INTO `client` (`clientID`, `clientName`, `clientPhoneNumber`, `clientEmail`, `clientUsername`, `clientPassword`) VALUES
(2, 'aznitah', '01160542815', 'aznitah@gmail.com', 'saaznita', 'aznitah123'),
(3, 'Aqilah', '012345678', 'aqilah@gmail.com', 'aqil', 'aqilah123'),
(4, 'ain', '0134685432', 'ain@gmail.com', 'sayaain', 'ain123'),
(5, 'Afiqah', '012345789', 'afiq@gmail.com', 'afiqafiq', 'afiq123'),
(6, 'az', '012345678', 'az@gmail.com', 'sazn', 'azni123'),
(7, 'nabilah', '012348586', 'nabilah@gmail.com', 'nabilah', 'nabilah123'),
(8, 'sarah', '01238373', 'sarah@gmail.com', 'sarah', 'sarah123'),
(9, 'izyan', '013273987', 'izyan@gmail.com', 'saizyan', 'izyan123'),
(10, 'Adnin', '0129485743', 'Adnin@gmail.com', 'adnin1', 'adnin123');

-- --------------------------------------------------------

--
-- Table structure for table `client_event`
--

CREATE TABLE `client_event` (
  `id` int(11) NOT NULL,
  `clientID` int(255) NOT NULL,
  `eventID` int(255) NOT NULL,
  `detail` varchar(255) NOT NULL,
  `paymentID` int(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `client_event`
--

INSERT INTO `client_event` (`id`, `clientID`, `eventID`, `detail`, `paymentID`) VALUES
(1, 3, 28, '', 8),
(2, 3, 29, '', 5),
(3, 3, 29, '', NULL),
(4, 3, 35, '', NULL),
(6, 3, 1, '', 9);

-- --------------------------------------------------------

--
-- Table structure for table `event`
--

CREATE TABLE `event` (
  `eventID` int(255) NOT NULL,
  `eventName` varchar(255) NOT NULL,
  `eventDescription` varchar(255) NOT NULL,
  `eventDate` timestamp(6) NOT NULL DEFAULT current_timestamp(6) ON UPDATE current_timestamp(6),
  `eventVenue` varchar(255) DEFAULT NULL,
  `eventPrice` varchar(255) NOT NULL,
  `eventCapacity` varchar(50) NOT NULL,
  `venueID` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `event`
--

INSERT INTO `event` (`eventID`, `eventName`, `eventDescription`, `eventDate`, `eventVenue`, `eventPrice`, `eventCapacity`, `venueID`) VALUES
(1, 'Birthday Party', 'Decoration: Basic\nFacility: 2 medium tables + 10 chairs\n', '2024-06-20 22:38:55.209159', 'Dewan Chempaka', 'RM: 150.00', '0', 1),
(10, 'engagement', 'wjdiejf', '2024-06-19 23:48:22.670803', NULL, 'rm234.00', '56', 2),
(28, 'Birthday Party', 'Premium decoration with 10 tables and 100 chairs', '2024-06-20 16:53:19.126233', NULL, 'RM 350.00', '0', 1),
(29, 'Engagement', 'Premium deco', '2024-06-20 22:32:09.565743', NULL, 'RM 240.00', '0', 1),
(34, 'test 123', '123', '2024-06-20 22:37:24.348411', NULL, '123', '123', 4),
(35, '1 2 3', '321', '2024-06-20 22:37:34.034481', NULL, '321', '321', 3),
(36, 'wsw', 'wd', '2024-06-20 23:00:58.319460', NULL, 'wwd', '123', 1);

-- --------------------------------------------------------

--
-- Table structure for table `payment`
--

CREATE TABLE `payment` (
  `paymentID` int(255) NOT NULL,
  `paymentAmount` decimal(10,2) NOT NULL,
  `clientID` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `payment`
--

INSERT INTO `payment` (`paymentID`, `paymentAmount`, `clientID`) VALUES
(5, 240.00, 3),
(8, 350.00, 3),
(9, 150.00, 3);

-- --------------------------------------------------------

--
-- Table structure for table `rate`
--

CREATE TABLE `rate` (
  `id` int(11) NOT NULL,
  `eventID` int(11) NOT NULL,
  `comments` varchar(255) NOT NULL,
  `clientID` int(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `rate`
--

INSERT INTO `rate` (`id`, `eventID`, `comments`, `clientID`) VALUES
(1, 1, 'fdgthythy', 3),
(2, 10, 'eedrefrg', 3),
(3, 28, 'Very good service', 3),
(4, 29, 'frg', 3);

-- --------------------------------------------------------

--
-- Table structure for table `venue`
--

CREATE TABLE `venue` (
  `venueID` int(255) NOT NULL,
  `venueLocation` varchar(255) NOT NULL,
  `venueCategory` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `venue`
--

INSERT INTO `venue` (`venueID`, `venueLocation`, `venueCategory`) VALUES
(1, 'Dewan Chempaka', 'Birthday Party'),
(2, 'Dewan Lestari', 'Engagement'),
(3, 'Dewan Satria', 'Wedding'),
(4, 'Dewan Tuah', 'Dinner'),
(5, 'Dewan Jebat', 'FF');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`adminID`);

--
-- Indexes for table `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`clientID`);

--
-- Indexes for table `client_event`
--
ALTER TABLE `client_event`
  ADD PRIMARY KEY (`id`),
  ADD KEY `clients` (`clientID`),
  ADD KEY `eventss` (`eventID`),
  ADD KEY `paymentss` (`paymentID`);

--
-- Indexes for table `event`
--
ALTER TABLE `event`
  ADD PRIMARY KEY (`eventID`),
  ADD KEY `events` (`venueID`);

--
-- Indexes for table `payment`
--
ALTER TABLE `payment`
  ADD PRIMARY KEY (`paymentID`),
  ADD KEY `payments` (`clientID`);

--
-- Indexes for table `rate`
--
ALTER TABLE `rate`
  ADD PRIMARY KEY (`id`),
  ADD KEY `rates` (`clientID`),
  ADD KEY `event` (`eventID`);

--
-- Indexes for table `venue`
--
ALTER TABLE `venue`
  ADD PRIMARY KEY (`venueID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `adminID` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `client`
--
ALTER TABLE `client`
  MODIFY `clientID` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `client_event`
--
ALTER TABLE `client_event`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `event`
--
ALTER TABLE `event`
  MODIFY `eventID` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=37;

--
-- AUTO_INCREMENT for table `payment`
--
ALTER TABLE `payment`
  MODIFY `paymentID` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `rate`
--
ALTER TABLE `rate`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `venue`
--
ALTER TABLE `venue`
  MODIFY `venueID` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `client_event`
--
ALTER TABLE `client_event`
  ADD CONSTRAINT `clients` FOREIGN KEY (`clientID`) REFERENCES `client` (`clientID`),
  ADD CONSTRAINT `eventss` FOREIGN KEY (`eventID`) REFERENCES `event` (`eventID`),
  ADD CONSTRAINT `paymentss` FOREIGN KEY (`paymentID`) REFERENCES `payment` (`paymentID`);

--
-- Constraints for table `event`
--
ALTER TABLE `event`
  ADD CONSTRAINT `events` FOREIGN KEY (`venueID`) REFERENCES `venue` (`venueID`);

--
-- Constraints for table `payment`
--
ALTER TABLE `payment`
  ADD CONSTRAINT `payments` FOREIGN KEY (`clientID`) REFERENCES `client` (`clientID`);

--
-- Constraints for table `rate`
--
ALTER TABLE `rate`
  ADD CONSTRAINT `event` FOREIGN KEY (`eventID`) REFERENCES `event` (`eventID`),
  ADD CONSTRAINT `rates` FOREIGN KEY (`clientID`) REFERENCES `client` (`clientID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
