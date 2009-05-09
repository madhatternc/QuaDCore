ALTER TABLE character_achievement
  CHANGE COLUMN guid guid int(11) unsigned NOT NULL,
  CHANGE COLUMN achievement achievement int(11) unsigned NOT NULL,
  CHANGE COLUMN date date bigint(11) unsigned NOT NULL default '0';

