########### next target ###############

SET(quad-logon_SRCS
AuthCodes.h
AuthSocket.cpp
AuthSocket.h
Main.cpp
LogonList.cpp
LogonList.h
)

SET(quad-logon_LINK_FLAGS "")

add_executable(quad-logon ${quad-logon_SRCS})
add_definitions(
-D_QUAD_LOGON_CONFIG='"${CONF_DIR}/quadlogon.conf"'
)
IF (DO_MYSQL)
   SET(quad-logon_LINK_FLAGS "-pthread ${quad-logon_LINK_FLAGS}")
ENDIF(DO_MYSQL)
IF (DO_POSTGRE)
   SET(quad-logon_LINK_FLAGS "${POSTGRE_LIBS} ${quad-logon_LINK_FLAGS}")
ENDIF(DO_POSTGRE)

IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
   SET(quad-logon_LINK_FLAGS "-framework Carbon ${quad-logon_LINK_FLAGS}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(quad-logon PROPERTIES LINK_FLAGS "${quad-logon_LINK_FLAGS}")

target_link_libraries(
quad-logon
shared
quadframework
quadsockets
quaddatabase
quadauth
quadconfig
ZThread
zlib
${SSLLIB}
${MYSQL_LIBRARIES}
${OSX_LIBS}
)

install(TARGETS quad-logon DESTINATION bin)


########### install files ###############

install(FILES  quadlogon.conf.dist DESTINATION etc)

