project(miniupnpc)

set(header "miniupnpc/miniupnpc.h"
"miniupnpc/upnpcommands.h"
"miniupnpc/miniwget.h"
"miniupnpc/upnpdev.h"
"miniupnpc/igd_desc_parse.h"
"miniupnpc/minissdpc.h"
"miniupnpc/minisoap.h"
"miniupnpc/minixml.h"
"miniupnpc/connecthostport.h"
"miniupnpc/receivedata.h"
"miniupnpc/portlistingparse.h"
"miniupnpc/upnpreplyparse.h")

set(c "miniupnpc/miniupnpc.c"
"miniupnpc/upnpcommands.c"
"miniupnpc/miniwget.c"
"miniupnpc/upnpdev.c"
"miniupnpc/igd_desc_parse.c"
"miniupnpc/minissdpc.c"
"miniupnpc/minisoap.c"
"miniupnpc/minixml.c"
"miniupnpc/connecthostport.c"
"miniupnpc/receivedata.c"
"miniupnpc/portlistingparse.c"
"miniupnpc/upnpreplyparse.c")

add_library(${PROJECT_NAME} ${header} ${c})

# TODO : need to be remove
target_link_libraries(${PROJECT_NAME} PRIVATE godotCore)

target_include_directories(${PROJECT_NAME} PUBLIC ".")

if(${target} STREQUAL "windows")
    target_compile_definitions(${PROJECT_NAME} PUBLIC -DMINIUPNP_STATICLIB)
endif()

