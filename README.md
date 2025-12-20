# Starting December 2025
# Development Log

## Project: Software Rasterizer
**Start Date:** December 11, 2025  
**Current Phase:** Core rasterization algorithms  
**GitHub:** 

---

### Daily Entries

#### December 11, 2025 - Initiation
**Today's Goal:** Environment setup and project planning during limited internet window.

**Progress:**
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

I will finish the rest tomorrow, as it was a late start. Hopefully, I'll discipline myself for at least a month.

# December 16

Wow, I haven't updated this for a few days. I couldn't get the commit to work because I was too unbothered to figure it out.

- Made Bresenham algorithm work with slopes <= 1 & >= -1.
- Negative values work, but it was mostly easy.
- Tomorrow: ???

# December 17

I rewrote bresenham's algorithm, with this time knowing how it works. I never thought algebra would actually help me in coding, yet here we are.

For tomorrow, I will try and make a naive version of it working for all sectors.

# December 19

I forgot to commit yesterday and I'm also one day off every commit. I guess I have to commit earlier than 9pm now. It works for slopes > 1 but not for negative numbers.

# December 20

I made it work for all degrees. Later, I will try and make a rotating square or cube. Since I already know the matrix multiplications, I figure it probably wouldn't be that hard.