add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/googletest" "third_party/googletest")

mark_as_advanced(
    BUILD_GMOCK BUILD_SHARED_LIBS
    gmock_build_tests 
)

#Add IDEs support folder clear
set_target_properties(gmock PROPERTIES FOLDER third_party)
set_target_properties(gmock_main PROPERTIES FOLDER third_party)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

macro(package_add_test TESTNAME TESTED_LIB)
    add_executable(${TESTNAME} ./maintest ${ARGN})
    target_compile_definitions(${TESTNAME} PRIVATE BOOST_TEST_DYN_LINK)
    target_include_directories(${TESTNAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_include_directories(${TESTNAME} PRIVATE ${PROJECT_SOURCE_DIR}/tests)
    target_link_libraries(${TESTNAME} PRIVATE
        gmock pthread Boost::unit_test_framework ${TESTED_LIB}
    )
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(LoaderTest ${PROJECT_NAME}
    ./Loader/BufferTest.cpp
    ./Loader/XmlLoaderTest.cpp
)

package_add_test(PhysicTest ${PROJECT_NAME}
    ./Physic/RectShapeFactoryTest.cpp
)

package_add_test(RenderTest ${PROJECT_NAME}
    ./Render/RenderableCircleCreatorTest.cpp
    ./Render/RenderablePolygonCreatorTest.cpp
    ./Render/ShapeArrayTest.cpp
)

package_add_test(ResourceBinderTest ${PROJECT_NAME}
    ./ResourceBinder/FileResourceBinderTest.cpp
)

package_add_test(IntegrationTest ${PROJECT_NAME}
    ./LibIntegrationTest.cpp
)
