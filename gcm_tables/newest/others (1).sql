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

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
