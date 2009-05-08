
########### next target ###############

SET(quadinterface_LIB_SRCS
   ScriptMgr.cpp
   ScriptMgr.h
   config.h
   system.cpp
   Scripts/sc_default.cpp
   Scripts/sc_defines.cpp
   Scripts/sc_defines.h
)

add_library(quadinterface SHARED ${quadinterface_LIB_SRCS})

target_link_libraries(quadinterface)

set_target_properties(quadinterface PROPERTIES VERSION 4.2.0 SOVERSION 4)
install(TARGETS quadinterface DESTINATION lib)
