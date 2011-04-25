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
#ifndef regIOobject_cxx
#define regIOobject_cxx


//---------------------------------------------------------------------------
%module( directors="1", allprotected="1" ) "Foam.src.OpenFOAM.db.regIOobject";
%{
  #include "src/OpenFOAM/db/regIOobject.hh"
%}

// Keep on corresponding "director" includes at the top of SWIG defintion file
%include "src/OpenFOAM/directors.hxx"


//---------------------------------------------------------------------------
%import "src/OpenFOAM/db/IOobject.cxx"


//---------------------------------------------------------------------------
%feature( "director" ) regIOobject;

DIRECTOR_PRE_EXTENDS( regIOobject );


//---------------------------------------------------------------------------
%ignore Foam::regIOobject::writeObject;

%include "regIOobject.H"


//---------------------------------------------------------------------------
%extend Foam::regIOobject
{
  DIRECTOR_EXTENDS( regIOobject );
}


//---------------------------------------------------------------------------
#endif
