-- phpMyAdmin SQL Dump
-- version 3.5.8.2
-- http://www.phpmyadmin.net
--
-- Host: sql200.byetcluster.com
-- Generation Time: Oct 03, 2014 at 05:23 PM
-- Server version: 5.6.19-67.0
-- PHP Version: 5.3.3

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
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
-- Table structure for table `centers`
--

CREATE TABLE IF NOT EXISTS `centers` (
  `s_no` int(11) NOT NULL,
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `centers`
--

INSERT INTO `centers` (`s_no`, `type`, `name`, `info`) VALUES
(1, 'Computer Center', 'cccdf', 'The Central Computer Centre caters to the needs of different academic departments and various sections of the institute. '),
(2, 'Alumni Section', ' dsfd', 'In the Student Alumni Mentorship Program, students are matched with an MNIT alumni '),
(3, 'Library Section', 'vxv', 'A university is just a group of buildings gathered around a library— Shelby Foote\r\n');

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
  `enddate` int(11) NOT NULL,
  `endmonth` int(11) NOT NULL,
  `endyear` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `chem_company`
--

INSERT INTO `chem_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `enddate`, `endmonth`, `endyear`) VALUES
(NULL, 'ntpc', 'chem', 'Date of Arrival: 10th august 2014\r\n\r\nExpected package: 5 Lakhs\r\nEligibility Criteria: 6.5 Pointer', 10, 8, 2014, '2 placed', 0, 0, 0),
(2, 'cfcl', 'chemical company', 'Date of Arrival:27th august 2014', 27, 8, 2014, '15 placed', 28, 8, 2014);

-- --------------------------------------------------------

--
-- Table structure for table `civil_company`
--

CREATE TABLE IF NOT EXISTS `civil_company` (
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
-- Dumping data for table `civil_company`
--

INSERT INTO `civil_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `enddate`, `endmonth`, `endyear`) VALUES
(1, 'Hindustan Construction Company Limited', 'construction company', 'Date of Arrival: 11th August 2014', 11, 8, 2014, '', 0, 0, 0),
(3, 'Bhel', 'civil company', 'Date of Arrival: 1 september 2014', 1, 9, 2014, '', 0, 0, 0),
(3, 'Aashiyana Housing', 'Construction company', 'Date of Arrival: 3rd october  2014', 3, 10, 2014, '', 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `company`
--

CREATE TABLE IF NOT EXISTS `company` (
  `company_name` text,
  `company_info` text,
  `other_info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

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
  `enddate` int(11) NOT NULL,
  `endmonth` int(11) NOT NULL,
  `endyear` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `comp_company`
--

INSERT INTO `comp_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `enddate`, `endmonth`, `endyear`) VALUES
(1, 'Amazon', 'software company', 'Arrival Date:28th july 2014\r\n\r\nComapny will take 1st round on 28th July 2014 and other rounds on 29th july 2014', 28, 7, 2014, '5 placed', 29, 7, 2014),
(2, 'Future first', 'open category company', 'Date of Arrival: 31st july 2014\r\n\r\nCompany will take 1st round on 31st july 2014.\r\nPointer criteria: 5.0 with no backlogs.\r\nExpected Package: 9 Lakhs', 31, 7, 2014, '', 0, 0, 0),
(3, 'Xpedia', 'Software company', 'Date of Arrival: 1st august 2014\r\n\r\nExpected package:12 Lakhs\r\nEligibility criteria: Above 7.0 Pointer', 1, 8, 2014, '5 Placed', 2, 8, 2014),
(4, 'Adobe', 'software oriented company', 'Date of Arrival: 29th july 2014\r\nExpected Package: 15 lakhs\r\nEligibility Critera: 7.4 Pointer', 29, 7, 2014, '7 Placed', 30, 7, 2014),
(5, 'microsoft', 'Software company', 'Arrival Date:5th august 2014\r\n\r\nExpected Package: 15 Lakhs\r\nEligibility Criteria:7.5 Pointer', 5, 8, 2014, '7 Placed', 6, 8, 2014),
(6, 'Oracle', 'software company', 'Date of Arrival:29th august 2014', 29, 8, 2014, '10 Placed', 30, 8, 2014),
(7, 'Morgan Stanley', 'software company', 'Date of Arrival:30th august 2014', 30, 8, 2014, '', 0, 0, 0),
(8, 'JP Morgan', 'software company', 'Date of Arrival:31th august 2014', 31, 8, 2014, '', 0, 0, 0),
(9, 'envidia', 'software + hardware', 'Date of Arrival:11nd september 2014', 11, 9, 2014, '', 0, 0, 0),
(10, 'dell', 'software', 'Date of Arrival:12th september 2014', 12, 9, 2014, '', 0, 0, 0),
(11, 'hp', 'software + hardware', 'Date of Arrival:13th september 2014', 13, 9, 2014, '', 0, 0, 0),
(12, 'wooqer', 'Software company', 'Date of Arrival: 5th october  2014', 5, 10, 2014, '15 placed', 6, 10, 2014),
(13, 'google', 'Software company', 'Date of Arrival: 4rd october  2014', 4, 10, 2014, '10 placed', 15, 10, 2014),
(14, 'SalesForce', 'Software company', 'Date of Arrival : 19th september 2014', 19, 9, 2014, '', 0, 0, 0),
(15, 'infoedge', 'Software company', 'Date of Arrival: 6th october  2014', 6, 10, 2014, '', 0, 0, 0),
(16, 'cdot', 'Software company', 'Date of Arrival: 7th october  2014', 7, 10, 2014, '15 placed', 8, 10, 2014),
(17, 'cdeck', 'govt.', 'Date of Arrival:27th october  2014', 27, 10, 2014, '2 placed:\r\narvind kejriwal,narendra modi', 28, 10, 2014),
(20, 'sap labs', 'software company', 'Date of arrival: 31st october 2014', 31, 10, 2014, '', 0, 0, 0),
(18, 'aspiring minds', 'Arrival date: 19th November', 'expected package 15 lpa', 27, 12, 2014, '', 0, 0, 0),
(19, 'applied Materials', 'arrival Date 15th october', 'Date of Arrival:25th october expected package 9.6 lpa', 25, 12, 2014, '', 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `dean`
--

CREATE TABLE IF NOT EXISTS `dean` (
  `s_no` int(11) NOT NULL,
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `dean`
--

INSERT INTO `dean` (`s_no`, `type`, `name`, `info`) VALUES
(1, 'Administration', 'M.K. Shrimali', '\nProfessor\n+91-141-2713364'),
(2, 'Student Welfare', 'R. C. Gupta', 'Professor	\n	+91-141-2713364'),
(1, 'Research & Consultancy', 'Awadhesh Bhardwaj', 'Professor\n Ph.no.+91-141-2713263');

-- --------------------------------------------------------

--
-- Table structure for table `departments`
--

CREATE TABLE IF NOT EXISTS `departments` (
  `s_no` int(11) NOT NULL,
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `departments`
--

INSERT INTO `departments` (`s_no`, `type`, `name`, `info`) VALUES
(1, 'Computer Engineering', 'Computer Engineering', 'Place where computer engieers are made'),
(2, 'Mechanical Engineering', 'Mechanical Engineering', 'Place where computer engieers are made'),
(3, 'Electrical Engineering', 'Electrical Engineering', 'Place where Electrical engieers are made');

-- --------------------------------------------------------

--
-- Table structure for table `director`
--

CREATE TABLE IF NOT EXISTS `director` (
  `s_no` int(11) NOT NULL,
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `director`
--

INSERT INTO `director` (`s_no`, `type`, `name`, `info`) VALUES
(1, 'Prof. I. K. Bhatt', 'Prof. I. K. Bhatt', 'Office :Administrative Block –I, MNIT Campus, JLN Marg, Jaipur-302017 \n\r\nPhone :+91 141 2529087 \n\r\nFax :+91 141 2529029 \n\r\nE-mail:director@mnit.ac.in');

-- --------------------------------------------------------

--
-- Table structure for table `electrical_company`
--

CREATE TABLE IF NOT EXISTS `electrical_company` (
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
-- Dumping data for table `electrical_company`
--

INSERT INTO `electrical_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `enddate`, `endmonth`, `endyear`) VALUES
(1, 'L&T Technology', 'electrical company', 'Date of Arrival:12th August 2014', 12, 8, 2014, '', 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `extras`
--

CREATE TABLE IF NOT EXISTS `extras` (
  `s_no` int(11) NOT NULL DEFAULT '0',
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL,
  `venue` text NOT NULL,
  `date` int(11) NOT NULL,
  `month` int(11) NOT NULL,
  `year` int(11) NOT NULL,
  `time` text NOT NULL,
  `organizers` text NOT NULL,
  PRIMARY KEY (`s_no`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `extras`
--

INSERT INTO `extras` (`s_no`, `type`, `name`, `info`, `venue`, `date`, `month`, `year`, `time`, `organizers`) VALUES
(1, 'cultural', 'blitzchalg', 'Do you ever wonder how the unfortunate sector of our society, the penurious and poverty-stricken, can fight all the odds and be stars in their own fields of interests just like we all do?\nChildren all over the world do not have access to quality education. Educational disadvantage is perhaps the worlds most fundamental injustice. It persists in different countries at all stages of development, severely limiting children''s life prospects. The foundation of every society is Education. We understand the importance of education but more importantly, we understand the value of each of those 320 million lives and the potential in every one of them.', 'MNIT Jaipur', 20, 11, 2014, '05:14:25', 'Aabhas Jain'),
(2, 'technical', 'techexpo', 'Have you ever had that one scientific idea which you carried in your mind after class, to your home, thinking over and over, reading about it, and then waiting for an opportunity to present it? If yes, then you''ve come to the right place!\r\nBlitzschlag 2014 takes great pleasure in announcing the commencement of Tech-Expo''14 - The Technical Leg of Blitzschlag, 2014. First of its kind in its country, Tech-Expo''14 (4-6 April, 2014) strives to provide a platform to the students to exhibit their ideas in front of an extensive panel of pioneers from the industry and the academia. \r\n', 'MNIT JAIPUR', 25, 12, 2014, '9 AM to 6 PM', 'Director''s Face off\r\nRitesh Batra\r\n(Director: The Lunchbox)'),
(3, 'sports', 'MST', 'The origin of MST (MNIT Sports Tournament) dates back to 2007 when the event made a kick start with more than 600 participants and 16 teams from well-reputed institute all over the country including IITs, NITs, BITS Pilani, DCE, etc. This year being the 5th version of MST, the fest has culminated a sports culture to develop in the institute and the essence of the fest lies in the fact that it contributes to sharpen the sporting talent not just in the present crop of sports-persons but also create a new generation striving to excel in their chosen games with full support of the faculty. With a participation of over 800 players and more than 20 colleges participating last year, MST ’11 was a huge success. With major reforms and inchoate events never witnessed before, coming up MST ’12 promises to be bigger and better this year. The event shall witness 3 days and nights of absorbing sporting action.', 'MNIT JAIPUR SPORTS GROUND', 12, 1, 2015, '8AM to 5 PM', 'SPORTS DEPARTMENT MNIT JAIPUR');

-- --------------------------------------------------------

--
-- Table structure for table `gcm_users`
--

CREATE TABLE IF NOT EXISTS `gcm_users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `gcm_regid` text,
  `name` varchar(50) NOT NULL,
  `email` varchar(255) NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Dumping data for table `gcm_users`
--

INSERT INTO `gcm_users` (`id`, `gcm_regid`, `name`, `email`, `created_at`) VALUES
(2, 'APA91bGnfGdRsPn6-g8hkmld0bygrQAsPWM-qHrOt5kg2A0p0Zw6fyr-vUJ6eyneUNFdaZTPguEGC-Gbou5uZvm3-atv84NSYANv8hCCdxjd-w3YZ5Cx_OIw0Vl1CS8YOc6aNdzmw7ohVUywIzmxvpcKWCPlKhLLjEofQy8s98QuOb7W2Pi6qK8', 'shub', 'shub@gmail.com', '2014-06-26 10:25:17');

-- --------------------------------------------------------

--
-- Table structure for table `hostel`
--

CREATE TABLE IF NOT EXISTS `hostel` (
  `s_no` text NOT NULL,
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `hostel`
--

INSERT INTO `hostel` (`s_no`, `type`, `name`, `info`) VALUES
('1', 'Hostel no : 1', ' Hostel no : 1', 'WARDEN : \nSumit Khandelwal \nPh no :2254515\nposition :Prof. at Department of Civil Engineering \n\nCARETAKER :\nCN Pareek\nPh no : 4545745'),
('2', 'Hostel no : 2', ' Hostel no : 2', 'WARDEN : \nNamita Mittal \nPh no :2254516\nposition :Prof. at Department of Computer  Engineering \n\nCARETAKER :\nAabhas Jain\nPh no : 4545746'),
('3', 'Hostel no : 3', 'Hostel no : 3', 'WARDEN : \nVijay Laxmi \nPh no :2254517\nposition :Prof. at Department of Computer Engineering \n\nCARETAKER :\nDeepank Porwal\nPh no : 4545747');

-- --------------------------------------------------------

--
-- Table structure for table `mech_company`
--

CREATE TABLE IF NOT EXISTS `mech_company` (
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
-- Dumping data for table `mech_company`
--

INSERT INTO `mech_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `enddate`, `endmonth`, `endyear`) VALUES
(1, 'bajaj', 'mech company', 'Date of Arrival: 13th August 2014', 13, 8, 2014, '', 0, 0, 0),
(2, 'tata motors', 'automobile company', 'Date of Arrival:26th august 2014', 26, 8, 2014, '', 0, 0, 0);

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

-- --------------------------------------------------------

--
-- Table structure for table `others`
--

CREATE TABLE IF NOT EXISTS `others` (
  `s_no` int(11) NOT NULL,
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `others`
--

INSERT INTO `others` (`s_no`, `type`, `name`, `info`) VALUES
(1, 'Hospital', 'Hospital', '\r\nA full-fledged Dispensary is available in the campus. It is supervised by a residential Medical Officer and two Compounders. The services of a part-time Ayurvedic Doctor and a Lady Doctor are also available to students and to the family members of the staff.'),
(2, 'Sports', 'Sports', 'The Annual Athletic meet 2014 will be organized on 18-19 January.Under the eminent leadership of our honourable director Prof I.K.Bhat. The Annual athletic meet aims to propagate the concept of national integration, spirit of communal harmony, brotherhood, courage and adventure amongst the youth by exhibiting their physical & cultural prowess in the playfield.');

-- --------------------------------------------------------

--
-- Table structure for table `ptp`
--

CREATE TABLE IF NOT EXISTS `ptp` (
  `s_no` int(11) DEFAULT NULL,
  `company_name` text,
  `date` int(11) DEFAULT NULL,
  `month` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `section`
--

CREATE TABLE IF NOT EXISTS `section` (
  `s_no` int(11) NOT NULL,
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `section`
--

INSERT INTO `section` (`s_no`, `type`, `name`, `info`) VALUES
(1, 'Academic Section', '', 'This is the place where grades are made'),
(2, 'Account Section', '', 'This is the place where records of finance are kept');

-- --------------------------------------------------------

--
-- Table structure for table `timestampvalue`
--

CREATE TABLE IF NOT EXISTS `timestampvalue` (
  `value` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `timestampvalue`
--

INSERT INTO `timestampvalue` (`value`) VALUES
(8);

-- --------------------------------------------------------

--
-- Table structure for table `tronics_company`
--

CREATE TABLE IF NOT EXISTS `tronics_company` (
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
-- Dumping data for table `tronics_company`
--

INSERT INTO `tronics_company` (`s_no`, `company_name`, `company_info`, `message`, `date`, `day`, `year`, `placement_info`, `enddate`, `endmonth`, `endyear`) VALUES
(1, 'AMD', 'hardware company', 'Date of Arrival:16th August 2014', 16, 8, 2014, '', 0, 0, 0),
(2, 'Intel', 'Hardware company', 'Date of Arrival: 17th August 2014', 17, 8, 2014, '', 0, 0, 0),
(3, 'qualcom', 'hardware company', 'Date of Arrival:28th august 2014', 28, 8, 2014, '', 0, 0, 0),
(4, 'texus instrument', 'hardware', 'Date of Arrival:27th september 2014', 27, 9, 2014, '', 0, 0, 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
