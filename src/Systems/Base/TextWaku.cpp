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

#include "Systems/Base/TextWaku.hpp"

#include <iostream>

#include "Systems/Base/System.hpp"
#include "Systems/Base/TextWakuNormal.hpp"
#include "Systems/Base/TextWakuType4.hpp"
#include "libReallive/gameexe.h"

// static
TextWaku* TextWaku::Create(System& system, TextWindow& window,
                           int setno, int no) {
  GameexeInterpretObject waku(system.gameexe()("WAKU", setno, "TYPE"));
  if (waku.to_int(5) == 4) {
    return new TextWakuType4(system, window, setno, no);
  } else {
    // Old style used everywhere is treated as the default.
    return new TextWakuNormal(system, window, setno, no);
  }
}

TextWaku::~TextWaku() { }
