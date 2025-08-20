# Computer-Graphics
## Experiment List
1. Simulate Hidden Surface Elimination or Visual Surface Detection
2. Implement the Cohen-Sutherland Line Clipping algorithm
3. Implement the Sutherland-Hodgman Polygon Clipping algorithm
4. Create the Bezier Curve
5. Simulate two-dimensional geometric Translation, Rotation, and Scaling
6. Draw a line with the Bresenham Line Drawing algorithm
7. Draw a circle with the Bresenham Circle Drawing algorithm
8. Draw the Snowflake Pattern with Fractal Geometry
   
## Setup
Download Codeblocks
Download TDM GCC 32 Bit Compiler from this link
Download Graphics Library: https://drive.google.com/file/d/1z19xxKm2YseQi7QGxqCCdJ-lLfiEGuCm/view
Extract Graphics Library
Copy graphics.h & winbgim.h and paste it in C:\\TDM-GCC-32\\include
Copy libbgi.a & paste it in C:\\TDM-GCC-32\\lib
Now go to CodeBlocks -> Settings -> Compiler
Go to Toolchain executables & change Compiler's installation directory to C:\\TDM-GCC-32
Go to Linker Settigns -> Other linker options & add -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
Go to Search directories → Compiler and add C:\TDM-GCC-32\include
Go to Search directories → Linker and add:C:\TDM-GCC-32\lib
