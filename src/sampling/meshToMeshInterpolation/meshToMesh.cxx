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
#ifndef meshToMesh_cxx
#define meshToMesh_cxx


//---------------------------------------------------------------------------
%module "Foam.src.sampling.meshToMeshInterpolation.meshToMesh";
%{
  #include "src/sampling/meshToMeshInterpolation/meshToMesh.hh"
%}


//---------------------------------------------------------------------------
%import "src/common.hxx"

%import "src/finiteVolume/fvMesh/fvMeshes.cxx"

%import "src/OpenFOAM/primitives/Lists/wordList.cxx"

%import "src/OpenFOAM/containers/HashTables/HashTable/HashTable_word_word_string_hash.cxx"

%include <meshToMesh.H>

%define MESHTOMESH_ADDONS( Type )
{
  //- Map field
  void mapField( Field< Type >& toF,
                 const Field< Type >& fromVf,
                 const labelList& adr ) const
  {
    self->mapField( toF, fromVf, adr );
  }

  //- Interpolate field using inverse-distance weights
  void interpolateField( Field< Type >& toF,
                         const GeometricField< Type, fvPatchField, volMesh >& fromVf,
                         const labelList& adr,
                         const scalarListList& weights ) const
  {
    self->interpolateField( toF, fromVf, adr, weights );
  }

  //- Interpolate field using cell-point interpolation
  void interpolateField( Field< Type >& toF,
                         const GeometricField< Type, fvPatchField, volMesh >& fromVf,
                         const labelList& adr,
                         const vectorField& centres ) const
  {
    self->interpolateField( toF, fromVf, adr, centres );
  }

  //- Interpolate internal volume field
  void interpolateInternalField( Field< Type >& toF,
                                 const GeometricField< Type, fvPatchField, volMesh >& fromVf,
                                 meshToMesh::order ord = meshToMesh::INTERPOLATE ) const
  {
    self->interpolateInternalField( toF, fromVf, ord );
  }

  //- Interpolate volume field
  void interpolate( GeometricField< Type, fvPatchField, volMesh >& toF,
                    const GeometricField< Type, fvPatchField, volMesh >& fromVf,
                    meshToMesh::order ord = meshToMesh::INTERPOLATE ) const
  {
    self->interpolate( toF, fromVf, ord );
  }

  //- Interpolate volume field
  tmp< GeometricField< Type, fvPatchField, volMesh > > 
  interpolate( const GeometricField< Type, fvPatchField, volMesh >& fromVf,
               meshToMesh::order ord = meshToMesh::INTERPOLATE ) const
  {
    return self->interpolate( fromVf, ord );
  }
}
%enddef

%extend Foam::meshToMesh MESHTOMESH_ADDONS( Foam::scalar );

%extend Foam::meshToMesh MESHTOMESH_ADDONS( Foam::vector );


//--------------------------------------------------------------------------------------
#endif
