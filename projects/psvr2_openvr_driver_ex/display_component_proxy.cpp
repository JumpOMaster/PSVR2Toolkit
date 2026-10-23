#include "display_component_proxy.h"

namespace psvr2_toolkit {

  DisplayComponentProxy *DisplayComponentProxy::m_pInstance = nullptr;

  DisplayComponentProxy::DisplayComponentProxy()
    : m_pDisplayComponent(nullptr)
  {}

  DisplayComponentProxy *DisplayComponentProxy::Instance() {
    if (!m_pInstance) {
      m_pInstance = new DisplayComponentProxy;
    }

    return m_pInstance;
  }

  void DisplayComponentProxy::SetDisplayComponent(vr::IVRDisplayComponent *pDisplayComponent) {
    m_pDisplayComponent = pDisplayComponent;
  }

  void DisplayComponentProxy::GetWindowBounds(int32_t *pnX, int32_t *pnY, uint32_t *pnWidth, uint32_t *pnHeight) {
    m_pDisplayComponent->GetWindowBounds(pnX, pnY, pnWidth, pnHeight);
  }

  bool DisplayComponentProxy::IsDisplayOnDesktop() {
    return m_pDisplayComponent->IsDisplayOnDesktop();
  }

  bool DisplayComponentProxy::IsDisplayRealDisplay() {
    return m_pDisplayComponent->IsDisplayRealDisplay();
  }

  void DisplayComponentProxy::GetRecommendedRenderTargetSize(uint32_t *pnWidth, uint32_t *pnHeight) {
//    m_pDisplayComponent->GetRecommendedRenderTargetSize(pnWidth, pnHeight);

    *pnWidth = 3536;
    *pnHeight = 3368;
  }

  void DisplayComponentProxy::GetEyeOutputViewport(vr::EVREye eEye, uint32_t *pnX, uint32_t *pnY, uint32_t *pnWidth, uint32_t *pnHeight) {
    m_pDisplayComponent->GetEyeOutputViewport(eEye, pnX, pnY, pnWidth, pnHeight);
  }

  void DisplayComponentProxy::GetProjectionRaw(vr::EVREye eEye, float *pfLeft, float *pfRight, float *pfTop, float *pfBottom) {
    m_pDisplayComponent->GetProjectionRaw(eEye, pfLeft, pfRight, pfTop, pfBottom);
  }

  vr::DistortionCoordinates_t DisplayComponentProxy::ComputeDistortion(vr::EVREye eEye, float fU, float fV) {
    return m_pDisplayComponent->ComputeDistortion(eEye, fU, fV);
  }

  bool DisplayComponentProxy::ComputeInverseDistortion(vr::HmdVector2_t *pResult, vr::EVREye eEye, uint32_t unChannel, float fU, float fV) {
    return m_pDisplayComponent->ComputeInverseDistortion(pResult, eEye, unChannel, fU, fV);
  }

} // psvr2_toolkit
