// Copyright (c) 2016 Martin Moene
//
// https://github.com/martinmoene/variant-lite
//
// This code is licensed under the MIT License (MIT).

#pragma once

#ifndef TEST_VARIANT_LITE_H_INCLUDED
#define TEST_VARIANT_LITE_H_INCLUDED

#include "optional.hpp"
#include "variant.hpp"
#include "lest_cpp03.hpp"

using namespace nonstd;

#define CASE( name ) lest_CASE( specification(), name )

extern lest::tests & specification();

namespace nonstd { namespace variants {

// use oparator<< instead of to_string() overload;
// see  http://stackoverflow.com/a/10651752/437272

template< class  T >
inline std::ostream & operator<<( std::ostream & os, nonstd::variants::detail::TX<T> const & v )
{
    return os << "[variant:tx]";
}

template< class T0, class T1, class T2, class T3, class T4, class T5, class T6 >
inline std::ostream & operator<<( std::ostream & os, nonstd::variant<T0, T1, T2, T3, T4, T5, T6> const & v )
{
    os << "[variant:";
    switch( v.index() )
    {
        case 0: os << get<0>( v ); break;
        case 1: os << get<1>( v ); break;
        case 2: os << get<2>( v ); break;
        case 3: os << get<3>( v ); break;
        case 4: os << get<4>( v ); break;
        case 5: os << get<5>( v ); break;
        case 6: os << get<6>( v ); break;
        default: os << "unexpected index";
    }
    return os << "]";
}

}}

namespace lest {

using ::nonstd::variants::operator<<;

} // namespace lest

#endif // TEST_VARIANT_LITE_H_INCLUDED

// end of file
