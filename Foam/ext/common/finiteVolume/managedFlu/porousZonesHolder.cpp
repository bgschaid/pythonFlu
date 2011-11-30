//  pythonFlu - Python wrapping for OpenFOAM C++ API
//  Copyright (C) 2010- Alexey Petrov
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
//  See http://sourceforge.net/projects/pythonflu
//
//  Author : Alexey PETROV, Andrey SIMURZIN


//---------------------------------------------------------------------------
#ifndef porousZonesHolder_cpp
#define porousZonesHolder_cpp


//---------------------------------------------------------------------------
%{
  #include "Foam/ext/common/finiteVolume/managedFlu/porousZonesHolder.hh"
%}


//---------------------------------------------------------------------------
%import "Foam/ext/common/managedFlu/commonHolder.hxx"

%import "Foam/ext/common/managedFlu/SimpleHolder.cxx"

%import "Foam/src/finiteVolume/fvMesh/fvMeshes.cxx"

INCLUDE_FILENAME(porousZonesHolder,hpp);

%include "Foam/ext/common/finiteVolume/shared_ptr/shared_ptr_porousZones.hpp"

#if FOAM_VERSION( >=, 020000)
INCLUDE_FILENAME(PorousZonesHolder,hpp);

%template ( porousZonesHolder ) Foam::PorousZonesHolder< Foam::porousZone >;
#endif


//---------------------------------------------------------------------------
%feature( "pythonappend" ) Foam::PorousZonesHolder< Foam::porousZone >::SMARTPTR_PYAPPEND_GETATTR( porousZonesHolder );

%extend Foam::PorousZonesHolder< Foam::porousZone >
{
  SMARTPTR_EXTEND_ATTR( porousZonesHolder );
  HOLDERS_CALL_SHARED_PTR_EXTENSION( porousZones );
}


//--------------------------------------------------------------------------------------
#endif
