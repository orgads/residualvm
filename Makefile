
#######################################################################
# Default compilation parameters. Normally don't edit these           #
#######################################################################

srcdir      ?= .

DEFINES     := -DHAVE_CONFIG_H
LDFLAGS     := 
INCLUDES    := -I. -I$(srcdir) -I$(srcdir)/engines
LIBS        := 
OBJS        :=
DEPDIR      := .deps

MODULES     :=
MODULE_DIRS :=

# Load the make rules generated by configure
-include config.mk

ifeq "$(HAVE_GCC)" "1"
	CXXFLAGS:= -Wall $(CXXFLAGS)
	# Turn off some annoying and not-so-useful warnings
	CXXFLAGS+= -Wno-long-long -Wno-multichar -Wno-unknown-pragmas -Wno-reorder
	# Enable even more warnings...
	CXXFLAGS+= -Wpointer-arith -Wcast-qual
	CXXFLAGS+= -Wshadow -Wnon-virtual-dtor -Wwrite-strings

	# Currently we disable this gcc flag, since it will also warn in cases,
	# where using GCC_PRINTF (means: __attribute__((format(printf, x, y))))
	# is not possible, thus it would fail compiliation with -Werror without
	# being helpful.
	#CXXFLAGS+= -Wmissing-format-attribute

	# Disable exceptions.
	CXXFLAGS+= -fno-exceptions

ifneq "$(HAVE_CLANG)" "1"
	# enable checking of pointers returned by "new", but only when we do not
	# build with clang
	CXXFLAGS+= -fcheck-new
endif
endif

ifeq "$(HAVE_CLANG)" "1"
	CXXFLAGS+= -Wno-conversion -Wno-shorten-64-to-32 -Wno-sign-compare -Wno-four-char-constants
	# We use a anonymous nested type declaration in an anonymous union in
	# common/str.h. This is no standard construct and clang warns about it.
	# It works for all our target systems though, thus we simply disable that
	# warning.
	CXXFLAGS+= -Wno-nested-anon-types
	# ResidualVM: added -Wno-global-constructors
	CXXFLAGS+= -Wno-global-constructors
endif

ifeq "$(HAVE_ICC)" "1"
	# Disable some warnings:
	#  161: unrecognized #pragma
	# 1899: multicharacter character literal (potential portability problem)
	CXXFLAGS+= -diag-disable 161,1899
endif

#######################################################################
# Default commands - put the necessary replacements in config.mk      #
#######################################################################

CAT     ?= cat
CP      ?= cp
ECHO    ?= printf
INSTALL ?= install
MKDIR   ?= mkdir -p
RM      ?= rm -f
RM_REC  ?= $(RM) -r
ZIP     ?= zip -q

#######################################################################
# Misc stuff - you should never have to edit this                     #
#######################################################################

EXECUTABLE  := $(EXEPRE)residualvm$(EXEEXT)

include $(srcdir)/Makefile.common

ENGINE_SUBDIRS_CONFIGURE := $(wildcard $(srcdir)/engines/*/configure.engine)

config.h:
SAVED_ENV_VARS = AR AS ASFLAGS CPPFLAGS CXX CXXFLAGS LD LDFLAGS RANLIB SDL_CONFIG STRIP WINDRES WINDRESFLAGS

# The environment variable PKG_CONFIG_LIBDIR has a different meaning
# for pkg-config when it is empty and when it is not defined.
# When PKG_CONFIG_LIBDIR is defined but empty, the .pc files cannot
# be found because the search path is empty.
# Here we make sure not to define PKG_CONFIG_LIBDIR when automatically
# running configure and it was not set for the previous run
# so pkg-config uses the system default search path for the .pc files.
ifneq ($(SAVED_PKG_CONFIG_LIBDIR),unset)
	SAVED_ENV_VARS += PKG_CONFIG_LIBDIR
endif

# check if configure has been run or has been changed since last run
config.h: $(srcdir)/configure $(ENGINE_SUBDIRS_CONFIGURE)
ifeq "$(findstring config.mk,$(MAKEFILE_LIST))" "config.mk"
	@echo "Running $(srcdir)/configure with the last specified parameters"
	@sleep 2

	$(foreach VAR,$(SAVED_ENV_VARS),$(VAR)="$(SAVED_$(VAR))") \
		$(srcdir)/configure $(SAVED_CONFIGFLAGS)
else
	$(error You need to run $(srcdir)/configure before you can run make. Check $(srcdir)/configure --help for a list of parameters)
endif

config.mk engines/plugins_table.h engines/engines.mk: config.h
	@if test -f $@; then \
		touch $@; \
	else \
		rm -f config.h; \
		$(MAKE) config.h; \
	fi

ifneq ($(origin port_mk), undefined)
include $(srcdir)/$(port_mk)
endif

.PHONY: print-dists print-executables print-version print-distversion
print-dists:
	@echo $(DIST_FILES_DOCS) $(DIST_FILES_THEMES) $(DIST_FILES_NETWORKING) $(DIST_FILES_VKEYBD) $(DIST_FILES_ENGINEDATA) $(DIST_FILES_PLATFORM) $(srcdir)/doc

print-executables:
	@echo $(if $(DIST_EXECUTABLES),$(DIST_EXECUTABLES),$(EXECUTABLE) $(PLUGINS))

print-version:
	@echo $(VERSION)

print-distversion:
	@echo $(DISTVERSION)
