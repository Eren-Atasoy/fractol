


int get_gradient_color(double iter, int max_iter)
{
    double t = iter / max_iter; // normalize
    int r = (int)(12 * (1 - t) * t * t * t * 255);
    int g = (int)(12 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(6 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (b << 16) | (r << 8) | g;
}