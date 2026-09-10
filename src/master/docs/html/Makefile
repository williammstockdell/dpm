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

# ===============================================================#
#                                                                  #
# Modifications Copyright (C) Will Stockdell 2026                  #
#                                                                  #
# Modifications to this file are made available under the          #
# Eclipse Public License (EPL) version 1.0.                        #
#                                                                  #
# ================================================================ #

include ../../../../Make.hlcs.rules

clean:
	rm -f doxygen.out


distclean: clean

INSTALL_DIR = $(DPM_INSTALL_DIR)/docs/master

IMAGE = Alias_etc.png

$(INSTALL_DIR):
	mkdir -p $@

$(INSTALL_DIR)/%: % | $(INSTALL_DIR)
	install -m 644 $< $@

install: docs $(INSTALL_DIR)/$(IMAGE)

uninstall:
	rm -rf $(DPM_BUILD_DIR)/docs/master

doxygen_version := $(shell doxygen --version 2>/dev/null)
required_doxygen_version := 1.6
doxygen_version_ok := $(shell printf '%s\n%s\n' \
	$(required_doxygen_version) $(doxygen_version) | \
	sort -V | head -1)

docs: doxygen.out

all: docs

doxygen.out: Doxyfile | $(INSTALL_DIR)
ifeq ($(doxygen_version_ok),$(required_doxygen_version))
	@echo "generating documentation"
	cd ../../../../ && cat src/master/docs/html/$^ | sed 's:DPM_BUILD_DIR:$(DPM_BUILD_DIR):' | doxygen - > src/master/docs/html/doxygen.out
else
	@echo "Will not generate docs because doxygen version is" $(doxygen_version) "and minimum version is" $(required_doxygen_version)
	@touch $@
endif
