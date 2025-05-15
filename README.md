
---

## 🎨 Fractol

Welcome to the Fractol project repository! This project is part of the 42 curriculum and focuses on generating and visualizing fractals using the MLX42 graphics library. It provides an interactive experience to explore complex mathematical patterns.

## Features

- **Fractal generation**: Supports rendering of Mandelbrot, Julia, and Burning Ship fractals.
- **Interactive controls**: Allows zooming, panning, and real-time parameter adjustments.
- **Color customization**: Offers various color schemes for visual enhancement.
- **High-performance rendering**: Optimized for smooth and responsive graphics.

## Technologies Used

- **C**: Core programming language for fractal algorithms.
- **MLX42**: Graphics library for window management and rendering.
- **Complex mathematics**: Implements complex number calculations for fractal generation.

## Getting Started

To compile and run the program:

```bash
make
./fractol <fractal_type>
```  
Replace <fractal_type> with mandelbrot, julia, or burningship to render the respective fractal.  
For the Julia fractal, you need to provide two numerical parameters.  
See: https://en.wikipedia.org/wiki/Julia_set  

```bash
./fractol mandelbrot  
./fractol julia -0.7 +0.27015  
./fractol burningship
```

## A few examples


### Mandelbrot
<img width="1000" alt="Screenshot 2024-05-23 at 15 49 46" src="https://github.com/Aerly-Lex/fractol/assets/117720936/6d59d4aa-0623-4841-8c14-098bc9979a3e">

### Julia Set 
Cords: -0.7 +0.27015
<img width="1000" alt="Screenshot 2024-05-23 at 15 46 17" src="https://github.com/Aerly-Lex/fractol/assets/117720936/1f6cf281-1e3d-4263-8d63-672fab377585">

### Burning Ship
<img width="1000" alt="Screenshot 2024-05-23 at 15 48 30" src="https://github.com/Aerly-Lex/fractol/assets/117720936/63eaa9ea-4fc6-41d7-be9e-e1013739f0a0">
