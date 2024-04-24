int draw_fractal(t_fractal *fractal, char *query, double cx, double cy)
{
 fractal->x = 0;
 fractal->y = 0;
 while (fractal->x < SIZE)
 {
  while (fractal->y < SIZE)
  {
   if (ft_strncmp(query, "mandel", 7) == 0)
    calculate_mandelbrot(fractal);
   else if (ft_strncmp(query, "julia", 6) == 0)
    calculate_julia(fractal, cx, cy);
   else if (ft_strncmp(query, "ship", 5) == 0)
    calculate_burning_ship(fractal);
   else
   {
    ft_putendl_fd("Available fractals: mandel, julia, ship", 1);
    exit_fractal(fractal);
   }
   fractal->y++;
  }
  fractal->x++;
  fractal->y = 0;
 }
 mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
  0);
 return (0);
}

void calculate_mandelbrot(t_fractal *fractal)
{
 int  i;
 double x_temp;

 fractal->name = "mandel";
 i = 0;
 fractal->zx = 0.0;
 fractal->zy = 0.0;
 fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
 fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
 while (++i < fractal->max_iterations)
 {
  x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
   + fractal->cx;
  fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
  fractal->zx = x_temp;
  if (fractal->zx * fractal->zx + fractal->zy
   * fractal->zy >= __DBL_MAX__)
   break ;
 }
 if (i == fractal->max_iterations)
  put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
 else
  put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
    * i));
}