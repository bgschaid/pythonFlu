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


#------------------------------------------------------------------------------------
# To import corresponding plugin first
#from Foam.applications.solvers.heatTransfer.chtMultiRegionFoam import plugin
from Foam.applications.solvers.heatTransfer.r1_5.chtMultiRegionFoam import derivedFvPatchFields


#--------------------------------------------------------------------------------------
def main_standalone( argc, argv ):

    from Foam.OpenFOAM.include import setRootCase
    args = setRootCase( argc, argv )

    from Foam.OpenFOAM.include import createTime
    runTime = createTime( args )
    
    from Foam.applications.solvers.heatTransfer.r1_5.chtMultiRegionFoam import regionProperties
    rp = regionProperties( runTime )
    
    from Foam.applications.solvers.heatTransfer.r1_5.chtMultiRegionFoam.fluid import createFluidMeshes
    fluidRegions = createFluidMeshes( rp, runTime )
    
    from Foam.applications.solvers.heatTransfer.r1_5.chtMultiRegionFoam.solid import createSolidMeshes
    solidRegions = createSolidMeshes( rp, runTime )
    
    from Foam.applications.solvers.heatTransfer.r1_5.chtMultiRegionFoam.fluid import createFluidFields
    pdf, thermof, rhof, Kf, Uf, phif, turb, DpDtf, ghf, initialMass = createFluidFields( fluidRegions, runTime, rp )
    
    from Foam.applications.solvers.heatTransfer.r1_5.chtMultiRegionFoam.solid import createSolidField
    rhos, cps, rhos, Ks, Ts = createSolidField( solidRegions, runTime )
    
    ext_Info() << "End\n"
    
    import os
    return os.EX_OK

    
#--------------------------------------------------------------------------------------
argv = None
import sys, os

if os.environ[ "WM_PROJECT_VERSION" ] == "1.5" :
    if __name__ == "__main__" :
        argv = sys.argv
        
        if len(argv) > 1 and argv[ 1 ] == "-test":
           argv = None
           test_dir= os.path.join( os.environ[ "PYFOAM_TESTING_DIR" ],'cases', 'r1.5', 'heatTransfer', 'chtMultiRegionFoam', 'multiRegionHeater' )
           argv = [ __file__, "-case", test_dir ]
           pass
        
        os._exit( main_standalone( len( argv ), argv ) )
        
        pass
else:
    from Foam.OpenFOAM import ext_Info
    ext_Info() << "\n\n To use this solver, it is necessary to SWIG OpenFOAM-1.5 \n"    
    pass

