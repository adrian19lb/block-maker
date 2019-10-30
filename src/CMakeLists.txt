include(GNUInstallDirs)

include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SOURCES
    ${SRCROOT}/block-maker/Debug/DebugDraw.cpp
    ${SRCROOT}/block-maker/Debug/DebugWorld.cpp
    ${SRCROOT}/block-maker/AttributeTransformer/PhysicCoordTransformer.cpp
    ${SRCROOT}/block-maker/Block.cpp
    ${SRCROOT}/block-maker/Physic/BodySpawner/BlockBodySpawner.cpp
    ${SRCROOT}/block-maker/Physic/BodySpawner/RandomBlockBodySpawner.cpp
    ${SRCROOT}/block-maker/Physic/RandomBlockSpawner.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/BoxBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/HalfPlusBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/IBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/LBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/NBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/OBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/PlusBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/RectShapeFactory.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/TBlock.cpp
    ${SRCROOT}/block-maker/Physic/FixtureFactory/UBlock.cpp
    ${SRCROOT}/block-maker/Render/BodyShape.cpp
    ${SRCROOT}/block-maker/Render/ShapeComposite/ShapeArray.cpp
    ${SRCROOT}/block-maker/Render/ShapeCompositeFactory/ShapeArrayFactory.cpp
    ${SRCROOT}/block-maker/Render/ShapeCreator/RenderableCircleCreator.cpp
    ${SRCROOT}/block-maker/Render/ShapeCreator/RenderablePolygonCreator.cpp
)

blockmaker_add_library(${PROJECT_NAME} SOURCES ${SOURCES})

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(Box2D REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        sfml-window
        sfml-graphics
        sfml-system
        Box2D
        Boost::system
)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/doc ${CMAKE_BINARY_DIR}/doc
)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources
)
