## -*- automake -*-
## FILE: "/home/joze/src/tclreadline/Makefile.am"
## LAST MODIFICATION: "Fre, 08 Dez 2000 01:47:52 +0100 (joze)"
## (C) 2000 by Johannes Zellner, <johannes@zellner.org>
## $Id: Makefile.am,v 1.1.1.1 2002/02/28 21:23:50 kilsdonk Exp $
## ---
## tclreadline -- gnu readline for tcl
## http://www.zellner.org/tclreadline/
## Copyright (c) 1998 - 2000, Johannes Zellner <johannes@zellner.org>
## This software is copyright under the BSD license.
## ---

## AUTOMAKE_OPTIONS = foreign

lib_LTLIBRARIES = libtclreadline.la

libtclreadline_la_SOURCES = config.h tclreadline.c tclreadline.h
include_HEADERS = tclreadline.h

INCLUDES = -I$(TCL_INCLUDE_DIR) -I$(READLINE_INCLUDE_DIR)

## libtclreadline_la_LIBADD = $(LIBS)
libtclreadline_la_LDFLAGS = -release $(MAJOR).$(MINOR).$(PATCHLEVEL)

tclrldir = @TCLRL_DIR@
tclrl_SCRIPTS = pkgIndex.tcl tclreadlineCompleter.tcl tclreadlineInit.tcl tclreadlineSetup.tcl
INSTALL_SCRIPT = ${INSTALL_DATA}

EXTRA_DIST =                 \
    tclreadlineCompleter.tcl \
    aux/config.guess         \
    aux/config.sub           \
    aux/install-sh           \
    aux/ltconfig             \
    aux/ltmain.sh            \
    aux/missing              \
    aux/mkinstalldirs

if STATIC_TCLSHRL
static_tclshrl = tclshrl
tclshrl_LDADD = libtclreadline.la $(TCL_LIB_SPEC)
tclshrl_LDFLAGS = -static
endif

if STATIC_WISHRL
static_wishrl = wishrl
wishrl_LDADD = libtclreadline.la $(TCL_LIB_SPEC) $(TK_LIB_SPEC)
wishrl_LDFLAGS = -static
endif

bin_PROGRAMS = $(static_tclshrl) $(static_wishrl)
tclshrl_SOURCES = tclshrl.c
wishrl_SOURCES = wishrl.c

man_MANS = tclreadline.n

