/**
 * Copyright 2020 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MINDSPORE_SERVING_ACL_SESSION_H
#define MINDSPORE_SERVING_ACL_SESSION_H

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <memory>
#include <map>

#include "include/inference.h"
#include "serving/acl/model_process.h"

namespace mindspore {
namespace inference {
class AclSession : public InferSession {
 public:
  AclSession();

  bool InitEnv(const std::string &device_type, uint32_t device_id) override;
  bool FinalizeEnv() override;
  bool LoadModelFromFile(const std::string &file_name, uint32_t &model_id) override;
  bool UnloadModel(uint32_t model_id) override;
  bool ExecuteModel(uint32_t model_id, const RequestBase &request, ReplyBase &reply) override;

 private:
  std::string device_type_;
  int32_t device_id_;
  aclrtStream stream_ = nullptr;
  aclrtContext context_ = nullptr;
  ModelProcess model_process_;
};
}  // namespace inference
}  // namespace mindspore
#endif  // MINDSPORE_SERVING_ACL_SESSION_H
