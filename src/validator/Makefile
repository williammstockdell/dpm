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

include ../../Make.hlcs.rules

EXECS = properties_validate

CXXFLAGS += -O2
CXXFLAGS += -Wall
CXXFLAGS += -MD -MP
CXXFLAGS += -iquote $(DPM_BUILD_DIR)/src/master
CXXFLAGS += -isystem $(DPM_BUILD_DIR)
CXXFLAGS += -isystem $(DPM_BUILD_DIR)/utility/include
CXXFLAGS += -I$(DPM_BUILD_DIR)/src/master/protocol

LDFLAGS += -L $(DPM_BUILD_DIR)/utility/src/cxxsockets -lcxxsockets
LDFLAGS += -L $(DPM_BUILD_DIR)/utility/src/ -lbgutility
LDFLAGS += -L $(DPM_BUILD_DIR)/xml/src/library -lXML
LDFLAGS += -Wl,-rpath,'$$ORIGIN/../lib'
LDFLAGS += -llog4cxx
LDFLAGS += -lssl
LDFLAGS += -lcrypto

BGM_OBJS =
BGM_OBJS += ../master/common/AgentBase.o
BGM_OBJS += ../master/common/BinaryController.o
BGM_OBJS += ../master/server/AgentManager.o
BGM_OBJS += ../master/server/AgentRep.o
BGM_OBJS += ../master/server/Alias.o
BGM_OBJS += ../master/server/AliasList.o
BGM_OBJS += ../master/server/Behavior.o
BGM_OBJS += ../master/server/ClientController.o
BGM_OBJS += ../master/server/ClientManager.o
BGM_OBJS += ../master/common/Ids.o
BGM_OBJS += ../master/common/ArgParse.o
BGM_OBJS += ../master/server/MasterController.o
BGM_OBJS += ../master/common/Protocol.o
BGM_OBJS += ../master/server/Registrar.o

BGM_OBJS += ../master/protocol/BGMasterAgentProtocolSpec.o
BGM_OBJS += ../master/protocol/BGMasterClientProtocolSpec.o

INSTALL_LIST += $(call INSTALL_BIN_TARGET, $(EXECS))

bg_bin_links := $(EXECS)

.PHONY: clean docs install distclean all

all: $(EXECS)

install:
	cp properties_validate $(BINDIR)/

clean:
	$(RM) $(INSTALL_LIST)
	$(RM) *.o
	$(RM) *.d
	$(RM) $(EXECS)
	$(RM) test

distclean:	clean

properties_validate: properties_validate.o $(BGM_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

test: properties_validate
	./$^ $(DPM_BUILD_DIR)/utility/etc/bg.properties.ship.tpl
	@touch $@

-include *.d
