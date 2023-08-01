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

#include <aasdk/Channel/Promise.hpp>
#include <aasdk/Messenger/IMessenger.hpp>
#include <boost/asio.hpp>

namespace aasdk {
namespace channel {

#define PRINT_RECEIVE(str) \
  AASDK_LOG(error) << channelIdToString(this->channelId_) << " Receive " << str;

#define PRINT_SEND_PROTO(response) \
  AASDK_LOG(error) << channelIdToString(this->channelId_) << " Send " << response.GetTypeName() << " " << response.DebugString()

#define PRINT_RECEIVE_PROTO(response) \
  AASDK_LOG(error) << channelIdToString(this->channelId_) << " Receive " << response.GetTypeName() << " " << response.DebugString()

class ServiceChannel {
 protected:
  ServiceChannel(boost::asio::io_service::strand& strand,
                 messenger::IMessenger::Pointer messenger,
                 messenger::ChannelId channelId);

  virtual ~ServiceChannel() = default;
  void send(messenger::Message::Pointer message, SendPromise::Pointer promise);

  boost::asio::io_service::strand& strand_;
  messenger::IMessenger::Pointer messenger_;
  messenger::ChannelId channelId_;
};

}  // namespace channel
}  // namespace aasdk
