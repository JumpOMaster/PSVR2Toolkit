#include "tracked_device_proxy.h"

#include "display_component_proxy.h"

#include <string.h>

namespace psvr2_toolkit {

  TrackedDeviceProxy::TrackedDeviceProxy(vr::ITrackedDeviceServerDriver *pTrackedDevice)
    : m_pTrackedDevice(pTrackedDevice)
  {}

  vr::EVRInitError TrackedDeviceProxy::Activate(uint32_t unObjectId) {
    return m_pTrackedDevice->Activate(unObjectId);
  }

  void TrackedDeviceProxy::Deactivate() {
    m_pTrackedDevice->Deactivate();
  }

  void TrackedDeviceProxy::EnterStandby() {
    m_pTrackedDevice->EnterStandby();
  }

  void *TrackedDeviceProxy::GetComponent(const char *pchComponentNameAndVersion) {
    void *result = m_pTrackedDevice->GetComponent(pchComponentNameAndVersion);

    if (strcmp(vr::IVRDisplayComponent_Version, pchComponentNameAndVersion) == 0 && result) {
      static DisplayComponentProxy *pDisplayComponentProxy = DisplayComponentProxy::Instance();
      pDisplayComponentProxy->SetDisplayComponent(static_cast<vr::IVRDisplayComponent *>(result));
      return pDisplayComponentProxy;
    }

    return result;
  }

  void TrackedDeviceProxy::DebugRequest(const char *pchRequest, char *pchResponseBuffer, uint32_t unResponseBufferSize) {
    m_pTrackedDevice->DebugRequest(pchRequest, pchResponseBuffer, unResponseBufferSize);
  }

  vr::DriverPose_t TrackedDeviceProxy::GetPose() {
    return m_pTrackedDevice->GetPose();
  }

} // psvr2_toolkit
