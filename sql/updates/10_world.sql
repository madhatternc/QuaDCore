DELETE FROM `command` WHERE `name` IN ('go taxinode','lookup taxinode');

INSERT INTO `command` VALUES
('go taxinode',1,'Syntax: .go taxinode #taxinode\r\n\r\nTeleport player to taxinode coordinates. You can look up zone using .lookup taxinode $namepart'),
('lookup taxinode',3,'Syntax: .lookup taxinode $substring\r\n\r\nSearch and output all taxinodes with provide $substring in name.');

DELETE FROM quad_string WHERE entry IN(347,466,1128,1129);
INSERT INTO quad_string VALUES
(347,'TaxiNode ID %u not found!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(466,'No taxinodes found!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1128,'%d - |cffffffff|Htaxinode:%u|h[%s %s]|h|r (Map:%u X:%f Y:%f Z:%f)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(1129,'%d - %s %s (Map:%u X:%f Y:%f Z:%f)',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM spell_proc_event WHERE entry = 34074;
INSERT INTO spell_proc_event VALUES (34074, 0, 9, 522819, 8917121, 513, 0, 0, 0, 0, 0);
