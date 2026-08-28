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
# (C) Copyright IBM Corp.  2011, 2011
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

INSTALL_DIR=$(DPM_BUILD_DIR)/xml/scripts
PYSCRIPTS = $(wildcard *.py)
INSTALL_TARGETS = $(addprefix $(DPM_BUILD_DIR)/xml/scripts/, $(PYSCRIPTS))

.PHONY: default all install clean distclean

default: all

all:
	@echo "Nothing to build in xml/include/scripts"

$(INSTALL_DIR):
	mkdir -p $(INSTALL_DIR)

$(INSTALL_TARGETS): $(PYSCRIPTS) | $(INSTALL_DIR)
	$(CP) $(notdir $@) $@

install: $(PYSCRIPTS) $(INSTALL_TARGETS)

clean:
	$(RM) -r $(INSTALL_DIR)

distclean: clean
