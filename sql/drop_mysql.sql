REVOKE ALL PRIVILEGES ON * . * FROM 'quad'@'localhost';

REVOKE ALL PRIVILEGES ON `QuadCore` . * FROM 'quad'@'localhost';

REVOKE GRANT OPTION ON `QuadCore` . * FROM 'quad'@'localhost';

REVOKE ALL PRIVILEGES ON `characters` . * FROM 'quad'@'localhost';

REVOKE GRANT OPTION ON `characters` . * FROM 'quad'@'localhost';

REVOKE ALL PRIVILEGES ON `logon` . * FROM 'quad'@'localhost';

REVOKE GRANT OPTION ON `logon` . * FROM 'quad'@'localhost';

DELETE FROM `user` WHERE CONVERT( User USING utf8 ) = CONVERT( 'quad' USING utf8 ) AND CONVERT( Host USING utf8 ) = CONVERT( 'localhost' USING utf8 ) ;

DROP DATABASE IF EXISTS `world` ;

DROP DATABASE IF EXISTS `characters` ;

DROP DATABASE IF EXISTS `logon` ;

