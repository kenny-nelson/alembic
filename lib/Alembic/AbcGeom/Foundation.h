//-*****************************************************************************
//
// Copyright (c) 2009-2010,
//  Sony Pictures Imageworks, Inc. and
//  Industrial Light & Magic, a division of Lucasfilm Entertainment Company Ltd.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Sony Pictures Imageworks, nor
// Industrial Light & Magic nor the names of their contributors may be used
// to endorse or promote products derived from this software without specific
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//-*****************************************************************************

#ifndef _Alembic_AbcGeom_Foundation_h_
#define _Alembic_AbcGeom_Foundation_h_

#include <Alembic/Abc/All.h>

#include <ImathMatrixAlgo.h>
#include <ImathEuler.h>


namespace Alembic {
namespace AbcGeom {

namespace Abc = ::Alembic::Abc;
using namespace Abc;

//-*****************************************************************************
//! Meshes have topology, which can be either unchanging (constant)
//! homogeneous, which indicates that the connectivity is unchanging,
//! but the positions may change, and finally heterogeneous, which indicates
//! that the connectivity and positions may change.
enum MeshTopologyVariance
{
    kConstantTopology,
    kHomogenousTopology,
    kHeterogenousTopology
};

//-*****************************************************************************
//! \brief Enum that indicates the type of transformational operation.
//! This enum is used when encoding and decoding the transform operation data.
enum XformOperationType
{
    kScaleOperation = 0,
    kTranslateOperation = 1,
    kRotateOperation = 2,
    kMatrixOperation = 3
};

//-*****************************************************************************
//! This utility function sets an array prorperty sample using "set" if
//! the sample is non-null, otherwise calls setFromPrevious.
template <class PROP, class SAMP>
inline void SetPropUsePrevIfNull( PROP iProp, SAMP iSamp,
                                  const Abc::OSampleSelector &iSS )
{
    if ( iSamp ) { iProp.set( iSamp, iSS ); }
    else { iProp.setFromPrevious( iSS ); }
}

template <>
inline void SetPropUsePrevIfNull<Abc::OStringProperty, std::string>(
    Abc::OStringProperty iProp, std::string iSamp,
    const Abc::OSampleSelector &iSS )
{
    if ( iSamp != "" ) { iProp.set( iSamp, iSS ); }
    else { iProp.setFromPrevious( iSS ); }
}

} // End namespace AbcGeom
} // End namespace Alembic

#endif
