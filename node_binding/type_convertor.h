// Copyright (c) 2019 The NodeBinding Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NODE_BINDING_TYPE_CONVERTOR_H_
#define NODE_BINDING_TYPE_CONVERTOR_H_

#include <string>
#include <type_traits>

#include "napi.h"

namespace node_binding {

template <typename T, typename SFINAE = void>
class TypeConvertor;

template <>
class TypeConvertor<bool> {
 public:
  static bool ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::Boolean>().Value();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsBoolean();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, bool value) {
    return Napi::Boolean::New(env, value);
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_integral<T>::value &&
                                        std::is_signed<T>::value &&
                                        sizeof(T) <= sizeof(int32_t)>> {
 public:
  static T ToNativeValue(const Napi::Value& value) {
    return static_cast<T>(value.As<Napi::Number>().Int32Value());
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsNumber();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, T value) {
    return Napi::Number::New(env, value);
  }
};

template <typename T>
class TypeConvertor<
    T, std::enable_if_t<
           std::is_integral<T>::value && !std::is_same<bool, T>::value &&
           !std::is_signed<T>::value && sizeof(T) <= sizeof(int32_t)>> {
 public:
  static T ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::Number>().Uint32Value();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsNumber();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, T value) {
    return Napi::Number::New(env, value);
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_same<int64_t, T>::value>> {
 public:
  static int64_t ToNativeValue(const Napi::Value& value) {
#ifdef NAPI_EXPERIMENTAL
    return value.As<Napi::BigInt>().Int64Value();
#else
    return value.As<Napi::Number>().Int64Value();
#endif
  }

  static bool IsConvertible(const Napi::Value& value) {
#ifdef NAPI_EXPERIMENTAL
    return value.IsBigInt();
#else
    return value.IsNumber();
#endif
  }

  static Napi::Value ToJSValue(const Napi::Env& env, int64_t value) {
#ifdef NAPI_EXPERIMENTAL
    return Napi::BigInt::New(env, value);
#else
    return Napi::Number::New(env, value);
#endif
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_same<uint64_t, T>::value>> {
 public:
  static uint64_t ToNativeValue(const Napi::Value& value) {
#ifdef NAPI_EXPERIMENTAL
    return value.As<Napi::BigInt>().Uint64Value();
#else
    return static_cast<uint64_t>(value.As<Napi::Number>().Int64Value());
#endif
  }

  static bool IsConvertible(const Napi::Value& value) {
#ifdef NAPI_EXPERIMENTAL
    return value.IsBigInt();
#else
    return value.IsNumber();
#endif
  }

  static Napi::Value ToJSValue(const Napi::Env& env, uint64_t value) {
#ifdef NAPI_EXPERIMENTAL
    return Napi::BigInt::New(env, value);
#else
    return Napi::Number::New(env, value);
#endif
  }
};

template <>
class TypeConvertor<long> {
 public:
  static long ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::Number>().Int64Value();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsNumber();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, long value) {
    return Napi::Number::New(env, value);
  }
};

template <>
class TypeConvertor<unsigned long> {
 public:
  static unsigned long ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::Number>().Int64Value();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsNumber();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, unsigned long value) {
    return Napi::Number::New(env, value);
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_same<float, T>::value>> {
 public:
  static float ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::Number>().FloatValue();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsNumber();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, float value) {
    return Napi::Number::New(env, value);
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_same<double, T>::value>> {
 public:
  static double ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::Number>().DoubleValue();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsNumber();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, double value) {
    return Napi::Number::New(env, value);
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_same<std::string, T>::value>> {
 public:
  static std::string ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::String>().Utf8Value();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsString();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, const std::string& value) {
    return Napi::String::New(env, value);
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_enum<T>::value>> {
 public:
  static std::underlying_type_t<T> ToNativeValue(const Napi::Value& value) {
    return TypeConvertor<std::underlying_type_t<T>>::ToNativeValue();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsNumber();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, T value) {
    return Napi::Number::New(env,
                             static_cast<std::underlying_type_t<T>>(value));
  }
};

template <typename T>
class TypeConvertor<T, std::enable_if_t<std::is_same<const char*, T>::value>> {
 public:
  static std::string ToNativeValue(const Napi::Value& value) {
    return value.As<Napi::String>().Utf8Value();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsString();
  }

  static Napi::Value ToJSValue(const Napi::Env& env, const char* value) {
    return Napi::String::New(env, value);
  }
};

template <>
class TypeConvertor<Napi::Object> {
 public:
  static Napi::Object ToNativeValue(const Napi::Value& value) {
    return value.ToObject();
  }

  static bool IsConvertible(const Napi::Value& value) {
    return value.IsObject();
  }

  static Napi::Value ToJSValue(const Napi::Env& env,
                               const Napi::Object& value) {
    return value;
  }
};

template <>
class TypeConvertor<Napi::Value> {
 public:
  static Napi::Value ToNativeValue(const Napi::Value& value) { return value; }

  static bool IsConvertible(const Napi::Value& value) { return true; }

  static Napi::Value ToJSValue(const Napi::Env& env, const Napi::Value& value) {
    return value;
  }
};

template <typename T>
auto ToNativeValue(const Napi::Value& value) {
  return TypeConvertor<T>::ToNativeValue(value);
}

template <typename T>
bool IsConvertible(const Napi::Value& value) {
  return TypeConvertor<T>::IsConvertible(value);
}

template <typename T>
Napi::Value ToJSValue(const Napi::Env& env, T&& value) {
  return TypeConvertor<std::decay_t<T>>::ToJSValue(env, std::forward<T>(value));
}

}  // namespace node_binding

#endif  // NODE_BINDING_TYPE_CONVERTOR_H_