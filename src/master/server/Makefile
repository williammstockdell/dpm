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

CXXFLAGS += \
 -isystem $(DPM_BUILD_DIR) \
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
 -L $(DPM_BUILD_DIR)/utility/src/cxxsockets -lcxxsockets \
 -L $(DPM_BUILD_DIR)/utility/src/ -lbgutility \
 -Wl,-rpath,$(DPM_BUILD_DIR)/utility/lib \
 -L $(DPM_BUILD_DIR)/xml/src/library -lXML \
 -Wl,-rpath,$(DPM_BUILD_DIR)/xml/lib \
 -Wl,-rpath,$(DPM_BUILD_DIR)/xml/lib \
 -llog4cxx \
 -lexpat\
 -lssl \
 -lcrypto

common_parts := \
 ArgParse

parts := \
 AgentManager \
 AgentRep \
 Alias \
 AliasList \
 Behavior \
 dpm_server \
 ClientController \
 ClientManager \
 MasterController \
 Registrar \

objs := ${parts:%=%.o}

common_parts := \
 AgentBase \
 BinaryController \
 Ids \
 ArgParse \
 Protocol

common_objs := ${common_parts:%=../common/%.o}

protocol_parts := \
 BGMasterAgentProtocolSpec \
 BGMasterClientProtocolSpec

protocol_objs := ${protocol_parts:%=../protocol/%.o}


exe := dpm_server
bg_sbin_links = $(exe)


default: all

all: $(exe)

$(exe): $(objs) $(common_objs) $(protocol_objs)
	$(CXX) -o $@ $^ $(LDFLAGS)

install:
	install -d $(SBINDIR)
	install -m 755 $(exe) $(SBINDIR)

clean:
	$(RM) *.o *.d $(exe)
	$(RM) ras_scan

distclean: clean


.PHONY: default all install clean distclean

-include *.d
