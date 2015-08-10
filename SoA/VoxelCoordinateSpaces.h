///
/// VoxelCoordinateSpaces.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 27 Jan 2015
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Contains the voxel coordinate space definitions.
///

#pragma once

#ifndef VoxelCoordinateSpaces_h__
#define VoxelCoordinateSpaces_h__

enum WorldCubeFace {
    FACE_TOP = 0, FACE_LEFT, FACE_RIGHT,
    FACE_FRONT, FACE_BACK, FACE_BOTTOM,
    FACE_NONE
};

struct ChunkPosition2D {
    operator i32v2&() { return pos; }
    operator const i32v2&() const { return pos; }
    union {
        UNIONIZE(i32v2 pos;);
        UNIONIZE(i32 x;
                 i32 z);
    };
    WorldCubeFace face = FACE_TOP;
};

struct ChunkPosition3D {
    operator i32v2() const { return i32v2(pos.x, pos.z); }
    operator i32v3&() { return pos; }
    operator const i32v3&() const { return pos; }
    union {
        UNIONIZE(i32v3 pos;);
        UNIONIZE(i32 x;
                 i32 y;
                 i32 z);
    };
    WorldCubeFace face = FACE_TOP;
};

struct VoxelPosition2D {
    operator f64v2&() { return pos; }
    operator const f64v2&() const { return pos; }
    union {
        UNIONIZE(f64v2 pos;);
        UNIONIZE(f64 x;
                 f64 z);
    };
    WorldCubeFace face = FACE_TOP;
};

struct VoxelPosition3D {
    operator f64v2() const { return f64v2(pos.x, pos.z); }
    operator f64v3&() { return pos; }
    operator const f64v3&() const { return pos; }
    union {
        UNIONIZE(f64v3 pos);
        UNIONIZE(f64 x;
                 f64 y;
                 f64 z);
    };
    WorldCubeFace face = FACE_TOP;
};

#endif // VoxelCoordinateSpaces_h__
