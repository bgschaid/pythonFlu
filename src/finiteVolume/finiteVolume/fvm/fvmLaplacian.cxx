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
#ifndef fvmLaplacian_cxx
#define fvmLaplacian_cxx


//---------------------------------------------------------------------------
%module "Foam.src.finiteVolume.finiteVolume.fvm.fvmLaplacian";
%{
  #include "src/finiteVolume/finiteVolume/fvm/fvmLaplacian.hh"
%}


//---------------------------------------------------------------------------
%import "src/finiteVolume/fvMesh/fvMeshes.cxx"

%import "src/finiteVolume/fvMatrices/fvMatrices.cxx"

%import "src/OpenFOAM/dimensionedTypes/dimensionedScalar.cxx"


//---------------------------------------------------------------------------
%define FVM_LAPLACIAN_TEMPLATE_FUNC( Type )
%{
  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf,
                 const Foam::word& name )
  {
    return Foam::fvm::laplacian( vf, name );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf )
  {
    return Foam::fvm::laplacian( vf );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( const Foam::dimensionedScalar& gamma,
                 Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf,
                 const Foam::word& name )
  {
    return Foam::fvm::laplacian( gamma, vf, name );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( const Foam::dimensionedScalar& gamma,
                 Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf )
  {
    return Foam::fvm::laplacian( gamma, vf );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( const Foam::volScalarField& gamma,
                 Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf,
                 const Foam::word& name )
  {
    return Foam::fvm::laplacian( gamma, vf, name );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( const Foam::volScalarField& gamma,
                 Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf )
  {
    return Foam::fvm::laplacian( gamma, vf );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( const Foam::volTensorField& tgamma,
                 Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf )
  {
    return Foam::fvm::laplacian( tgamma, vf );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( const Foam::surfaceScalarField& gamma,
                 Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf,
                 const Foam::word& name )
  {
    return Foam::fvm::laplacian( gamma, vf, name );
  }

  Foam::tmp< Foam::fvMatrix< Type > > 
  fvm_laplacian( const Foam::surfaceScalarField& gamma,
                 Foam::GeometricField<Type, Foam::fvPatchField, Foam::volMesh>& vf )
  {
    return Foam::fvm::laplacian( gamma, vf );
  }
%}
%enddef


//---------------------------------------------------------------------------
%inline FVM_LAPLACIAN_TEMPLATE_FUNC( Foam::scalar );

%inline FVM_LAPLACIAN_TEMPLATE_FUNC( Foam::vector );


//---------------------------------------------------------------------------
%include <fvmLaplacian.H>


//---------------------------------------------------------------------------
#endif
