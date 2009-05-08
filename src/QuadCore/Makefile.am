# Copyright (C) 2009 QuadCore <http://github.com/QuaDCore/QuaDCore/tree/master>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

## Process this file with automake to produce Makefile.in

## CPP flags for includes, defines, etc.
AM_CPPFLAGS = $(TRINI_INCLUDES) -I$(top_builddir)/src/shared -I$(srcdir)/../../dep/include -I$(srcdir)/../framework -I$(srcdir)/../shared  -I$(srcdir)/../game -I$(srcdir) -DSYSCONFDIR=\"$(sysconfdir)/\"

## Build world list daemon as standalone program
bin_PROGRAMS = quad-worldd
quad_worldd_SOURCES = \
    CliRunnable.cpp \
    CliRunnable.h \
    Main.cpp \
    Master.cpp \
    Master.h \
    RASocket.cpp \
    RASocket.h \
    WorldRunnable.cpp \
    WorldRunnable.h

## Link world daemon against the shared library
quad_worldd_LDADD = ../bindings/scripts/libquadscript.la ../game/libQuadCoregame.a ../shared/Database/libquadcoreatabase.a ../shared/Config/libQuadCoreconfig.a ../shared/Auth/libQuadCoreauth.a ../shared/libQuadCoreshared.a ../shared/vmap/libQuadCorevmaps.a ../framework/libQuadCoreframework.a ../../dep/src/sockets/libQuadCoresockets.a  ../../dep/src/zthread/libZThread.la ../../dep/src/g3dlite/libg3dlite.a
quad_worldd_LDFLAGS = -L../../dep/src/sockets -L../../dep/src/zthread -L../../dep/src/g3dlite -L../bindings/scripts/ -L$(libdir) $(TRINI_LIBS) -export-dynamic

## Additional files to include when running 'make dist'
#  Include world daemon configuration
EXTRA_DIST = \
    quadcore.conf.dist

## Additional files to install
sysconf_DATA = \
    quadcore.conf.dist

install-data-hook:
	@list='$(sysconf_DATA)'; for p in $$list; do \
      dest=`echo $$p | sed -e s/.dist//`; \
      if test -f $(DESTDIR)$(sysconfdir)/$$dest; then \
        echo "$@ will not overwrite existing $(DESTDIR)$(sysconfdir)/$$dest"; \
      else \
        echo " $(INSTALL_DATA) $$p $(DESTDIR)$(sysconfdir)/$$dest"; \
        $(INSTALL_DATA) $$p $(DESTDIR)$(sysconfdir)/$$dest; \
      fi; \
    done

clean-local:
	rm -f $(sysconf_DATA)
