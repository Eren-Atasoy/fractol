


int get_gradient_color(double iter, int max_iter)
{
    double t = iter / max_iter; // normalize
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (r << 16) | (g << 8) | b;
}