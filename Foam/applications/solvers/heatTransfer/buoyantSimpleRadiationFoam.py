#!/usr/bin/env python

#--------------------------------------------------------------------------------------
## Copyright (C) 2009-2010 Pebble Bed Modular Reactor (Pty) Limited (PBMR)
## 
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
## 
## See https://csrcs.pbmr.co.za/svn/nea/prototypes/reaktor/pyfoam
##
## Author : Alexey PETROV
##


#--------------------------------------------------------------------------------------------
argv = None
import sys, os

from Foam import WM_PROJECT_VERSION

if WM_PROJECT_VERSION() == "1.5" :
    if __name__ == "__main__" :
        argv = sys.argv
        pass
    else :
        argv = None
        test_dir= os.path.join( os.environ[ "PYFOAM_TESTING_DIR" ],'cases', 'r1_5', 'heatTransfer', 'buoyantSimpleRadiationFoam', 'hotRadiationRoom' )
        argv = [ __file__, "-case", test_dir ]
        pass
    from Foam.applications.solvers.heatTransfer.r1_5.buoyantSimpleRadiationFoam import main_standalone
    os._exit( main_standalone( len( argv ), argv ) )
    pass

if WM_PROJECT_VERSION() >= "1.6":
    if __name__ == "__main__" :
        argv = sys.argv
        pass
    else :
        argv = None
        test_dir= os.path.join( os.environ[ "PYFOAM_TESTING_DIR" ],'cases', 'r1_6', 'heatTransfer', 'buoyantSimpleRadiationFoam', 'hotRadiationRoom' )
        argv = [ __file__, "-case", test_dir ]
        pass
    from Foam.applications.solvers.heatTransfer.r1_6.buoyantSimpleRadiationFoam import main_standalone
    os._exit( main_standalone( len( argv ), argv ) )
    pass
else:
    from Foam.OpenFOAM import ext_Info, nl
    ext_Info() <<"\n\n The use buoyantSimpleRadiationFoam It is necessary to SWIG OpenFOAM-1.5 or higher\n"    
    pass


#--------------------------------------------------------------------------------------

