/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef STARK_GFX_OPENGL_S_RENDERED_H
#define STARK_GFX_OPENGL_S_RENDERED_H

#include <engines/stark/formats/biffmesh.h>
#include "common/hash-str.h"
#include "common/str.h"

#include "engines/stark/visual/prop.h"

namespace Graphics {
	class Shader;
}

namespace Stark {

namespace Gfx {

class OpenGLSPropRenderer : public VisualProp {
public:
	OpenGLSPropRenderer();
	virtual ~OpenGLSPropRenderer();

	void render(Gfx::Driver *gfx, const Math::Vector3d position, float direction) override;

protected:
	Graphics::Shader *_shader;

	int32 _faceVBO;
	Common::HashMap<Common::String, uint32> _faceEBO;

	Common::String faceHash(const Formats::BiffMesh::Face *face) const;
	void clearVertices();
	void uploadVertices();
	uint32 createFaceVBO();
	uint32 createFaceEBO(const Formats::BiffMesh::Face *face);
};

} // End of namespace Gfx
} // End of namespace Stark

#endif // STARK_GFX_OPENGL_S_RENDERED_H
