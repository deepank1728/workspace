-- phpMyAdmin SQL Dump
-- version 4.0.9
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 03, 2014 at 11:46 PM
-- Server version: 5.6.14
-- PHP Version: 5.5.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `b7_15025964_college_stat`
--

-- --------------------------------------------------------

--
-- Table structure for table `meta_company`
--

CREATE TABLE IF NOT EXISTS `meta_company` (
  `s_no` int(11) DEFAULT NULL,
  `company_name` text,
  `company_info` text,
  `message` text,
  `date` int(11) DEFAULT NULL,
  `day` int(11) DEFAULT NULL,
  `year` int(11) DEFAULT NULL,
  `placement_info` text NOT NULL,
  `enddate` int(11) NOT NULL,
  `endmonth` int(11) NOT NULL,
  `endyear` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `meta_company`
--

INSERT INTO `meta_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `enddate`, `endmonth`, `endyear`) VALUES
(1, 'Jindal Steels', 'Meta company', 'Date of Arrival: 14th August 2014', 14, 8, 2014, '', 0, 0, 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
