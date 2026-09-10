# begin_generated_IBM_copyright_prolog
#
# This is an automatically generated copyright prolog.
# After initializing,  DO NOT MODIFY OR MOVE
# ================================================================
#
# Licensed Materials - Property of IBM
#
# Blue Gene/Q
#
# (C) Copyright IBM Corp.  2004, 2011
#
# US Government Users Restricted Rights -
# Use, duplication or disclosure restricted
# by GSA ADP Schedule Contract with IBM Corp.
#
# This software is available to you under the
# Eclipse Public License (EPL).
#
# ================================================================
#
# end_generated_IBM_copyright_prolog

# ===============================================================#
#                                                                  #
# Modifications Copyright (C) Will Stockdell 2026                  #
#                                                                  #
# Modifications to this file are made available under the          #
# Eclipse Public License (EPL) version 1.0.                        #
#                                                                  #
# ================================================================ #

include ../Make.hlcs.rules

DIRS  = docs
DIRS += master

TARGETS_ALL		= $(addsuffix .all,$(DIRS))
TARGETS_INSTALL		= $(addsuffix .install,$(DIRS))
TARGETS_CLEAN		= $(addsuffix .clean,$(DIRS))
TARGETS_DISTCLEAN	= $(addsuffix .distclean,$(DIRS))
TARGETS_UNINSTALL	= $(addsuffix .uninstall,$(DIRS))


TARGETS  = $(TARGETS_ALL)
TARGETS += $(TARGETS_INSTALL)
TARGETS += $(TARGETS_CLEAN)
TARGETS += $(TARGETS_DISTCLEAN)
TARGETS += $(TARGETS_UNINSTALL)


.PHONY: $(DIRS) clean docs install distclean


default:        all
all:            all $(TARGETS_ALL)

install:
	$(MAKE) --directory master install

clean:			$(TARGETS_CLEAN)
distclean:	clean   $(TARGETS_DISTCLEAN)
uninstall:              $(TARGETS_UNINSTALL)


# dependencies
ifeq ($(BGQDB),yes)
    mmcs.install: master.install security.install libmmcs_client.install
else
    mmcs.install: master.install libmmcs_client.install
endif
bgsched.install: security.install libmmcs_client.install
runjob.install: bgsched.install security.install
realtime.install: bgsched.install
validator.install: master.install mmcs.install

$(TARGETS):
	$(MAKE) --directory $(basename $@) $(subst .,,$(suffix $@))
