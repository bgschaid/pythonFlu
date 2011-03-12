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
#ifndef List_vector_cxx
#define List_vector_cxx


//---------------------------------------------------------------------------
%module( directors="1", allprotected="1" ) "Foam.src.OpenFOAM.containers.Lists.List.List_vector";
%{
   #include "src/OpenFOAM/containers/Lists/List/List_vector.hpp"
%}


//---------------------------------------------------------------------------
%include "src/OpenFOAM/containers/Lists/List/List.cxx"

%import "src/OpenFOAM/containers/Lists/UList/UList_vector.cxx"

%template( List_vector ) Foam::List< Foam::vector >;

%extend Foam::List< Foam::vector > COMMON_EXTENDS;


//---------------------------------------------------------------------------
#endif
