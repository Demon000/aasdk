/*
*  This file is part of aasdk library project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  aasdk is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.

*  aasdk is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with aasdk. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <aasdk_proto/ChannelOpenRequestMessage.pb.h>
#include <aasdk_proto/NavigationDistanceEventMessage.pb.h>
#include <aasdk_proto/NavigationStatusMessage.pb.h>
#include <aasdk_proto/NavigationTurnEventMessage.pb.h>
#include <aasdk/Error/Error.hpp>

namespace aasdk {
namespace channel {
namespace navigation {

class INavigationStatusServiceChannelEventHandler {
 public:
  typedef std::shared_ptr<INavigationStatusServiceChannelEventHandler> Pointer;

  INavigationStatusServiceChannelEventHandler() = default;
  virtual ~INavigationStatusServiceChannelEventHandler() = default;

  virtual void onChannelOpenRequest(
      const proto::messages::ChannelOpenRequest& request) = 0;
  virtual void onChannelError(const error::Error& e) = 0;
  virtual void onStatusUpdate(
      const proto::messages::NavigationStatus& navStatus) = 0;
  virtual void onTurnEvent(
      const proto::messages::NavigationTurnEvent& turnEvent) = 0;
  virtual void onDistanceEvent(
      const proto::messages::NavigationDistanceEvent& distanceEvent) = 0;
};

}  // namespace navigation
}  // namespace channel
}  // namespace aasdk
