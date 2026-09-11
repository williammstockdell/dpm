# Building and Installing DPM
DPM releases come as a binary tarball and source distribution.  Unfortunately,
there are no .deb, .rpm, flatpack or any other binary distribution packages.
There's also no autoconf infrastructure.  Maybe for 2.0.  This means users
will need to satisfy dependencies on their own.  This will be easiest on
Ubuntu 24.04 where DPM was developed.

## Binary install
As root, copy the binary package to /usr, /usr/local, or preferably, /opt
and unpack.

### Dependencies
You'll need the following packages:
- liblog4cxx15
- libexpat1
- libssl3
- libapr1
- libaprutil1
- libstdc++6
- ca-certificates

That will create and populate bin, sbin, man, etc, lib and docs directories.
Make sure your environment's library path, manual path and path all refer
to the install location.

### Configuration

- You'll need to set up your SSL certificates.  There's an included script
 called dpm-generate-certiticates that can be used to generate self-signed certs.

- DPM is driven by a single configuration file called dpm.properties by default.
The location of the file can be specified on the command line for every
executable or via an environment variable, DPM_PROPERTIES_FILE.  By default,
it's expected in /opt/etc/dpm.properties.  A template/example file is installed
into the etc/ directory under the installation location.

## Building

### Accessing
You can get the code from a git clone of main or a release tag or you
can download the source distribution from GitHub.

### Dependencies
You'll need to
satisfy the following dependencies:
- g++-14
- build-essential
- liblog4cxx-dev
- libexpat1-dev
- libssl-dev
- libapr1-dev
- libaprutil1-dev
- libxml2-utils
- docbook-xml
- docbook-xsl
- xsltproc
- make
- ca-certificates

### Compile
From the top level, "make all" will build the source tree and documentation.
"make install" will create installation directories under the directory
specified as the DPM_INSTALL_DIR directory and copy binaries, libraries, man
pages, doxygen output and a config file template.

### Tests
"make test" from the top level directory will build the catch2 unit tests.  Catch2
itself is installed into the tree under test/.

There's a controlled environment for integration testing under test/integration.
You can build the docker container with the test/integration/Dockerfile and
use the bootstrap.sh script to start docker compose containers with a master
server and agents.

### Static analysis
"make check" runs cppcheck for static analysis.  That is an additional installation
dependency.

### Formatting
If you install clang-format, you can use the .clang-format tool to match the
code format style.
