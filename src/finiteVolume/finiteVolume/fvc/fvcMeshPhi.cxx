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
//  See https://vulashaka.svn.sourceforge.net/svnroot/vulashaka
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef fvcMeshPhi_cxx
#define fvcMeshPhi_cxx


//---------------------------------------------------------------------------
%module "Foam.src.finiteVolume.finiteVolume.fvc.fvcMeshPhi";
%{
  #include "src/finiteVolume/finiteVolume/fvc/fvcMeshPhi.hpp"
%}


//---------------------------------------------------------------------------
%import "src/finiteVolume/fields/volFields/volScalarField.cxx"

%import "src/finiteVolume/fields/volFields/volVectorField.cxx"

%import "src/finiteVolume/fields/surfaceFields/surfaceScalarField.cxx"

%import "src/OpenFOAM/dimensionedTypes/dimensionedScalar.cxx"


//---------------------------------------------------------------------------
%inline
{
  void 
  fvc_makeRelative( Foam::surfaceScalarField& phi,
                    const Foam::volVectorField& U )
  {
    Foam::fvc::makeRelative( phi, U);
  }
    
  void 
  fvc_makeRelative( Foam::surfaceScalarField& phi,
                    const Foam::dimensionedScalar& rho,
                    const Foam::volVectorField& U )
  {
    Foam::fvc::makeRelative( phi, rho, U );
  }
  
  void 
  fvc_makeRelative( Foam::surfaceScalarField& phi,
                    const Foam::volScalarField& rho,
                    const Foam::volVectorField& U )
  { 
    Foam::fvc::makeRelative( phi, rho, U );
  }
    
  void
  fvc_makeAbsolute( Foam::surfaceScalarField& phi,
                    const Foam::volVectorField& U )
  {
    Foam::fvc::makeAbsolute( phi, U );
  }
    
  void
  fvc_makeAbsolute( Foam::surfaceScalarField& phi,
                    const Foam::dimensionedScalar& rho,
                    const Foam::volVectorField& U )
  {
    Foam::fvc::makeAbsolute( phi, rho, U );
  }
    
  void
  fvc_makeAbsolute( Foam::surfaceScalarField& phi,
                    const Foam::volScalarField& rho,
                    const Foam::volVectorField& U )
  {
    Foam::fvc::makeAbsolute( phi, rho, U );
  }
}


//---------------------------------------------------------------------------
%include <fvcMeshPhi.H>


//---------------------------------------------------------------------------
#endif
