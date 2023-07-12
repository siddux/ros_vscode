/*
 *  Copyright 2023 Eduard Rius
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 *  software and associated documentation files (the "Software"), to deal in the Software without 
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or 
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "minimal_publisher/minimal_publisher.h"

MinimalPublisher::MinimalPublisher(ros::NodeHandle& nh) : nh_(nh)
{
  pub_ = nh_.advertise<minimal_messages::CustomMsg>("/minimal_publisher", 10);
  msg_id_ = 0;
}

MinimalPublisher::~MinimalPublisher() { }

void MinimalPublisher::publishMessage(const minimal_messages::CustomMsg& message)
{
  minimal_messages::CustomMsg msg;
  msg.id = msg_id_;
  msg_id_++;
  msg.message = message.message;
  pub_.publish(msg);
}
