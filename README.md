# VertexTracerGPU
This is open source GPU based raytracer project that allows user to render quite realistically-looking scenes. It supports several light sources (directional, point), supports various materials (opaque, reflective refractive – Fresnel's equation). In addition, it has various antyaliasing methods (removing the jagged edges), and rendering is done using multithreading.

The newest features (may be **unstable**) will be pushed to **develop** branch and **stable** version of the engine will always be pushed to **master** branch. 

## TODOs
- [ ] Rewrite Vertextracer to GPU
- [x] Tonemapping - auto-exposure
- [x] Light intensity calculated from AS
- [ ] Ambient light calculated from AS
- [ ] AS + fog
- [ ] Calculate AS coefficients at fly (for a fog)

### Dependencies' versions
- Assimp 3.2
- GLM 0.9.8.4
- GLFW 3.2.1
- GLEW 2.0.0