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

TOP_DIR=utility
BGQ_BIN_INSTALL_DIR=$(BGQ_INSTALL_DIR)/$(TOP_DIR)/etc


.PHONY: default all clean distclean


default: all



install_targets=${install_parts:%=$(BGQ_BIN_INSTALL_DIR)/%}


dpm.properties: dpm.properties.template
	sed -e "s/%%BGQDB_DBNAME%%/$(BGQDB_DBNAME)/" $< | \
	sed -e "s/%%BGQDB_USER%%/$(BGQDB_USER)/" | \
	sed -e "s/%%BGQDB_PWD%%/$(BGQDB_PWD)/" | \
	sed -e "s/%%BGQDB_SCHEMA%%/$(BGQDB_SCHEMA)/" | \
	sed -e "s,%%BGQ_INSTALL_DIR%%,$(BGQ_INSTALL_DIR)," | \
	sed -e "s,%%CERTIFICATE_DIR%%,$(BGQ_INSTALL_DIR)/etc/security," > $@


%.tpl: %
	$(CP) $< $@

all: dpm.properties


clean:
	$(RM) dpm.properties

distclean: clean

install:
	install -d $(ETCDIR)
	install -m 755 dpm.properties $(ETCDIR)


uninstall:
	$(RM) $(etc_install_dir)/dpm.properties.tpl
	$(RM) $(etc_install_dir)/dpm.bringup.properties.tpl
