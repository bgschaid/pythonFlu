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


#-----------------------------------------------------------------
def createSolidMeshes( rp, runTime ):
    
    from Foam.finiteVolume import PtrList_fvMesh, fvMesh
    solidRegions = PtrList_fvMesh( rp.solidRegionNames.size() )
    
    from Foam.OpenFOAM import word, fileName, IOobject
    for index in range( solidRegions.size() ):
        from Foam.OpenFOAM import ext_Info, nl
        ext_Info()<< "Create solid mesh for region " << rp.solidRegionNames[ index ] \
            << " for time = " << runTime.timeName() << nl << nl
        
        solidRegions.ext_set(index, fvMesh( IOobject ( word( rp.solidRegionNames[ index ] ),
                                                       fileName( runTime.timeName() ),
                                                       runTime,
                                                       IOobject.MUST_READ ) ) )
        pass
    
    return solidRegions


#---------------------------------------------------------------------
def createSolidField( solidRegions, runTime ):

    #Initialise solid field pointer lists
    from Foam.finiteVolume import PtrList_volScalarField, volScalarField
    rhos = PtrList_volScalarField( solidRegions.size() )
    cps = PtrList_volScalarField( solidRegions.size() )
    rhosCps = PtrList_volScalarField( solidRegions.size() )
    Ks = PtrList_volScalarField( solidRegions.size() )
    Ts = PtrList_volScalarField( solidRegions.size() )
    
    from Foam.OpenFOAM import ext_Info, nl
    
    #Populate solid field pointer lists    
    from Foam.OpenFOAM import word, IOobject, fileName
    for index in range( solidRegions.size() ):
        ext_Info()<< "*** Reading solid mesh thermophysical properties for region " \
            << solidRegions[ index ].name() << nl << nl

        ext_Info()<< "    Adding to rhos\n" << nl
        tmp = volScalarField( IOobject ( word( "rho" ), 
                                         fileName( runTime.timeName() ), 
                                         solidRegions[ index ], 
                                         IOobject.MUST_READ, 
                                         IOobject.AUTO_WRITE ),
                              solidRegions[ index ] ) 
        rhos.ext_set( index, tmp )
        
        ext_Info()<< "    Adding to cps\n" << nl
        tmp = volScalarField( IOobject( word( "cp" ),
                                        fileName( runTime.timeName() ),
                                        solidRegions[ index ],
                                        IOobject.MUST_READ,
                                        IOobject.AUTO_WRITE ),
                              solidRegions[ index ] )
        cps.ext_set( index, tmp )
        
        rhosCps.ext_set( index, volScalarField( word( "rhosCps" ), rhos[ index ] * cps[ index ]  ) )
        
        ext_Info()<< "    Adding to Ks\n" << nl
        tmp = volScalarField( IOobject( word( "K" ),
                                        fileName( runTime.timeName() ),
                                        solidRegions[ index ],
                                        IOobject.MUST_READ,
                                        IOobject.AUTO_WRITE ),
                              solidRegions[ index ] )

        Ks.ext_set( index,tmp )
        
        ext_Info()<< "    Adding to Ts\n" << nl
        tmp = volScalarField( IOobject( word( "T" ),
                                        fileName( runTime.timeName() ),
                                        solidRegions[ index ],
                                        IOobject.MUST_READ,
                                        IOobject.AUTO_WRITE ),
                              solidRegions[ index ] )
        
        Ts.ext_set( index, tmp )
   
    return rhos, cps, rhos, Ks, Ts


#-----------------------------------------------------------------------------------------------------
def readSolidMultiRegionPIMPLEControls( mesh ):
    from Foam.OpenFOAM import word
    pimple = mesh.solutionDict().subDict( word( "PIMPLE" ) )
    nNonOrthCorr = pimple.lookupOrDefault( word( "nNonOrthogonalCorrectors" ), 0 )
    
    return pimple, nNonOrthCorr


#-------------------------------------------------------------------------------------------------------
def setRegionSolidFields( i, solidRegions, rhos, cps, Ks, Ts ):
    mesh = solidRegions[ i ]
    rho = rhos[ i ]
    cp = cps[ i ]
    K = Ks[ i ]
    T = Ts[ i ]
    
    return mesh, rho, cp, K, T


#-------------------------------------------------------------------------------------------------------
def solveSolid( mesh, rho, cp, K, T, nNonOrthCorr ):
    for index in range( nNonOrthCorr + 1 ):
       from Foam import fvm
       TEqn = fvm.ddt( rho * cp, T ) - fvm.laplacian( K, T )
       TEqn.relax()
       TEqn.solve()
       pass
    from Foam.OpenFOAM import ext_Info, nl   
    ext_Info()<< "Min/max T:" << T.ext_min() << ' ' << T.ext_max() << nl
    
    pass
