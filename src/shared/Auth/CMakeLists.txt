
########### next target ###############

SET(quadauth_STAT_SRCS
   AuthCrypt.cpp
   AuthCrypt.h
   BigNumber.cpp
   BigNumber.h
   Hmac.cpp
   Hmac.h
   Sha1.cpp
   Sha1.h
   md5.c
   md5.h
)

add_library(quadauth STATIC ${quadauth_STAT_SRCS})
