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
# (C) Copyright IBM Corp.  2012, 2012
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

include ../../../Make.hlcs.rules


TOP_DIR=hlcs
TOP_INSTALL_DIR=$(BGQ_INSTALL_DIR)/$(TOP_DIR)
MODULE_INIT_DIR=$(TOP_INSTALL_DIR)/etc/init


CXXFLAGS += \
 -isystem $(BGQ_INSTALL_DIR)/ \
 -iquote .. \
 -W \
 -Wall \
 -Wextra \
 -Wundef \
 -Wconversion \
 -O2 \
 -MD -MP \
 -pthread


LDFLAGS += \
 -L $(BGQ_INSTALL_DIR)/utility/src/cxxsockets -lcxxsockets \
 -L $(BGQ_INSTALL_DIR)/utility/src/ -lbgutility \
 -Wl,-rpath,$(BGQ_INSTALL_DIR)/utility/lib \
 -L $(BGQ_INSTALL_DIR)/xml/src/library -lXML \
 -Wl,-rpath,$(BGQ_INSTALL_DIR)/xml/lib \
 -llog4cxx \
 -lexpat \
 -lssl \
 -lcrypto

LDFLAGS  += -lboost_program_options


parts := \
 dpm_agentd \
 MasterConnection \
 Agent

objs := ${parts:%=%.o}

common_parts := \
 AgentBase \
 ArgParse \
 BinaryController \
 Ids \
 Protocol

common_objs := ${common_parts:%=../common/%.o}

protocol_parts := \
 BGMasterAgentProtocolSpec

protocol_objs := ${protocol_parts:%=../protocol/%.o}


exe := dpm_agentd
bg_sbin_links = $(exe)


default: all

all: $(exe)

install:
	install -d $(SBINDIR)
	install -m 755 $(exe) $(SBINDIR)


$(exe): $(objs) $(common_objs) $(protocol_objs)
	$(CXX) -o $@ $^ $(LDFLAGS)


$(MODULE_INIT_DIR):
	$(MKDIR) -p $@

$(MODULE_INIT_DIR)/%: % | $(MODULE_INIT_DIR)
	$(CP) $^ $@


clean:
	$(RM) *.o *.d dpm_agentd

distclean: clean


.PHONY: default all install clean distclean

-include *.d
