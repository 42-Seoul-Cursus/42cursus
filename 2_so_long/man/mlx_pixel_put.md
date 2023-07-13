NAME
	   MiniLibX - Drawing inside windows

SYNOPSYS
	   int
	   mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );

	   int
	   mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );



DESCRIPTION
	   The  mlx_pixel_put  () function draws a defined pixel in the window win_ptr using the ( x , y ) coordinates, and the specified color . The origin (0,0) is the upper left corner of the window, the x and y axis respectively pointing
	   right and down. The connection identifier, mlx_ptr , is needed (see the mlx man page).

	   Parameters for mlx_string_put () have the same meaning. Instead of a simple pixel, the specified string will be displayed at ( x , y ).

	   In both functions, it is impossible to display anything outside the specified window, nor display in another window in front of the selected one.


COLOR MANAGEMENT
	   The color parameter has an integer type. The displayed color needs to be encoded in this integer, following a defined scheme. All displayable colors can be split in 3 basic colors: red, green and blue. Three associated values,  in
	   the  0-255  range,  represent  how  much  of each color is mixed up to create the original color. Theses three values must be set inside the integer to display the right color. The three least significant bytes of this integer are
	   filled as shown in the picture below:

			   | 0 | R | G | B |   color integer
			   +---+---+---+---+


	   While filling the integer, make sure you avoid endian problems. Remember that the "blue" byte should always be the least significant one.



SEE ALSO
	   mlx(3), mlx_new_window(3), mlx_new_image(3), mlx_loop(3)



AUTHOR
	   Copyright ol@ - 2002-2015 - Olivier Crouzet

NAME
	   MiniLibX - 창 안에 그리기

SYNOPSYS
	   int
	   mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );

	   int
	   mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );



설명
	   mlx_pixel_put () 함수는 ( x , y ) 좌표와 지정된 색상을 사용하여 win_ptr 창에 정의 된 픽셀을 그립니다 . 원점(0,0)은 창의 왼쪽 상단 모서리이며, x축과 y축은 각각 오른쪽과 아래를 가리킵니다.
	   오른쪽과 아래를 가리킵니다. 연결 식별자 mlx_ptr 이 필요합니다(mlx 매뉴얼 페이지 참조).

	   mlx_string_put ()의 매개변수도 같은 의미를 갖습니다. 단순한 픽셀 대신 지정된 문자열이 ( x , y )에 표시됩니다.

	   두 함수 모두 지정된 창 외부에는 아무것도 표시할 수 없으며 선택한 창 앞에 다른 창에 표시할 수도 없습니다.


색상 관리
	   색상 매개변수에는 정수 유형이 있습니다. 표시되는 색상은 정의된 체계에 따라 이 정수로 인코딩되어야 합니다. 표시 가능한 모든 색상은 빨강, 녹색, 파랑의 세 가지 기본 색상으로 나눌 수 있습니다. 세 가지 연관된 값은
	   범위의 세 가지 관련 값은 원래 색상을 만들기 위해 각 색상이 얼마나 혼합되는지를 나타냅니다. 올바른 색상을 표시하려면 이 세 가지 값을 정수 안에 설정해야 합니다. 이 정수의 최하위 바이트 세 개는 다음과 같습니다.
	   로 채워집니다:

			   | 0 | R | G | B | 색상 정수
			   +---+---+---+---+


	   정수를 채우는 동안 엔디안 문제를 피해야 합니다. "파란색" 바이트는 항상 최하위 바이트여야 한다는 점을 기억하세요.



참조
	   MLX(3), MLX_NEW_WINDOW(3), MLX_NEW_IMAGE(3), MLX_LOOP(3)



AUTHOR
	   저작권 ol@ - 2002-2015 - 올리비에 크루제
