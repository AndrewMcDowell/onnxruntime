// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/providers/rocm/rocm_common.h"
#include "core/providers/rocm/math/binary_elementwise_ops.h"
#include "core/providers/rocm/activation/activations.h"
#include "orttraining/training_ops/rocm/activation/activations_grad_impl.h"

namespace onnxruntime {
namespace rocm {

template <typename T>
class GeluGrad final : public BinaryElementwise<ShouldNotBroadcast> {
 public:
  GeluGrad(const OpKernelInfo& info) : BinaryElementwise(info) {}

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  MAKE_FUNC_CTX_NULL()
};

template <typename T>
class FastGeluGrad final : public BinaryElementwise<ShouldNotBroadcast> {
 public:
  FastGeluGrad(const OpKernelInfo& info) : BinaryElementwise(info) {}

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  MAKE_FUNC_CTX_NULL()
};

template <typename T>
class ReluGrad final : public BinaryElementwise<ShouldNotBroadcast> {
 public:
  ReluGrad(const OpKernelInfo& info) : BinaryElementwise(info) {}

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  MAKE_FUNC_CTX_NULL()
};

}  // namespace rocm
}  // namespace onnxruntime
