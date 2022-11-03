#!/bin/bash

cp extern/UEB/{canopy.cpp,matrixnvector.cpp,ncfunctions.cpp,snowdgtv.cpp,snowdv.cpp,snowxv.cpp,uebdecls.cpp,uebinputs.cpp} src/
cd src
make clean
make