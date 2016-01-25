//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V2_ADAPTOR_BASE_DECL_HPP
#define MSGPACK_V2_ADAPTOR_BASE_DECL_HPP

#include "msgpack/v1/adaptor/adaptor_base_decl.hpp"

namespace msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

using v1::packer;

namespace adaptor {

// Adaptor functors

using v1::adaptor::convert;

using v1::adaptor::pack;

using v1::adaptor::object;

using v1::adaptor::object_with_zone;

} // namespace adaptor

// operators

using v1::operator>>;
using v1::operator<<;

/// @cond
} // MSGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

} // namespace msgpack

#endif // MSGPACK_V2_ADAPTOR_BASE_DECL_HPP
