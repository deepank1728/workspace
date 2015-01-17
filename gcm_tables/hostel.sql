-- phpMyAdmin SQL Dump
-- version 4.0.9
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 03, 2014 at 11:45 PM
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

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
