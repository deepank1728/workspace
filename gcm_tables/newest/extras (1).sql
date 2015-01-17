-- phpMyAdmin SQL Dump
-- version 4.0.9
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 06, 2014 at 02:27 AM
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
-- Table structure for table `extras`
--

CREATE TABLE IF NOT EXISTS `extras` (
  `s_no` int(11) NOT NULL DEFAULT '0',
  `type` text NOT NULL,
  `name` text NOT NULL,
  `info` text NOT NULL,
  `venue` text NOT NULL,
  `start_date` text NOT NULL,
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

INSERT INTO `extras` (`s_no`, `type`, `name`, `info`, `venue`, `start_date`, `date`, `month`, `year`, `time`, `organizers`) VALUES
(1, 'cultural', 'blitzchalg', 'Do you ever wonder how the unfortunate sector of our society, the penurious and poverty-stricken, can fight all the odds and be stars in their own fields of interests just like we all do?\nChildren all over the world do not have access to quality education. Educational disadvantage is perhaps the worlds most fundamental injustice. It persists in different countries at all stages of development, severely limiting children''s life prospects. The foundation of every society is Education. We understand the importance of education but more importantly, we understand the value of each of those 320 million lives and the potential in every one of them.', 'MNIT Jaipur', '20-11-2014', 20, 11, 2014, '05:14:25', 'Aabhas Jain'),
(2, 'technical', 'techexpo', 'Have you ever had that one scientific idea which you carried in your mind after class, to your home, thinking over and over, reading about it, and then waiting for an opportunity to present it? If yes, then you''ve come to the right place!\r\nBlitzschlag 2014 takes great pleasure in announcing the commencement of Tech-Expo''14 - The Technical Leg of Blitzschlag, 2014. First of its kind in its country, Tech-Expo''14 (4-6 April, 2014) strives to provide a platform to the students to exhibit their ideas in front of an extensive panel of pioneers from the industry and the academia. \r\n', 'MNIT JAIPUR', '25-12-2014', 25, 12, 2014, '9 AM to 6 PM', 'Director''s Face off\r\nRitesh Batra\r\n(Director: The Lunchbox)'),
(3, 'sports', 'MST', 'The origin of MST (MNIT Sports Tournament) dates back to 2007 when the event made a kick start with more than 600 participants and 16 teams from well-reputed institute all over the country including IITs, NITs, BITS Pilani, DCE, etc. This year being the 5th version of MST, the fest has culminated a sports culture to develop in the institute and the essence of the fest lies in the fact that it contributes to sharpen the sporting talent not just in the present crop of sports-persons but also create a new generation striving to excel in their chosen games with full support of the faculty. With a participation of over 800 players and more than 20 colleges participating last year, MST ’11 was a huge success. With major reforms and inchoate events never witnessed before, coming up MST ’12 promises to be bigger and better this year. The event shall witness 3 days and nights of absorbing sporting action.', 'MNIT JAIPUR SPORTS GROUND', '12-1-2015', 12, 1, 2015, '8AM to 5 PM', 'SPORTS DEPARTMENT MNIT JAIPUR'),
(4, 'technical', 'neuron', 'technical fest', 'mnit', '6-11-2014', 0, 0, 0, '10:00 AM', 'anurag saxena');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
