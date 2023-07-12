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
#include <string>

#include "minimal_service_client/minimal_service_client.h"

MinimalServiceClient::MinimalServiceClient(ros::NodeHandle& nh) : nh_(nh)
{
  srv_ = nh_.serviceClient<minimal_messages::CustomSrv>("/minimal_service");
}

MinimalServiceClient::~MinimalServiceClient() { }

void MinimalServiceClient::callService(const std::string& request_data)
{
  minimal_messages::CustomSrv srv;
  srv.request.text = request_data;
  // Wait for the server to become available
  if (srv_.waitForExistence(ros::Duration(5.0)))
  {
    if (srv_.call(srv))
    {
      if (srv.response.response)
      {
        ROS_INFO("Service call succeeded");
      }
      else
      {
      ROS_WARN("Service call failed.");
      }
    }
    else
    {
      ROS_ERROR("Failed to call service");
    }
  }
  else
  {
    ROS_ERROR("Timeout: Server is not available");
  }
}
