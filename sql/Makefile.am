# Copyright (C) 2009 QuadCore <http://github.com/QuaDCore/QuaDCore/tree/master>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## Process this file with automake to produce Makefile.in

## Sub-directories to parse
SUBDIRS = updates tools

## Change installation location
#  datadir = quad/sql
pkgdatadir = $(datadir)/quad/sql

## Files to be installed
#  Install basic SQL files to datadir
pkgdata_DATA = \
	world.sql \
	logon.sql \
	characters.sql \
	create_mysql.sql \
    world_scripts_full.sql \
    world_scripts_structure.sql \
	drop_mysql.sql \
	quadscript_script_texts.sql \
letter_analogs.txt \
innormative_words.txt

## Additional files to include when running 'make dist'
#  SQL files for QuadCore database
EXTRA_DIST = \
	create_mysql.sql \
	drop_mysql.sql \
	characters.sql \
	world.sql \
    world_scripts_full.sql \
    world_scripts_structure.sql \
	quadscript_script_texts.sql \
	logon.sql \
letter_analogs.txt \
innormative_words.txt