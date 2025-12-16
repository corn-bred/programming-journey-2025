# MIT Journey - Starting December 2025
# MIT CS Development Log

## Project: Software Rasterizer
**Start Date:** December 11, 2025  
**Current Phase:** Core rasterization algorithms  
**GitHub:** 

---

### Daily Entries

#### December 11, 2025 - Initiation
**Today's Goal:** Environment setup and project planning during limited internet window.

**Progress:**
- Created Github repo offline
- Focusing on Bresenham's Line Algorithm 
(https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) 
and how it works

**Technical Decisions:**
1. Implementing from scratch in C++ (no graphics libraries)
2. ASCII output first → OpenGL comparison later
3. Starting with cube (8 vertices, 12 edges)

**Blockers:** 
- Internet access limited to 20-minute windows
- Need to find efficient offline C++ documentation

**Insights:**
- The perspective projection formula (x/z, y/z) assumes camera at origin looking along z-axis
- Bresenham's algorithm uses integer arithmetic only - important for optimization

**Code Snippet:**
```cpp
// Projection function stub
Point2D projectPoint(Point3D p, float focal_length = 1.0f) {
    return { p.x / (p.z + focal_length), 
             p.y / (p.z + focal_length) };
}
```

I will finish the rest tomorrow, as it was a late start. Hopefully, I'll discipline myself for at least a month.