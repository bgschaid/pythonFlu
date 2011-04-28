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
#ifndef vector_cxx
#define vector_cxx


//---------------------------------------------------------------------------
%module "Foam.src.OpenFOAM.primitives.vector";
%{
  #include "src/OpenFOAM/primitives/vector.hh"
%}


//---------------------------------------------------------------------------
%import "src/common.hxx"

%import "src/OpenFOAM/primitives/scalar.cxx"

%import "src/OpenFOAM/primitives/direction.cxx"

%include <VectorSpace.H>

%template( VectorSpace_Vector ) Foam::VectorSpace< Foam::Vector< Foam::scalar >, Foam::scalar, 3 >;


//---------------------------------------------------------------------------
%extend Foam::VectorSpace< Foam::Vector< Foam::scalar >, Foam::scalar, 3 >
{
  int __len__()
  {
    return self->size();
  }
  
  Foam::scalar __getitem__( const Foam::direction theIndex )
  {
    return self->operator[]( theIndex );
  }
  
  void __setitem__( const Foam::direction theIndex, const Foam::scalar& theValue )
  {
    self->operator[]( theIndex ) = theValue;
  }
}


//---------------------------------------------------------------------------
%include <Vector.H>


//---------------------------------------------------------------------------
%include <vector.H>

%template( vector ) Foam::Vector< Foam::scalar >;


//---------------------------------------------------------------------------
%include "src/try_reverse_operator.hxx"

%feature ("pythonprepend") Foam::Vector< Foam::scalar >::TRY_REVERSE_PYPREPEND( and )

%extend Foam::Vector< Foam::scalar >
{
  Foam::Tensor< Foam::scalar > sqr()
  {
    return Foam::sqr( *self );
  }
  Foam::Vector< Foam::scalar > __neg__()
  {
    return - *self;
  }
  Foam::scalar __and__( const Foam::Vector< Foam::scalar >& theArg )
  {
    return  *self & theArg;
  }
  
  Foam::Vector< Foam::scalar > __div__( const Foam::scalar& theArg )
  {
    return  *self / theArg;
  }
  Foam::scalar mag()
  {
    return  Foam::mag( *self );
  }  
}


//---------------------------------------------------------------------------
#endif