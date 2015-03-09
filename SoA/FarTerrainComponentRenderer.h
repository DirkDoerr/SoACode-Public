///
/// FarTerrainComponentRenderer.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 22 Feb 2015
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Renderer for far terrain patches
///

#pragma once

#ifndef FarTerrainComponentRenderer_h__
#define FarTerrainComponentRenderer_h__

#include <Vorb/VorbPreDecl.inl>

struct AxisRotationComponent;
struct NamePositionComponent;
struct SpaceLightComponent;
struct SphericalTerrainComponent;
struct FarTerrainComponent;
class Camera;

DECL_VG(class GLProgram);

class FarTerrainComponentRenderer {
public:
    ~FarTerrainComponentRenderer();
    void draw(const FarTerrainComponent& cmp,
              const Camera* camera,
              const f64v3& lightDir,
              const SpaceLightComponent* spComponent,
              const AxisRotationComponent* arComponent);

private:
    void buildShaders();

    vg::GLProgram* m_farTerrainProgram = nullptr;
    vg::GLProgram* m_farWaterProgram = nullptr;
};

#endif // FarTerrainComponentRenderer_h__
