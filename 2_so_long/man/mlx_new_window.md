NAME
	   MiniLibX - Managing windows

SYNOPSYS
	   void *
	   mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

	   int
	   mlx_clear_window ( void *mlx_ptr, void *win_ptr );

	   int
	   mlx_destroy_window ( void *mlx_ptr, void *win_ptr );



DESCRIPTION
	   The  mlx_new_window  () function creates a new window on the screen, using the size_x and size_y parameters to determine its size, and title as the text that should be displayed in the window's title bar.  The mlx_ptr parameter is
	   the connection identifier returned by mlx_init () (see the mlx man page).  mlx_new_window () returns a void * window identifier that can be used by other MiniLibX calls.  Note that the MiniLibX can handle an  arbitrary  number  of
	   separate windows.

	   mlx_clear_window () and mlx_destroy_window () respectively clear (in black) and destroy the given window. They both have the same parameters: mlx_ptr is the screen connection identifier, and win_ptr is a window identifier.


RETURN VALUES
	   If mlx_new_window() fails to create a new window (for wathever reason), it will return NULL, otherwise a non-null pointer is returned as a window identifier.  mlx_clear_window and mlx_destroy_window right now return nothing.


SEE ALSO
	   mlx(3), mlx_pixel_put(3), mlx_new_image(3), mlx_loop(3)


AUTHOR
	   Copyright ol@ - 2002-2015 - Olivier Crouzet

NAME
	   MiniLibX - 창 관리

SYNOPSYS
	   void *
	   MLX_NEW_WINDOW ( void *MLX_PTR, int size_x, int size_y, char *title );

	   int
	   MLX_CLEAR_WINDOW ( void *MLX_PTR, void *WIN_PTR );

	   int
	   MLX_DESTROY_WINDOW ( void *MLX_PTR, void *WIN_PTR );



설명
	   mlx_new_window () 함수는 size_x 및 size_y 매개 변수를 사용하여 크기를 결정하고 제목을 창의 제목 표시 줄에 표시 할 텍스트로 사용하여 화면에 새 창을 만듭니다.  mlx_ptr 매개 변수는
	   mlx_init ()이 반환하는 연결 식별자입니다(mlx 매뉴얼 페이지 참조). mlx_new_window ()는 다른 MiniLibX 호출에서 사용할 수 있는 void * 창 식별자를 반환합니다.  MiniLibX는 임의로 많은 수의
	   별도의 창을 처리할 수 있습니다.

	   mlx_clear_window () 및 mlx_destroy_window ()는 각각 주어진 창을 지우고(검은색) 파괴합니다. 두 함수의 매개변수는 모두 동일합니다. mlx_ptr은 화면 연결 식별자이고 win_ptr은 창 식별자입니다.


반환 값
	   mlx_new_window()가 새 창을 만드는 데 실패하면(어떤 이유로든) NULL을 반환하고, 그렇지 않으면 창 식별자로 널이 아닌 포인터를 반환합니다. 현재 mlx_clear_window 및 mlx_destroy_window는 아무것도 반환하지 않습니다.


참조
	   MLX(3), MLX_PIXEL_PUT(3), MLX_NEW_IMAGE(3), MLX_LOOP(3)


AUTHOR
	   저작권 ol@ - 2002-2015 - 올리비에 크루제
