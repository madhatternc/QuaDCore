ALTER TABLE npc_spellclick_spells
  ADD COLUMN quest_status tinyint(1) unsigned NOT NULL default '0' AFTER quest_id;

CREATE TABLE `npc_spellclick_spells` (
    `npc_entry` INT UNSIGNED NOT NULL COMMENT 'reference to creature_template',
    `spell_id` INT UNSIGNED NOT NULL COMMENT 'spell which should be casted ',
    `quest_id` INT UNSIGNED NOT NULL COMMENT 'reference to quest_template',
    `cast_flags` TINYINT UNSIGNED NOT NULL COMMENT 'first bit defines caster: 1=player, 0=creature; second bit defines target, same mapping as caster bit'
) ENGINE = MYISAM DEFAULT CHARSET=utf8;

UPDATE `item_template` SET `scriptname` = 'item_jeremiahs_tools' WHERE `entry` = '35943';
UPDATE `item_template` SET `scriptname` = 'item_blood_gem' WHERE `entry` = '36827';
UPDATE `item_template` SET `scriptname` = 'item_frost_gem' WHERE `entry` = '36847';
UPDATE `item_template` SET `scriptname` = 'item_unholy_gem' WHERE `entry` = '36835';
UPDATE `item_template` SET `scriptname` = 'item_scepter_of_domination' WHERE `entry` = '39664';
UPDATE `item_template` SET `scriptname` = 'item_dart_gun' WHERE `entry` = '44222';
UPDATE `creature_template` SET `ScriptName`='npc_dragonflayer_forge_master' WHERE `entry` =24079;
DELETE FROM spell_proc_event WHERE entry IN (30299,30301,30302);
INSERT INTO spell_proc_event VALUES (30299, 0x0000007E,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000,  0);
INSERT INTO spell_proc_event VALUES (30301, 0x0000007E,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000,  0);
INSERT INTO spell_proc_event VALUES (30302, 0x0000007E,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0.000000, 0.000000,  0);




