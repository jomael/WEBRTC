/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef MODULES_RTP_RTCP_SOURCE_RTP_UTILITY_H_
#define MODULES_RTP_RTCP_SOURCE_RTP_UTILITY_H_

#include <stdint.h>

#include <algorithm>

#include "absl/base/attributes.h"
#include "absl/strings/string_view.h"
#include "api/rtp_headers.h"
#include "modules/rtp_rtcp/include/rtp_header_extension_map.h"
#include "modules/rtp_rtcp/include/rtp_rtcp_defines.h"

namespace webrtc {
namespace RtpUtility {

class RtpHeaderParser {
 public:
  RtpHeaderParser(const uint8_t* rtpData, size_t rtpDataLength);
  ~RtpHeaderParser();

  ABSL_DEPRECATED("Use IsRtpPacket or IsRtcpPacket")
  bool RTCP() const;
  bool Parse(RTPHeader* parsedPacket,
             const RtpHeaderExtensionMap* ptrExtensionMap = nullptr,
             bool header_only = false) const;

 private:
  void ParseOneByteExtensionHeader(RTPHeader* parsedPacket,
                                   const RtpHeaderExtensionMap* ptrExtensionMap,
                                   const uint8_t* ptrRTPDataExtensionEnd,
                                   const uint8_t* ptr) const;

  const uint8_t* const _ptrRTPDataBegin;
  const uint8_t* const _ptrRTPDataEnd;
};
}  // namespace RtpUtility
}  // namespace webrtc

#endif  // MODULES_RTP_RTCP_SOURCE_RTP_UTILITY_H_
