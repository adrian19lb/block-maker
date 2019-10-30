#ifndef FILEFIXTUREFACTORYMOCK_HPP_INCLUDED
#define FILEFIXTUREFACTORYMOCK_HPP_INCLUDED

#include "../../include/Physic/FixtureFactory/FileFixtureFactory.hpp"

namespace bm::physic::testing {

    class FileFixtureFactoryMock : public FileFixtureFactory {
        MOCK_METHOD0()
    };


}

#endif // FILEFIXTUREFACTORYMOCK_HPP_INCLUDED
