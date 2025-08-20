# 🖥 Computer Graphics Lab


**Name:** Souvik Sanyal  
**ID:** 2011176108  
**Session:** 2019-20  
**Department:** Computer Science and Engineering  

---

## 📋 Experiment List
1. Simulate Hidden Surface Elimination (Visual Surface Detection)  
2. Implement the Cohen-Sutherland Line Clipping Algorithm  
3. Implement the Sutherland-Hodgman Polygon Clipping Algorithm  
4. Create the Bezier Curve  
5. Simulate Two-Dimensional Geometric Transformations:  
   - Translation  
   - Rotation  
   - Scaling  
6. Draw a Line with the Bresenham Line Drawing Algorithm  
7. Draw a Circle with the Bresenham Circle Drawing Algorithm  
8. Draw the Snowflake Pattern with Fractal Geometry  

---

## ⚙️ Development Environment Setup

### 📥 Required Downloads
1. **Code::Blocks IDE**  
   [Official Download](http://www.codeblocks.org/downloads)  
   *(Recommended version: 20.03 with MinGW)*

2. **TDM GCC 32-Bit Compiler**  
   [Download Here](https://jmeubank.github.io/tdm-gcc/)  
   *(Essential for graphics library compatibility)*

3. **Graphics Library**  
   [Download Files](https://drive.google.com/file/d/1z19xxKm2YseQi7QGxqCCdJ-lLfiEGuCm/view)  
   *(Contains graphics.h, winbgim.h, and libbgi.a)*

### 🔧 Installation Steps

#### 1. Extract Graphics Library
- Unzip the downloaded graphics library files to a temporary location

#### 2. Copy Header Files
- Move `graphics.h` → `C:\TDM-GCC-32\include`  
- Move `winbgim.h` → `C:\TDM-GCC-32\include`

#### 3. Copy Library File
- Move `libbgi.a` → `C:\TDM-GCC-32\lib`

#### 4. Configure Code::Blocks
1. Launch Code::Blocks
2. Navigate to **Settings → Compiler → Toolchain Executables**
3. Set **Compiler's installation directory** to:  C:\TDM-GCC-32

#### 5. Configure Linker Settings
1. Go to **Settings → Compiler → Linker Settings**
2. Under **Other linker options**, add:  -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

#### 6. Set Search Directories
1. Go to **Settings → Compiler → Search directories**
2. **Compiler** tab: Add `C:\TDM-GCC-32\include`
3. **Linker** tab: Add `C:\TDM-GCC-32\lib`

---

\
