-- phpMyAdmin SQL Dump
-- version 4.0.9
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 06, 2014 at 02:26 AM
-- Server version: 5.6.14
-- PHP Version: 5.5.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `college_stat2`
--

-- --------------------------------------------------------

--
-- Table structure for table `chem_company`
--

CREATE TABLE IF NOT EXISTS `chem_company` (
  `s_no` int(11) DEFAULT NULL,
  `company_name` text,
  `company_info` text,
  `message` text,
  `date` int(11) DEFAULT NULL,
  `day` int(11) DEFAULT NULL,
  `year` int(11) DEFAULT NULL,
  `placement_info` text NOT NULL,
  `start_date` text NOT NULL,
  `end_date` text NOT NULL,
  `enddate` int(11) NOT NULL,
  `endmonth` int(11) NOT NULL,
  `endyear` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `chem_company`
--

INSERT INTO `chem_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `start_date`, `end_date`, `enddate`, `endmonth`, `endyear`) VALUES
(NULL, 'ntpc', 'chem', 'Date of Arrival: 10th august 2014\r\n\r\nExpected package: 5 Lakhs\r\nEligibility Criteria: 6.5 Pointer', 10, 8, 2014, '2 placed', '10-8-2014', '', 0, 0, 0),
(2, 'cfcl', 'chemical company', 'Date of Arrival:27th august 2014', 27, 8, 2014, '15 placed', '27-8-2014', '28-8-2014', 28, 8, 2014);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
