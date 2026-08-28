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
# (C) Copyright IBM Corp.  2010, 2011
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

DIRS  = $(subst /Makefile,,$(wildcard */Makefile))

ifeq ($(BGQ_HOST_OS),x86_64)
# test directory has a dependency on boost not installed on x86 processors
DIRS    := $(filter-out test,$(DIRS))
endif


TARGETS_ALL		= $(addsuffix .all,$(DIRS))
TARGETS_CLEAN		= $(addsuffix .clean,$(DIRS))
TARGETS_DISTCLEAN	= $(addsuffix .distclean,$(DIRS))
TARGETS_INSTALL         = src

TARGETS  = $(TARGETS_ALL)
TARGETS += $(TARGETS_CLEAN)
TARGETS += $(TARGETS_DISTCLEAN)


doxygen_version := $(subst 1.7,1.6,$(findstring 1.6, $(shell doxygen --version))$(findstring 1.7, $(shell doxygen --version)))
required_doxygen_version := 1.6


.PHONY: default all clean distclean docs $(TARGETS)


# make the all also do an install so the top level default make works
all:  $(TARGETS_ALL)


install:
	$(MAKE) --directory etc install
	$(MAKE) --directory src install
	install -d $(SBINDIR)
	install -m 755 src/generate_security_certificates.sh \
	    $(SBINDIR)/dpm-generate-certificates

clean:			$(TARGETS_CLEAN) docs.clean
distclean:	clean   $(TARGETS_DISTCLEAN)


$(TARGETS)::
	$(MAKE) --directory $(basename $@) $(subst .,,$(suffix $@))

docs.clean:
	$(RM) doxygen.out


doxygen.out:
ifeq ($(doxygen_version),$(required_doxygen_version))
	@echo "generating documentation"
	$(MKDIR) -p $(DPM_BUILD_DIR)/utility/docs
	$(CP) docs/verbose.html $(DPM_BUILD_DIR)/utility/docs
	$(CP) docs/verbose.man $(DPM_BUILD_DIR)/utility/docs
	cat docs/Doxyfile | sed 's:!OUTPUT_DIR!:$(DPM_BUILD_DIR)/utility/docs:' | doxygen - > $@
	sed -e 's^@DRIVER@^$(DPM_BUILD_DIR)^' < docs/main_index.html > $(DPM_BUILD_DIR)/utility/docs/main_index.html
else
	@echo "Will not generate docs because doxygen version is" $(shell doxygen --version) "and required version is" $(required_doxygen_version)
	@touch $@
endif


docs: doxygen.out
