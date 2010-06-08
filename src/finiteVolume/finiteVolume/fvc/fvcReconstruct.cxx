//  VulaSHAKA (Simultaneous Neutronic, Fuel Performance, Heat And Kinetics Analysis)
//  Copyright (C) 2009-2010 Pebble Bed Modular Reactor (Pty) Limited (PBMR)
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//  See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka/pyfoam
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef fvcReconstruct_cxx
#define fvcReconstruct_cxx

//---------------------------------------------------------------------------
// Keep on corresponding "director" includes at the top of SWIG defintion file

%include "src/OpenFOAM/directors.hxx"

%include "src/finiteVolume/directors.hxx"


//----------------------------------------------------------------------------
%include "src/finiteVolume/fields/volFields/volFields.cxx"
%include "src/finiteVolume/fields/surfaceFields/surfaceFields.cxx"

%{
    #include "fvcSurfaceIntegrate.H"
    #include "fvcReconstruct.H"
%}


//---------------------------------------------------------------------------
%include "src/OpenFOAM/fields/tmp/tmp_surfaceVectorField.cxx"

%inline
{
  Foam::tmp< Foam::GeometricField< Foam::tensor, Foam::fvPatchField, Foam::volMesh > > fvc_reconstruct
     ( const Foam::GeometricField< Foam::vector, Foam::fvsPatchField, Foam::surfaceMesh >& ssf )
  {
    return Foam::fvc::reconstruct( ssf );
  }

}


//---------------------------------------------------------------------------
%include "src/OpenFOAM/fields/tmp/tmp_surfaceScalarField.cxx"

%inline
{
  Foam::tmp< Foam::GeometricField< Foam::vector, Foam::fvPatchField, Foam::volMesh > > fvc_reconstruct
     ( const Foam::GeometricField< Foam::scalar, Foam::fvsPatchField, Foam::surfaceMesh >& ssf )
  {
    return Foam::fvc::reconstruct( ssf );
  }
  
}


//---------------------------------------------------------------------------
%include "src/finiteVolume/fvMesh/fvMesh.cxx"
%include "src/finiteVolume/fields/fvPatchFields/zeroGradient/zeroGradientFvPatchFields.cxx"


%include "fvcReconstruct.H"



//---------------------------------------------------------------------------
#endif
