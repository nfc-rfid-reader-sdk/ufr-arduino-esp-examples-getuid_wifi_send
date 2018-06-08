-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               10.1.28-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win32
-- HeidiSQL Version:             9.5.0.5196
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Dumping structure for view ufr.accepted
-- Creating temporary table to overcome VIEW dependency errors
CREATE TABLE `accepted` (
	`UID` VARCHAR(50) NOT NULL COLLATE 'latin1_swedish_ci',
	`NAME` VARCHAR(50) NOT NULL COLLATE 'latin1_swedish_ci',
	`SN` VARCHAR(50) NOT NULL COLLATE 'latin1_swedish_ci',
	`DATE_TIME` DATETIME NOT NULL
) ENGINE=MyISAM;

-- Dumping structure for view ufr.denied
-- Creating temporary table to overcome VIEW dependency errors
CREATE TABLE `denied` (
	`UID` VARCHAR(50) NOT NULL COLLATE 'latin1_swedish_ci',
	`SN` VARCHAR(50) NOT NULL COLLATE 'latin1_swedish_ci',
	`DATE_TIME` DATETIME NOT NULL
) ENGINE=MyISAM;

-- Dumping structure for table ufr.log
CREATE TABLE IF NOT EXISTS `log` (
  `LOG_ID` int(11) NOT NULL AUTO_INCREMENT,
  `SN` varchar(50) NOT NULL DEFAULT '0',
  `UID` varchar(50) NOT NULL DEFAULT '0',
  `CTRLINFO` int(11) NOT NULL DEFAULT '0',
  `DATE_TIME` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`LOG_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=276 DEFAULT CHARSET=latin1;

-- Data exporting was unselected.
-- Dumping structure for table ufr.whitelist
CREATE TABLE IF NOT EXISTS `whitelist` (
  `UID` varchar(50) NOT NULL,
  `NAME` varchar(50) NOT NULL,
  PRIMARY KEY (`UID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- Data exporting was unselected.
-- Dumping structure for view ufr.accepted
-- Removing temporary table and create final VIEW structure
DROP TABLE IF EXISTS `accepted`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `accepted` AS SELECT whitelist.UID, whitelist.NAME, log.SN, log.DATE_TIME FROM whitelist,log WHERE whitelist.UID=log.UID ;

-- Dumping structure for view ufr.denied
-- Removing temporary table and create final VIEW structure
DROP TABLE IF EXISTS `denied`;
CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `denied` AS SELECT log.UID, log.SN , log.DATE_TIME FROM log WHERE log.UID not in(SELECT UID FROM whitelist) ;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
