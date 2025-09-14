
#include "fractol.h"


int	main(int argc, char **argv)
{
	t_fractol fractol;

	fractol.type_of_fractal = check_args(argc, argv[1]);
	
	if (!fractol.type_of_fractal)
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		return (1);
	}
		init_window(&fractol, argv);
		draw_fractol(&fractol);
		event_handler(&fractol);
		mlx_loop(fractol.mlx);
	return (0);
}

// ERENIKO KOMANCALEZ NOTLAR: parse'ı adam et yanlış değer girilmesin,
// olması gerekenden fazla veya az argüman girilirse,

// argüman sayısı doğruysa adam gibi number check

// 1 1 girince yine yuvarlak veriyo araştır.