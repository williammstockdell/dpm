#include "catch2/catch_amalgamated.hpp"
#include <netinet/tcp.h>
#include <utility/include/Properties.h>
#include <utility/include/cxxsockets/ListeningSocket.h>
#include <utility/include/cxxsockets/SockAddr.h>
#include <utility/include/cxxsockets/TCPSocket.h>


using namespace bgq::utility;
using namespace CxxSockets;

TEST_CASE( "default_ctor" )
{
    // open a listening socket
    SockAddr addr( AF_INET );
    ListeningSocket listen( addr );
    listen.getSockName( addr );
    CHECK( addr.getServicePort() != 0 );

    // connect to it
    TCPSocket client;
    client.Connect( addr );

    int flag;
    socklen_t length = sizeof(flag);
    const int ret = getsockopt( client.getFileDescriptor(), IPPROTO_TCP, TCP_NODELAY, &flag, &length );
    CHECK( ret == 0 );
    CHECK( flag == 1u );
}
