cmake_minimum_required(VERSION 3.2)
project(WhatsAnalyzer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp MessageFactory.cpp MessageFactory.h MessageProcessors/AndroidMessageProcessorImpl.h MessageProcessors/AndroidMessageProcessorImpl.h MessageProcessors/AndroidMessageProcessorImpl.h MessageProcessors/AndroidMessageProcessorImpl.h MessageProcessors/IOSMessageProcessorImpl.h MessageProcessors/IOSMessageProcessorImpl.h MessageFactory.cpp MessageFactory.h)
add_executable(WhatsAnalyzer ${SOURCE_FILES} Dialogue.cpp Dialogue.h Message.cpp Message.h)