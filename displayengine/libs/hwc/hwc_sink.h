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

#ifndef __HWC_SINK_H__
#define __HWC_SINK_H__

#include <hardware/hwcomposer.h>
#include <core/core_interface.h>

namespace sde {

class HWCSink : public DeviceEventHandler {
 public:
  virtual int Init();
  virtual int Deinit();
  virtual int Prepare(hwc_display_contents_1_t *content_list) = 0;
  virtual int Commit(hwc_display_contents_1_t *content_list) = 0;
  virtual int Blank(int blank);
  virtual int GetDisplayConfigs(uint32_t *configs, size_t *num_configs);
  virtual int GetDisplayAttributes(uint32_t config, const uint32_t *attributes, int32_t *values);

 protected:
  HWCSink(CoreInterface *core_intf, hwc_procs_t const *hwc_procs, DeviceType type, int id);
  virtual ~HWCSink() { }

  // DeviceEventHandler methods
  virtual DisplayError VSync(const DeviceEventVSync &vsync);
  virtual DisplayError Refresh();

  CoreInterface *core_intf_;
  hwc_procs_t const *hwc_procs_;
  DeviceType type_;
  int id_;
  DeviceInterface *device_intf_;
};

}  // namespace sde

#endif  // __HWC_SINK_H__

