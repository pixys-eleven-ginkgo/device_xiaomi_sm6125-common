/*
* Copyright (c) 2014, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
*    * Redistributions of source code must retain the above copyright notice, this list of
*      conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright notice, this list of
*      conditions and the following disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of The Linux Foundation nor the names of its contributors may be used to
*      endorse or promote products derived from this software without specific prior written
*      permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// DISPLAY_LOG_TAG definition must precede logger.h include.
#define DISPLAY_LOG_TAG kTagCore
#define DISPLAY_MODULE_NAME "DeviceBase"
#include <utils/logger.h>

#include <utils/constants.h>

#include "device_base.h"

namespace sde {

DeviceBase::DeviceBase(HWInterfaceType type, DeviceEventHandler *event_handler,
                       HWInterface *hw_interface, CompManager *comp_manager)
  : type_(type), event_handler_(event_handler), hw_intf_(hw_interface), comp_manager_(comp_manager),
    state_(kStateOff) {
}

DisplayError DeviceBase::Init() {
  SCOPE_LOCK(locker_);

  return kErrorNone;
}

DisplayError DeviceBase::Deinit() {
  SCOPE_LOCK(locker_);

  return kErrorNone;
}

DisplayError DeviceBase::Prepare(LayerStack *layer_stack) {
  SCOPE_LOCK(locker_);

  return kErrorNone;
}

DisplayError DeviceBase::Commit(LayerStack *layer_stack) {
  SCOPE_LOCK(locker_);

  return kErrorNone;
}

DisplayError DeviceBase::GetDeviceState(DeviceState *state) {
  SCOPE_LOCK(locker_);

  if (UNLIKELY(!state)) {
    return kErrorParameters;
  }

  *state = state_;
  return kErrorNone;
}

DisplayError DeviceBase::GetNumVariableInfoConfigs(uint32_t *count) {
  SCOPE_LOCK(locker_);

  if (UNLIKELY(!count)) {
    return kErrorParameters;
  }

  return kErrorNone;
}

DisplayError DeviceBase::GetConfig(DeviceConfigFixedInfo *fixed_info) {
  SCOPE_LOCK(locker_);

  if (UNLIKELY(!fixed_info)) {
    return kErrorParameters;
  }

  return kErrorNone;
}

DisplayError DeviceBase::GetConfig(DeviceConfigVariableInfo *variable_info, uint32_t mode) {
  SCOPE_LOCK(locker_);

  if (UNLIKELY(!variable_info)) {
    return kErrorParameters;
  }

  return kErrorNone;
}

DisplayError DeviceBase::GetVSyncState(bool *enabled) {
  SCOPE_LOCK(locker_);

  if (UNLIKELY(!enabled)) {
    return kErrorParameters;
  }

  return kErrorNone;
}

DisplayError DeviceBase::SetDeviceState(DeviceState state) {
  SCOPE_LOCK(locker_);

  return kErrorNone;
}

DisplayError DeviceBase::SetConfig(uint32_t mode) {
  SCOPE_LOCK(locker_);

  return kErrorNone;
}

DisplayError DeviceBase::SetVSyncState(bool enabled) {
  SCOPE_LOCK(locker_);

  return kErrorNone;
}

}  // namespace sde

