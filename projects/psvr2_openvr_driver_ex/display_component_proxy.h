#pragma once

#include <openvr_driver.h>

namespace psvr2_toolkit {

  class DisplayComponentProxy : public vr::IVRDisplayComponent {
  public:
    DisplayComponentProxy();

    static DisplayComponentProxy *Instance();

    void SetDisplayComponent(vr::IVRDisplayComponent *pDisplayComponent);

    /** IVRDisplayComponent **/

    void GetWindowBounds(int32_t *pnX, int32_t *pnY, uint32_t *pnWidth, uint32_t *pnHeight) override;
    bool IsDisplayOnDesktop() override;
    bool IsDisplayRealDisplay() override;
    void GetRecommendedRenderTargetSize(uint32_t *pnWidth, uint32_t *pnHeight) override;
    void GetEyeOutputViewport(vr::EVREye eEye, uint32_t *pnX, uint32_t *pnY, uint32_t *pnWidth, uint32_t *pnHeight) override;
    void GetProjectionRaw(vr::EVREye eEye, float *pfLeft, float *pfRight, float *pfTop, float *pfBottom) override;
    vr::DistortionCoordinates_t ComputeDistortion(vr::EVREye eEye, float fU, float fV) override;
    bool ComputeInverseDistortion(vr::HmdVector2_t *pResult, vr::EVREye eEye, uint32_t unChannel, float fU, float fV) override;

  private:
    static DisplayComponentProxy *m_pInstance;

    vr::IVRDisplayComponent *m_pDisplayComponent;
  };

} // psvr2_toolkit
