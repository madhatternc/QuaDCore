
########### next target ###############

SET(quad-core_SRCS
CliRunnable.cpp
CliRunnable.h
Main.cpp
Master.cpp
Master.h
RASocket.cpp
RASocket.h
WorldRunnable.cpp
WorldRunnable.h
)

SET(quad-core_LINK_FLAGS "")

add_executable(quad-core ${quad-core_SRCS})
add_definitions(
-D_QUAD_CORE_CONFIG='"${CONF_DIR}/quadcore.conf"'
)
IF (DO_MYSQL)
    SET(quad-core_LINK_FLAGS "-pthread ${quad-core_LINK_FLAGS}")
ENDIF(DO_MYSQL)


IF (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    SET(quad-core_LINK_FLAGS "-framework Carbon ${quad-core_LINK_FLAGS}")
    SET(SCRIPT_LIB "")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Darwin")

SET_TARGET_PROPERTIES(quad-core PROPERTIES LINK_FLAGS "${quad-core_LINK_FLAGS}")

target_link_libraries(
quad-core
game
shared
zlib
quadframework
quadsockets
quaddatabase
quadauth
quadconfig
vmaps
ZThread
g3dlite
${SCRIPT_LIB}
${MYSQL_LIBRARIES}
${POSTGRE_LIBS}
${SSLLIB}
${ACE_LIBRARY}
${ZLIB}
${OSX_LIBS}
)

install(TARGETS quad-core DESTINATION bin)


########### install files ###############

install(FILES  quadcore.conf.dist DESTINATION etc)

