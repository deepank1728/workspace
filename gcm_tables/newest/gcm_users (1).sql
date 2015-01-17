-- phpMyAdmin SQL Dump
-- version 4.0.9
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 06, 2014 at 02:32 AM
-- Server version: 5.6.14
-- PHP Version: 5.5.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `gcm`
--

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
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `gcm_users`
--

INSERT INTO `gcm_users` (`id`, `gcm_regid`, `name`, `email`, `created_at`) VALUES
(1, 'APA91bGnfGdRsPn6-g8hkmld0bygrQAsPWM-qHrOt5kg2A0p0Zw6fyr-vUJ6eyneUNFdaZTPguEGC-Gbou5uZvm3-atv84NSYANv8hCCdxjd-w3YZ5Cx_OIw0Vl1CS8YOc6aNdzmw7ohVUywIzmxvpcKWCPlKhLLjEofQy8s98QuOb7W2Pi6qK8', 'shub', 'shub@gmail.com', '2014-06-26 10:25:17'),
(2, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'xzvv', 'xvvzx', '2014-06-29 18:58:56'),
(3, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'xvxv', 'xvxv', '2014-06-29 19:45:30'),
(4, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'xv', 'xvvx', '2014-06-29 21:34:45'),
(5, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'xv', 'ssvs', '2014-06-29 21:58:07'),
(6, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'deepank', 'p', '2014-10-05 22:00:48'),
(7, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'deepank', 'deepank@gmail.com', '2014-10-05 22:17:05'),
(8, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'deep', 'deep@gmail.com', '2014-10-05 22:23:54'),
(9, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'shubh', 'shubh@gmail.com', '2014-10-05 22:27:44'),
(11, 'APA91bGM48TodOZpT4Cx_p9-JYE4fBlzdnEaStLaOZZWNjKxLjlLkRIfCCzzn9aA3GEe7BeKSEcjzowEIq2cpI4jni6iiXeMYRRHkdj8pHDFbr1j9UDBRZw9lXDOpRDbkW39EVEraFGWL5uCi5rqTxWoLztz29M9A-BKShyJ96RCdFP02I8gcs8', 'dp', 'dp', '2014-10-05 22:42:05');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
