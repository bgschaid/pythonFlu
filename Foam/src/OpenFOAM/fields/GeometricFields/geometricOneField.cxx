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
%module "Foam.src.OpenFOAM.fields.GeometricFields.geometricOneField";
%{
    #include "src/OpenFOAM/fields/GeometricFields/geometricOneField.hh"
%}


//---------------------------------------------------------------------------
#if FOAM_VERSION( <, 010500 )
#define geometricOneField_cxx
#endif


//---------------------------------------------------------------------------
#ifndef geometricOneField_cxx
#define geometricOneField_cxx

%import "src/common.hxx"


//---------------------------------------------------------------------------
%import "src/OpenFOAM/fields/Fields/oneField.cxx"

%import "src/OpenFOAM/fields/FieldFields/oneFieldField.cxx"

%import "src/OpenFOAM/primitives/label.cxx"

%include <geometricOneField.H>


//---------------------------------------------------------------------------
#endif