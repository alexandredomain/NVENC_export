/*
 * Copyright 1993-2013 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

#ifndef _NVENCODE_H264_H_
#define _NVENCODE_H264_H_

#include <CNVEncoder.h>

class CNvEncoderH264:public CNvEncoder
{
public:
    CNvEncoderH264();
    ~CNvEncoderH264();
protected:
    bool                                                 m_bMVC;
    unsigned int                                         m_dwViewId;
    unsigned int                                         m_dwPOC;
    unsigned int                                         m_dwFrameNumSyntax;
    unsigned int                                         m_dwIDRPeriod;
    unsigned int                                         m_dwNumRefFrames[2];
    unsigned int                                         m_dwFrameNumInGOP;
    unsigned int                                         m_uMaxHeight;
    unsigned int                                         m_uMaxWidth;
    unsigned int                                         m_uCurHeight;
    unsigned int                                         m_uCurWidth;
	NV_ENC_H264_SEI_PAYLOAD								 m_sei_user_payload;     // SEI: user encoder settings
	std::string											 m_sei_user_payload_str; // SEI: encoder-settings converted to text-msg

public:
    virtual HRESULT                                      InitializeEncoder();
//    virtual HRESULT                                      InitializeEncoderH264( NV_ENC_CONFIG_H264_VUI_PARAMETERS *pvui );
	virtual HRESULT                                      InitializeEncoderCodec(void * const p);
	virtual HRESULT                                      ReconfigureEncoder(EncodeConfig EncoderReConfig);
	virtual HRESULT                                      EncodeFramePPro(EncodeFrameConfig *pEncodeFrame, const bool bFlush);
    virtual HRESULT                                      EncodeCudaMemFrame(EncodeFrameConfig *pEncodeFrame, CUdeviceptr oFrame[], const unsigned int oFrame_pitch, bool bFlush=false);
    virtual HRESULT                                      DestroyEncoder();
};

#endif
