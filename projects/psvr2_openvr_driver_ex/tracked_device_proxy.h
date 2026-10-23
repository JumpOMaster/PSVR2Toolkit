#pragma once

#include <openvr_driver.h>

namespace psvr2_toolkit {

  class TrackedDeviceProxy : public vr::ITrackedDeviceServerDriver {
  public:
    TrackedDeviceProxy(vr::ITrackedDeviceServerDriver *pTrackedDevice);

    /** ITrackedDeviceServerDriver **/

    vr::EVRInitError Activate(uint32_t unObjectId) override;
    void Deactivate() override;
    void EnterStandby() override;
    void *GetComponent(const char *pchComponentNameAndVersion) override;
    void DebugRequest(const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize) override;
    vr::DriverPose_t GetPose() override;

  private:
    vr::ITrackedDeviceServerDriver *m_pTrackedDevice;
  };

} // psvr2_toolkit
