-- phpMyAdmin SQL Dump
-- version 4.1.6
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Mar 07, 2014 at 12:25 PM
-- Server version: 5.5.36
-- PHP Version: 5.4.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `deenbandhu`
--

-- --------------------------------------------------------

--
-- Table structure for table `class`
--

CREATE TABLE IF NOT EXISTS `class` (
  `c_id` int(11) NOT NULL,
  `name` varchar(20) NOT NULL,
  PRIMARY KEY (`c_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `class`
--

INSERT INTO `class` (`c_id`, `name`) VALUES
(1, 'cp1-2nd year'),
(2, 'cp2-2nd year'),
(3, 'cp3-2nd year'),
(4, 'CP1 - 3rd year'),
(5, 'CP2 - 3rd year'),
(6, 'CP3 - 3rd year'),
(7, 'IT1 - 3rd year'),
(8, 'IT2 - 3rd year'),
(9, 'IT3 - 3rd year'),
(10, 'CP1 - 4th year'),
(11, 'CP2 - 4th year'),
(12, 'CP3 - 4th year'),
(13, 'IT1 - 4th year'),
(14, 'IT2 - 4th year'),
(15, 'IT3 - 4th year');

-- --------------------------------------------------------

--
-- Table structure for table `combination`
--

CREATE TABLE IF NOT EXISTS `combination` (
  `s_id` int(11) NOT NULL,
  `t_id` int(11) NOT NULL,
  `c_id` int(11) NOT NULL,
  `course` int(11) NOT NULL DEFAULT '1',
  `assigned` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`s_id`,`t_id`,`c_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `combination`
--

INSERT INTO `combination` (`s_id`, `t_id`, `c_id`, `course`, `assigned`) VALUES
(1, 6, 4, 1, 0),
(1, 6, 5, 1, 0),
(1, 6, 6, 1, 0),
(2, 5, 4, 1, 0),
(2, 5, 5, 1, 0),
(2, 5, 6, 1, 0),
(3, 4, 4, 1, 0),
(3, 4, 5, 1, 0),
(3, 4, 6, 1, 0),
(4, 4, 7, 1, 0),
(4, 4, 8, 1, 0),
(4, 4, 9, 1, 0),
(5, 7, 7, 1, 0),
(5, 7, 8, 1, 0),
(5, 7, 9, 1, 0),
(6, 11, 4, 1, 0),
(6, 11, 5, 1, 0),
(6, 11, 6, 1, 0),
(7, 16, 7, 1, 0),
(7, 16, 8, 1, 0),
(7, 16, 9, 1, 0),
(8, 15, 7, 1, 0),
(8, 15, 8, 1, 0),
(8, 15, 9, 1, 0),
(9, 3, 1, 1, 0),
(9, 3, 2, 1, 0),
(9, 3, 3, 1, 0),
(10, 4, 1, 1, 0),
(10, 4, 2, 1, 0),
(10, 4, 3, 1, 0),
(11, 20, 1, 1, 0),
(11, 20, 2, 1, 0),
(11, 20, 3, 1, 0),
(12, 22, 1, 1, 0),
(12, 22, 2, 1, 0),
(12, 22, 3, 1, 0),
(13, 23, 1, 1, 0),
(13, 23, 2, 1, 0),
(13, 23, 3, 1, 0),
(14, 6, 1, 1, 0),
(14, 6, 2, 1, 0),
(14, 6, 3, 1, 0),
(15, 3, 13, 1, 0),
(15, 3, 14, 1, 0),
(15, 3, 15, 1, 0),
(16, 10, 13, 1, 0),
(16, 10, 14, 1, 0),
(16, 10, 15, 1, 0),
(17, 9, 4, 1, 0),
(17, 9, 5, 1, 0),
(17, 9, 6, 1, 0),
(18, 21, 4, 1, 0),
(18, 21, 5, 1, 0),
(18, 21, 6, 1, 0),
(19, 17, 7, 1, 0),
(19, 17, 8, 1, 0),
(19, 17, 9, 1, 0),
(20, 18, 7, 1, 0),
(20, 18, 8, 1, 0),
(20, 18, 9, 1, 0),
(21, 3, 1, 1, 0),
(21, 3, 2, 1, 0),
(21, 3, 3, 1, 0),
(22, 4, 1, 1, 0),
(22, 4, 2, 1, 0),
(22, 4, 3, 1, 0),
(23, 6, 1, 1, 0),
(23, 6, 2, 1, 0),
(23, 6, 3, 1, 0),
(24, 3, 13, 1, 0),
(24, 3, 14, 1, 0),
(24, 3, 15, 1, 0),
(25, 10, 13, 1, 0),
(25, 10, 14, 1, 0),
(25, 10, 15, 1, 0),
(26, 12, 10, 1, 0),
(26, 12, 11, 1, 0),
(26, 12, 12, 1, 0),
(27, 12, 10, 1, 0),
(27, 12, 11, 1, 0),
(27, 12, 12, 1, 0),
(28, 20, 10, 1, 0),
(28, 20, 11, 1, 0),
(28, 20, 12, 1, 0),
(29, 20, 10, 1, 0),
(29, 20, 11, 1, 0),
(29, 20, 12, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `room`
--

CREATE TABLE IF NOT EXISTS `room` (
  `room_no` int(11) NOT NULL,
  `type` varchar(20) NOT NULL,
  `room_name` varchar(20) NOT NULL,
  PRIMARY KEY (`room_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `room`
--

INSERT INTO `room` (`room_no`, `type`, `room_name`) VALUES
(1, 'LT', 'LT-18'),
(2, 'TR', 'TR-5'),
(3, 'TR', 'TR-6'),
(4, 'HW', 'demp lab'),
(5, 'SW', 'sw1'),
(6, 'SW', 'SW2'),
(7, 'SW', 'ISEA'),
(8, 'SW', 'NW'),
(9, 'SW', 'PROJECT LAB'),
(10, 'LT', 'LT19'),
(11, 'LT', 'SH'),
(12, 'SW', 'IP');

-- --------------------------------------------------------

--
-- Table structure for table `subject`
--

CREATE TABLE IF NOT EXISTS `subject` (
  `s_id` int(11) NOT NULL,
  `name` varchar(20) NOT NULL,
  `no_of_lectures` int(11) NOT NULL,
  `no_of_labs` int(11) NOT NULL,
  `lab_room_type` varchar(20) NOT NULL,
  `no_of_tut` int(11) NOT NULL,
  PRIMARY KEY (`s_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `subject`
--

INSERT INTO `subject` (`s_id`, `name`, `no_of_lectures`, `no_of_labs`, `lab_room_type`, `no_of_tut`) VALUES
(1, 'DAA', 3, 0, '', 0),
(2, 'Neural nw', 3, 0, '', 0),
(3, 'Soft. Engg', 3, 0, '', 0),
(4, 'SE', 3, 0, '', 0),
(5, 'Compilers', 3, 0, '', 0),
(6, 'FOS lab', 0, 0, '', 0),
(7, 'FOS lab', 0, 0, '', 0),
(8, 'MMT', 3, 0, '', 0),
(9, 'DSA', 3, 0, '', 1),
(10, 'DLD', 3, 0, '', 1),
(11, 'LIC', 3, 0, '', 0),
(12, 'EC dept', 3, 0, '', 0),
(13, 'eff. comm.', 3, 0, '', 1),
(14, 'PM', 3, 0, '', 0),
(15, 'pattern recog.', 3, 0, '', 0),
(16, 'distributed sys', 3, 0, '', 0),
(17, 'DAA', 0, 1, 'SW', 0),
(18, 'Neural nw', 0, 1, 'SW', 0),
(19, 'Compilers', 0, 1, 'SW', 0),
(20, 'MMT', 0, 1, 'SW', 0),
(21, 'DSA', 0, 1, 'SW', 0),
(22, 'DLD', 0, 1, 'HW', 0),
(23, 'PM', 0, 1, 'SW', 0),
(24, 'pattern recog.', 0, 1, 'SW', 0),
(25, 'distributed sys', 0, 1, 'SW', 0),
(26, 'nw security', 3, 0, '', 0),
(27, 'nw security lab', 0, 1, 'SW', 0),
(28, 'evolving arch.', 3, 0, '', 0),
(29, 'evolving arch. lab', 0, 1, 'SW', 0);

-- --------------------------------------------------------

--
-- Table structure for table `teacher`
--

CREATE TABLE IF NOT EXISTS `teacher` (
  `t_id` int(11) NOT NULL,
  `name` varchar(20) NOT NULL,
  PRIMARY KEY (`t_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `teacher`
--

INSERT INTO `teacher` (`t_id`, `name`) VALUES
(1, 'Namita Mittal'),
(2, 'M. S. Gaur'),
(3, 'Vijaylaxmi'),
(4, 'G. S.'),
(5, 'yogesh meena'),
(6, 'Dinesh Tyagi'),
(7, 'Dinesh Goplani'),
(8, 'Emmanuel pillie'),
(9, 'Sakshi'),
(10, 'Mushtaq Ahmed'),
(11, 'Rekha'),
(12, 'R. batula'),
(13, 'Neeta nain'),
(14, 'Meenakshi Tripathi'),
(15, 'APM'),
(16, 'Nitin'),
(17, 'vijay'),
(18, 'sonia'),
(19, 'monika'),
(20, 'ESP'),
(21, 'ankit'),
(22, 'EC teacher'),
(23, 'eff. comm. techer');

-- --------------------------------------------------------

--
-- Table structure for table `t_hour`
--

CREATE TABLE IF NOT EXISTS `t_hour` (
  `t_id` int(11) NOT NULL,
  `day` varchar(20) NOT NULL DEFAULT '',
  `hour` int(11) DEFAULT '0',
  PRIMARY KEY (`t_id`,`day`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
