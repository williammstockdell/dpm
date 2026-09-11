# Introduction
DPM, Distributed Process Manager is a tool for starting, stopping, running and monitoring processes on remote hosts in
small clusters.  It's based on a tool included with IBM's BlueGene/Q control system for managing control nodes for the BG/Q
super computer.  DPM is released under the EPL 1.0, the same license used by the original code.  DPM is not maintained,
or contributed to by IBM and IBM has no involvement in this distribution.

DPM has been updated from the original BG Master with the elimination of database dependencies, extrication from the rest
of the control system software, modernization of the code base by replacing boost with C++ 20 standards, and fixing janky formatting.
It has also been run through cppcheck, had basic unit tests added and an integration framework with composed Docker
containers.

## Licensing & Modifications
This project is a modernized fork of the IBM Blue Gene/Q codebase, distributed under the Eclipse Public License 1.0.

The original code is Copyright (c) 2010, 2011 IBM Corp.
All modernizations, modifications, and new contributions are Copyright (c) 2026 Will Stockdell.

Full, line-by-line identification of all modifications and author attributions is maintained transparently via the project's Git commit history (`git log`).
