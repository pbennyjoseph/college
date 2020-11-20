-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 19, 2020 at 05:15 PM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.4.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `mydb`
--

-- --------------------------------------------------------

--
-- Table structure for table `memorecords`
--

CREATE TABLE `memorecords` (
  `id` int(11) NOT NULL,
  `rlno` varchar(15) NOT NULL,
  `subject` text NOT NULL,
  `marks` int(11) NOT NULL,
  `total` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `memorecords`
--

INSERT INTO `memorecords` (`id`, `rlno`, `subject`, `marks`, `total`) VALUES
(1, '1602-18-733-010', 'MPMCI', 25, 30),
(4, '1602-18-733-010', 'DAA', 26, 30),
(5, '1602-18-733-010', 'OS', 23, 30),
(6, '1602-18-733-010', 'CN', 15, 30),
(7, '1602-18-733-999', 'MPMCI', 24, 30),
(9, '1602-18-733-999', 'DAA', 28, 30),
(10, '1602-18-733-999', 'OS', 29, 30),
(11, '1602-18-733-999', 'CN', 25, 30),
(12, '1602-18-733-998', 'DAA', 30, 30),
(13, '1602-18-733-998', 'OS', 3, 30),
(14, '1602-18-733-998', 'MPMCI', 2, 30),
(15, '1602-18-733-998', 'CN', 1, 30);

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE `students` (
  `id` int(11) NOT NULL,
  `rlno` varchar(15) NOT NULL,
  `name` text NOT NULL,
  `fnam` text NOT NULL,
  `moname` text NOT NULL,
  `semester` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`id`, `rlno`, `name`, `fnam`, `moname`, `semester`) VALUES
(1, '1602-18-733-010', 'P Benny Joseph', 'P Philip', 'P Rebekah', 4),
(2, '1602-18-733-999', 'Morgan Smith', 'Joe Smith', 'Ashley Smith', 4),
(4, '1602-18-733-998', 'James Bond', 'Andrew Bond', 'Monique Delacroix', 4);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `memorecords`
--
ALTER TABLE `memorecords`
  ADD PRIMARY KEY (`id`),
  ADD KEY `rlnoref` (`rlno`);

--
-- Indexes for table `students`
--
ALTER TABLE `students`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `rlno` (`rlno`),
  ADD KEY `rlno_2` (`rlno`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `memorecords`
--
ALTER TABLE `memorecords`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `students`
--
ALTER TABLE `students`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `memorecords`
--
ALTER TABLE `memorecords`
  ADD CONSTRAINT `rlnoref` FOREIGN KEY (`rlno`) REFERENCES `students` (`rlno`) ON DELETE NO ACTION ON UPDATE NO ACTION;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
