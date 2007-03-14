// This file is part of RLVM, a RealLive virtual machine clone.
//
// -----------------------------------------------------------------------
//
// Copyright (C) 2006 El Riot
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
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
//  
// -----------------------------------------------------------------------

#ifndef __SDLSurface_hpp__
#define __SDLSurface_hpp__

#include <boost/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>

#include <vector>

#include "Systems/Base/Surface.hpp"

struct SDL_Surface;
class Texture;
class SDLGraphicsSystem;
class GraphicsObject;

/** 
 * Wrapper around an OpenGL texture; meant to be passed out of the
 * graphics system.
 *
 * Some SDLSurfaces will own their underlying SDL_Surface, for
 * example, anything returned from loadSurfaceFromFile(), while others
 * don't own their surfaces (SDLSurfaces returned by getDC()
 */
class SDLSurface : public Surface, public boost::noncopyable
{
public:
  struct GrpRect {
    int x1, y1, x2, y2;
  };

private:
  /// The SDL_Surface that contains the software version of the bitmap.
  SDL_Surface* m_surface;

  /// The region table
  std::vector<GrpRect> m_regionTable;

  /// The SDLTexture which wraps one or more OpenGL textures
  boost::scoped_ptr<Texture> m_texture;

  /// Whether m_texture represents the contents of m_surface. Blits
  /// from surfaces to surfaces invalidate the target surfaces's
  /// texture.
  bool m_textureIsValid;

  /// A pointer to the graphicsSystem. This item being non-NULL means
  /// that this Surface is the special DC0.
  SDLGraphicsSystem* m_graphicsSystem;

  /** 
   * Makes sure that m_texture is a valid object and that it's
   * updated. This method should be called before doing anything with
   * m_texture.
   */
  void uploadTextureIfNeeded();

public:
  SDLSurface();

  /// Surface that takes ownership of an externally created surface.
  SDLSurface(SDL_Surface* surf, 
             const std::vector<SDLSurface::GrpRect>& region_table);

  /// Surface created with a specified width and height
  SDLSurface(int width, int height);
  ~SDLSurface();

  void dump();

  /// allocate a surface
  void allocate(int width, int height);

  void allocate(int width, int height, SDLGraphicsSystem* in);
  
  /// Deallocate
  void deallocate();

  operator SDL_Surface*()
  {
    return m_surface;
  }

  /// Accessor to the texture for doing advanced rendering by composing
  /// SDLSurface into another part of the SDL_* graphics system
  Texture& texture();

  /// Blits to another surface
  virtual void blitToSurface(Surface& surface, 
                     int srcX, int srcY, int srcWidth, int srcHeight,
                     int destX, int destY, int destWidth, int destHeight,
                             int alpha = 255, bool useSrcAlpha = true);

  virtual void renderToScreen(
                     int srcX, int srcY, int srcWidth, int srcHeight,
                     int destX, int destY, int destWidth, int destHeight,
                     int alpha = 255);

  virtual void renderToScreen(
                     int srcX, int srcY, int srcWidth, int srcHeight,
                     int destX, int destY, int destWidth, int destHeight,
                     const int opacity[4]);

  virtual void rawRenderQuad(const int srcCoords[8], 
                             const int destCoords[8],
                             const int opacity[4]);

  // Used internally; not exposed to the general graphics system
  void renderToScreenAsObject(const GraphicsObject& rp);

  /// Called after each change to m_surface. Marks the texture as
  /// invalid and notifies SDLGraphicsSystem when appropriate.
  void markWrittenTo();

  /// Returns pattern information.
  const GrpRect& getPattern(int pattNo) const;

  // -----------------------------------------------------------------------

  int width() const;
  int height() const;

  virtual void fill(int r, int g, int b, int alpha);
  virtual void fill(int r, int g, int b, int alpha, int x, int y, 
                    int width, int height);

  SDL_Surface* surface() { return m_surface; }

  virtual Surface* clone() const;
};


#endif 