// Copyright (c) 2019 The NodeBinding Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NODE_BINDING_TYPED_CALL_H_
#define NODE_BINDING_TYPED_CALL_H_

#include "napi.h"

#include "node_binding/macros.h"
#include "node_binding/template_util.h"
#include "node_binding/type_convertor.h"

namespace node_binding {

namespace internal {

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<0 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  return f(std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<1 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<2 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<3 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), ARG(2), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<4 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), ARG(2), ARG(3),
           std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<5 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4),
           std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<6 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
           std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<7 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
           std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<8 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6), ARG(7),
           std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename... Args, typename... DefaultArgs,
          std::enable_if_t<9 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (*f)(Args...),
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return f(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6), ARG(7),
           ARG(8), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<0 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  return ((*c).*f)(std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<1 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<2 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<3 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<4 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<5 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<6 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<7 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<8 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   ARG(7), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<9 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...), Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   ARG(7), ARG(8), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<0 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  return ((*c).*f)(std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<1 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<2 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<3 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<4 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<5 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<6 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<7 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<8 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   ARG(7), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<9 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   ARG(7), ARG(8), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<0 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  return ((*c).*f)(std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<1 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<2 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<3 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<4 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<5 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<6 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<7 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<8 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   ARG(7), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<9 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) const&,
         const Class* c, DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return ((*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5), ARG(6),
                   ARG(7), ARG(8), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<0 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  return (std::move(*c).*f)(std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<1 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<2 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1),
                            std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<3 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1), ARG(2),
                            std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<4 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3),
                            std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<5 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4),
                            std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<6 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
                            std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<7 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
                            ARG(6), std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<8 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
                            ARG(6), ARG(7),
                            std::forward<DefaultArgs>(def_args)...);
}

template <size_t N, typename R, typename Class, typename... Args,
          typename... DefaultArgs, std::enable_if_t<9 == N>* = nullptr>
R Invoke(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&, Class* c,
         DefaultArgs&&... def_args) {
  using ArgList = internal::TypeList<Args...>;
  return (std::move(*c).*f)(ARG(0), ARG(1), ARG(2), ARG(3), ARG(4), ARG(5),
                            ARG(6), ARG(7), ARG(8),
                            std::forward<DefaultArgs>(def_args)...);
}

}  // namespace internal

template <typename R, typename... Args, typename... DefaultArgs>
Napi::Value TypedCall(const Napi::CallbackInfo& info, R (*f)(Args...),
                      DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  return ToJSValue(info, internal::Invoke<num_args>(
                             info, f, std::forward<DefaultArgs>(def_args)...));
}

template <typename... Args, typename... DefaultArgs>
void TypedCall(const Napi::CallbackInfo& info, void (*f)(Args...),
               DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  internal::Invoke<num_args>(info, f, std::forward<DefaultArgs>(def_args)...);
}

template <typename R, typename Class, typename... Args, typename... DefaultArgs>
Napi::Value TypedCall(const Napi::CallbackInfo& info, R (Class::*f)(Args...),
                      Class* c, DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  return ToJSValue(
      info, internal::Invoke<num_args>(info, f, c,
                                       std::forward<DefaultArgs>(def_args)...));
}

template <typename Class, typename... Args, typename... DefaultArgs>
void TypedCall(const Napi::CallbackInfo& info, void (Class::*f)(Args...),
               Class* c, DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  internal::Invoke<num_args>(info, f, c,
                             std::forward<DefaultArgs>(def_args)...);
}

template <typename R, typename Class, typename... Args, typename... DefaultArgs>
Napi::Value TypedCall(const Napi::CallbackInfo& info,
                      R (Class::*f)(Args...) const, const Class* c,
                      DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  return ToJSValue(
      info, internal::Invoke<num_args>(info, f, c,
                                       std::forward<DefaultArgs>(def_args)...));
}

template <typename Class, typename... Args, typename... DefaultArgs>
void TypedCall(const Napi::CallbackInfo& info, void (Class::*f)(Args...) const,
               const Class* c, DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  internal::Invoke<num_args>(info, f, c,
                             std::forward<DefaultArgs>(def_args)...);
}

template <typename R, typename Class, typename... Args, typename... DefaultArgs>
Napi::Value TypedCall(const Napi::CallbackInfo& info,
                      R (Class::*f)(Args...) const&, const Class* c,
                      DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  return ToJSValue(
      info, internal::Invoke<num_args>(info, f, c,
                                       std::forward<DefaultArgs>(def_args)...));
}

template <typename Class, typename... Args, typename... DefaultArgs>
void TypedCall(const Napi::CallbackInfo& info, void (Class::*f)(Args...) const&,
               const Class* c, DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  internal::Invoke<num_args>(info, f, c,
                             std::forward<DefaultArgs>(def_args)...);
}

template <typename R, typename Class, typename... Args, typename... DefaultArgs>
Napi::Value TypedCall(const Napi::CallbackInfo& info, R (Class::*f)(Args...) &&,
                      Class* c, DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  return ToJSValue(
      info, internal::Invoke<num_args>(info, f, c,
                                       std::forward<DefaultArgs>(def_args)...));
}

template <typename Class, typename... Args, typename... DefaultArgs>
void TypedCall(const Napi::CallbackInfo& info, void (Class::*f)(Args...) &&,
               Class* c, DefaultArgs&&... def_args) {
  constexpr size_t num_args = sizeof...(Args) - sizeof...(DefaultArgs);
  JS_CHECK_NUM_ARGS(info, num_args);

  internal::Invoke<num_args>(info, f, c,
                             std::forward<DefaultArgs>(def_args)...);
}

}  // namespace node_binding

#endif  // NODE_BINDING_TYPED_CALL_H_