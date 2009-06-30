// -*- Mode: C++; tab-width:2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
// vi:tw=80:et:ts=2:sts=2
//
// -----------------------------------------------------------------------
//
// This file is part of RLVM, a RealLive virtual machine clone.
//
// -----------------------------------------------------------------------
//
// Copyright (C) 2009 Elliot Glaysher
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// -----------------------------------------------------------------------

#include "gtest/gtest.h"

#include "MachineBase/RLMachine.hpp"
#include "Modules/Module_EventLoop.hpp"
#include "TestSystem/TestMachine.hpp"
#include "TestSystem/TestSystem.hpp"
#include "libReallive/archive.h"

#include "testUtils.hpp"

class MediumEventLoopTest : public ::testing::Test {
 protected:
  MediumEventLoopTest()
      : arc(locateTestCase("Module_Str_SEEN/strcpy_0.TXT")),
        system(locateTestCase("Gameexe_data/Gameexe.ini")),
        rlmachine(system, arc) {
    rlmachine.attachModule(new EventLoopModule);
  }

  // Use any old test case; it isn't getting executed
  libReallive::Archive arc;
  TestSystem system;
  TestMachine rlmachine;
};

TEST_F(MediumEventLoopTest, TestSkipMode) {
  rlmachine.setStoreRegister(20);

  rlmachine.exe("SetSkipMode", 0);
  EXPECT_TRUE(system.text().skipMode());
  rlmachine.exe("SkipMode", 0);
  EXPECT_EQ(1, rlmachine.getStoreRegisterValue());

  rlmachine.exe("ClearSkipMode", 0);
  EXPECT_FALSE(system.text().skipMode());
  rlmachine.exe("SkipMode", 0);
  EXPECT_EQ(0, rlmachine.getStoreRegisterValue());
}