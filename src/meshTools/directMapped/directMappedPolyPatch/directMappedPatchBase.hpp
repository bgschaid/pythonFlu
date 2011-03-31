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
#include "src/common.hpp"

#if FOAM_VERSION( <, 010600 )
#define directMappedPatchBase_hpp
#endif


//---------------------------------------------------------------------------
#ifndef directMappedPatchBase_hpp
#define directMappedPatchBase_hpp


//---------------------------------------------------------------------------
#include "src/OpenFOAM/meshes/primitiveShapes/point/pointField.hpp"

#include "src/OpenFOAM/meshes/polyMesh/polyPatches/polyPatch.hpp"

// #include "Tuple2.H"
// #include "pointIndexHit.H"

#include "src/OpenFOAM/meshes/polyMesh/mapPolyMesh/mapDistribute/mapDistribute.hpp"

#include <directMappedPatchBase.H>


//---------------------------------------------------------------------------
#endif
