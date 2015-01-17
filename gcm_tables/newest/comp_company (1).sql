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
-- Table structure for table `comp_company`
--

CREATE TABLE IF NOT EXISTS `comp_company` (
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
-- Dumping data for table `comp_company`
--

INSERT INTO `comp_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `start_date`, `end_date`, `enddate`, `endmonth`, `endyear`) VALUES
(1, 'Amazon', 'software company', 'Arrival Date:28th july 2014\r\n\r\nComapny will take 1st round on 28th July 2014 and other rounds on 29th july 2014', 28, 7, 2014, '5 placed', '28-7-2014', '29-7-2014', 29, 7, 2014),
(2, 'Future first', 'open category company', 'Date of Arrival: 31st july 2014\r\n\r\nCompany will take 1st round on 31st july 2014.\r\nPointer criteria: 5.0 with no backlogs.\r\nExpected Package: 9 Lakhs', 31, 7, 2014, '', '31-7-2014', '', 0, 0, 0),
(3, 'Xpedia', 'Software company', 'Date of Arrival: 1st august 2014\r\n\r\nExpected package:12 Lakhs\r\nEligibility criteria: Above 7.0 Pointer', 1, 8, 2014, '5 Placed', '1-8-2014', '2-8-2014', 2, 8, 2014),
(4, 'Adobe', 'software oriented company', 'Date of Arrival: 29th july 2014\r\nExpected Package: 15 lakhs\r\nEligibility Critera: 7.4 Pointer', 29, 7, 2014, '7 Placed', '29-7-2014', '30-7-2014', 30, 7, 2014),
(5, 'microsoft', 'Software company', 'Arrival Date:5th august 2014\r\n\r\nExpected Package: 15 Lakhs\r\nEligibility Criteria:7.5 Pointer', 5, 8, 2014, '7 Placed', '5-8-2014', '6-8-2014', 6, 8, 2014),
(6, 'Oracle', 'software company', 'Date of Arrival:29th august 2014', 29, 8, 2014, '10 Placed', '29-8-2014', '30-8-2014', 30, 8, 2014),
(7, 'Morgan Stanley', 'software company', 'Date of Arrival:30th august 2014', 30, 8, 2014, '', '30-8-2014', '', 0, 0, 0),
(8, 'JP Morgan', 'software company', 'Date of Arrival:31th august 2014', 31, 8, 2014, '', '31-8-2014', '', 0, 0, 0),
(9, 'envidia', 'software + hardware', 'Date of Arrival:11nd september 2014', 11, 9, 2014, '', '11-9-2014', '', 0, 0, 0),
(10, 'dell', 'software', 'Date of Arrival:12th september 2014', 12, 9, 2014, '', '12-9-2014', '', 0, 0, 0),
(11, 'hp', 'software + hardware', 'Date of Arrival:13th september 2014', 13, 9, 2014, '', '13-9-2014', '', 0, 0, 0),
(12, 'wooqer', 'Software company', 'Date of Arrival: 5th october  2014', 5, 10, 2014, '15 placed', '5-10-2014', '6-10-2014', 6, 10, 2014),
(13, 'google', 'Software company', 'Date of Arrival: 4rd october  2014', 4, 10, 2014, '10 placed', '4-10-2014', '15-10-2014', 15, 10, 2014),
(14, 'SalesForce', 'Software company', 'Date of Arrival : 19th september 2014', 19, 9, 2014, '', '19-9-2014', '', 0, 0, 0),
(15, 'infoedge', 'Software company', 'Date of Arrival: 6th october  2014', 6, 10, 2014, '', '6-10-2014', '', 0, 0, 0),
(16, 'cdot', 'Software company', 'Date of Arrival: 7th october  2014', 7, 10, 2014, '15 placed', '7-10-2014', '8-10-2014', 8, 10, 2014),
(17, 'cdeck', 'govt.', 'Date of Arrival:27th october  2014', 27, 10, 2014, '2 placed:\r\narvind kejriwal,narendra modi', '27-10-2014', '28-10-2014', 28, 10, 2014),
(20, 'sap labs', 'software company', 'Date of arrival: 31st october 2014', 31, 10, 2014, '', '31-10-2014', '', 0, 0, 0),
(18, 'aspiring minds', 'Arrival date: 19th November', 'expected package 15 lpa', 27, 12, 2014, '', '27-12-2014', '', 0, 0, 0),
(19, 'applied Materials', 'arrival Date 15th october', 'Date of Arrival:25th october expected package 9.6 lpa', 25, 12, 2014, '', '25-12-2014', '', 0, 0, 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
