set(Boost_USE_STATIC_LIBS ON)
find_package(Threads)
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Yaml-cpp)
find_package(seccomp)

aux_source_directory(. DAEMON_SOURCE_FILES)
aux_source_directory(./sandboxing/ DAEMON_SOURCE_FILES)
aux_source_directory(./log/ DAEMON_SOURCE_FILES)
aux_source_directory(./config/ DAEMON_SOURCE_FILES)
aux_source_directory(./util/ DAEMON_SOURCE_FILES)
add_executable(OJdaemon ${DAEMON_SOURCE_FILES})

target_link_libraries(OJdaemon mysqlclient)
target_link_libraries(OJdaemon microhttpd)
target_link_libraries(OJdaemon ${Boost_LIBRARIES})
target_link_libraries(OJdaemon ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(OJdaemon yaml-cpp)
target_link_libraries(OJdaemon seccomp)

install(PROGRAMS ${CMAKE_SOURCE_DIR}/bin/OJdaemon DESTINATION bin)

include("../../ConfigFile.cmake")
CopyConfigFileIfNotExist(
        "${CMAKE_SOURCE_DIR}/sdojconfig.ini"
        "/etc/cwojconfig.ini"
        "/etc/"
)
CopyConfigFileIfNotExist(
        "${CMAKE_SOURCE_DIR}/OJdaemon.service"
        "/lib/systemd/system/OJdaemon.service"
        "/lib/systemd/system/"
)
